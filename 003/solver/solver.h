#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct Vector2D {
	float x;
	float y;

        Vector2D(float x_, float y_) : x(x_), y(y_) {}
        Vector2D operator*(const float& scalar);
        Vector2D operator/(const float& scalar);
};

void dfdx(Vector2D*, Vector2D*, Vector2D*, Vector2D*, float, size_t);
Vector2D operator*(float, Vector2D);

#ifdef __cplusplus
}
#endif // __cplusplus

Vector2D sin(Vector2D);
