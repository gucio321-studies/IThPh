#pragma once
#include "solver.h"

Vector2D operator*(const Vector2D& src, const float& scalar);
Vector2D operator*(const float& scalar, const Vector2D& vector);
Vector2D operator/(const Vector2D& src, const float& scalar);
Vector2D operator-(const Vector2D& src, const Vector2D& other);
Vector2D operator-(const Vector2D& src, const float& other);
Vector2D operator-(const float& src, const Vector2D& other);
Vector2D operator-(const Vector2D& src);
Vector2D operator+(const Vector2D& src, const float& other);
Vector2D operator+(const float& src, const Vector2D& other);
Vector2D operator+(const Vector2D& src, const Vector2D& other);

Vector2D sin(Vector2D);
