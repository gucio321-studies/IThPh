#include <stdio.h>
#include <stdlib.h>

// --- 1D Functions ---

/*
 * Calculates the next 1D coordinate 
 */

float next_coordinate_1D(float coord, float vel, float dt){
  /* Calculating new coordinates */
  float ratio = dt*vel;
  return coord += ratio;
}

float next_velocity_1D(float coord, float vel, float dt){
  /* Calculating new velocities*/
        /*
  if (coord > 1.5) return vel - 1e-1*dt;
  else             return vel + 1e-1*dt;
  */
        auto k = 1;
        return vel - dt * k * coord;
}

// --- 2D Structures and Functions ---

typedef struct {
  float x;
  float y;
} Vector2D;

/* Exemplary helper */
float dxdt(float x, float dt){
  return -dt*x;
}

void next_coordinate_2D(Vector2D* coord, Vector2D* vel, Vector2D* new_coord, float dt) {
  /* Calculating new coordinates in 2D
   * INPUT: `coord`, `vel`, `dt`
   * OUTPUT saved in `new_coord`
   */
  if (!coord || !vel || !new_coord) return; // Safety check for null pointers

  /* Exemplary use of the helper function */
  new_coord->x = coord->x + dxdt(coord->x,dt);
  new_coord->y = coord->y + dxdt(coord->y,dt);
}

void next_velocity_2D(Vector2D* coord, Vector2D* vel, Vector2D* new_vel, float dt) {
  /* Calculating new velocities in 2D
   * INPUT: `coord`, `vel`, `dt`
   * OUTPUT saved in `new_coord`
   */
  if (!coord || !vel || !new_vel) return; // Safety check for null pointers
}

