# === IMPORTS ===
# Standard library imports
import itertools as it

# Numpy (https://numpy.org/)
# and ctypes (https://docs.python.org/3/library/ctypes.html)
import numpy as np

# Matplotlib (https://matplotlib.org/) 
# imports for plotting and animation
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.animation as animation


class Animation2D:
    def __init__(self,qs,vector_factory=None, c_arr=None,
                 next_step=None,positions=None, velocities=None,
                 dt=0.01,NUMBER_OF_PARTICLES=1, NQ=0, pos_calc=None):
        self.data = np.zeros((NUMBER_OF_PARTICLES, 2))
        self.pos_calc = pos_calc

        self.qs = qs
        self.dqs = np.zeros((NUMBER_OF_PARTICLES, NQ), dtype=np.float32)
        self.NQ = NQ
        self.vector = vector_factory
        self.c_arr = c_arr
        self.next_step = next_step
        self.set_positions(positions)
        self.set_velocities(velocities)
        self.colours = it.cycle(mcolors.TABLEAU_COLORS)
        self.dt = dt
        self.NUMBER_OF_PARTICLES = NUMBER_OF_PARTICLES

    def set_positions(self, positions):
        self.positions = positions
        for i, pos in enumerate(self.positions):
            pos(self.data, i)  # Initialize 'self.data' with starting positions

    def set_velocities(self, velocities):
        self.velocities = velocities

    def create_canvas(self,**kwargs):
        """
        This function sets up the Matplotlib figure and axes for the animation.
        It initializes the plot elements that will be updated in each frame.
        """
        self.fig, self.ax = plt.subplots()
        self.ax.set_aspect('equal', adjustable='box')  # Ensure x and y axes have the same scale
        # Set plot limits and labels
        if 'xlim' not in kwargs:
            kwargs['xlim']=[-2.1, 2.1]
        if 'ylim' not in kwargs:
            kwargs['ylim']=[-2.1, 2.1]
        if 'xlabel' not in kwargs:
            kwargs['xlabel']='x'
        if 'ylabel' not in kwargs:
            kwargs['ylabel']='y'
        self.ax.set(**kwargs)
        if self.NUMBER_OF_PARTICLES > 1:
            # Append first point to close the loop
            self.lines = self.ax.plot(np.append(self.data[:, 0], self.data[0, 0]),
                                      np.append(self.data[:, 1], self.data[0, 1]), lw=1)[0]
        # 'points' is a scatter plot of the particles themselves
        self.points = self.ax.scatter(self.data[:, 0], self.data[:, 1],
                      c=[clr for clr, _ in zip(self.colours, range(self.NUMBER_OF_PARTICLES))], s=57)

    def update_frame(self, frame):
        """
        This function is called for each frame of the animation.
        It calculates the new state of the simulation and updates the plot.
        """
        global positions,velocities

        t = frame

        # Create empty Vector2D objects to hold the C function results
        new_qs = np.zeros((self.NUMBER_OF_PARTICLES, self.NQ), dtype=np.float32)
        new_dqs = np.zeros((self.NUMBER_OF_PARTICLES, self.NQ), dtype=np.float32)

        # 1. Calculate the new positions and velocities
        self.next_step(self.qs, self.dqs, # q and dq
                       new_qs, new_dqs, # newq and newdq
                       t, self.dt, self.NUMBER_OF_PARTICLES, self.NQ)

        for i,new_q in enumerate(new_qs):
            # 2. Update the master Python lists with the new state
            self.qs[i] = new_q
            self.dqs[i] = new_dqs[i]
            result = self.pos_calc.calc(self.qs[i], self.dqs[i])
            self.positions[i] = self.vector(x=result[0], y=result[1])

            # 3. Update the NumPy plotting array
            self.positions[i](self.data, i)

        # --- Update Matplotlib elements ---
        # Update the positions of the scattered points
        self.points.set_offsets(self.data)

        # Update the connecting lines (if they exist)
        if self.NUMBER_OF_PARTICLES > 1:
            self.lines.set_xdata(np.append(self.data[:, 0], self.data[0, 0]))
            self.lines.set_ydata(np.append(self.data[:, 1], self.data[0, 1]))

    def run_animation(self,frames=60,interval=30):
        self.ani = animation.FuncAnimation(fig=self.fig, func=self.update_frame,
                                           frames=frames , interval=interval)
        plt.show()

