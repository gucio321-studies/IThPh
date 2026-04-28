#include "solver.h"
#include <math.h>

Vector2D sin(const Vector2D v) {
    return Vector2D(sin(v.x), sin(v.y));
}

Vector2D Vector2D::operator*(const float& scalar) {
        return Vector2D(scalar * x, scalar * y);
}

Vector2D Vector2D::operator/(const float& scalar) {
        return Vector2D(x / scalar, y / scalar);
}
