# Usage

- install requirements: `python3 -m virtualenv venv && source venv/bin/activate && pip install -r requirements.txt`
- update lagrangian.json (see below)
- run `./particles.py N`, where N is a number of particles to simulate.

# Lagrangian json

The lagrangian is stored in a json file. In my implementation, Lagrangian is an abstract object which depends **only** on `q`, `T` and `V`. The `animation`
section is used for visualization.

- `q` - a list of generalized coordinates. Each of them is a function of time `t`.
- `V` - potential energy, a function of `q`, `q_dot` and constrants
- `T` - kinetic energy, a function of `q`, `q_dot` and constrants
- `constants` - a list of constants used in the Lagrangian.
- `equations` - a list of additional equations (e.g. for $v^2$)
- `animation` - a way to map generalized coordinates to Cartesian (x,y) coordinates for visualization. It is a list of objects with `x` and `y` fields, which are functions of `q`.
