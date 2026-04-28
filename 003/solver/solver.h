#pragma once

typedef struct {
	float x;
	float y;
} Vector2D;

void dfdx(Vector2D*, Vector2D*, Vector2D*, Vector2D*, float, size_t);
