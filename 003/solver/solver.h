#pragma once

struct Vector2D {
	float x;
	float y;

        Vector2D operator*(const float& scalar);
        Vector2D operator/(const float& scalar);
};

void dfdx(Vector2D*, Vector2D*, Vector2D*, Vector2D*, float, size_t);
Vector2D sin(Vector2D);
Vector2D operator*(float, Vector2D);
