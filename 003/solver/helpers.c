#include "solver.hpp"
#include <math.h>

Vector2D sin(const Vector2D v) {
    return Vector2D{sin(v.x), sin(v.y)};
}

Vector2D operator*(const Vector2D& self, const float& scalar) {
        return Vector2D{scalar * self.x, scalar * self.y};
}

Vector2D operator*(const float& scalar, const Vector2D& self) {
        return self * scalar;
}

Vector2D operator/(const Vector2D& self, const float& scalar) {
        return Vector2D{self.x / scalar, self.y / scalar};
}

Vector2D operator-(const Vector2D& src, const Vector2D& other) {
        return Vector2D{src.x - other.x, src.y - other.y};
}

Vector2D operator-(const Vector2D& src, const float& other) {
        return Vector2D{src.x - other, src.y - other};
}

Vector2D operator-(const float& src, const Vector2D& other) {
        return Vector2D{src - other.x, src - other.y};
}

Vector2D operator+(const Vector2D& src, const float& other) {
        return Vector2D{src.x + other, src.y + other};
}

Vector2D operator+(const float& src, const Vector2D& other) {
        return other + src;
}
