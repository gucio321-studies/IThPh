#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct {
	float x;
	float y;
} Vector2D;

void dfdx(float*, float*, float*, float*, float, size_t);
void next_2D(Vector2D* coord, Vector2D* vel, Vector2D* new_coord, Vector2D* new_vel,float t, float dt, size_t N);
void next_1D(float* q, float* dq, float* new_q, float* new_dq,float t, float dt, size_t N);

#ifdef __cplusplus
}
#endif // __cplusplus
