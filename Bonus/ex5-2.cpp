#include <iostream>
class Vector2D {
public:
    int x, y;
    Vector2D(int x = 0, int y = 0) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(this->x - other.x, this->y - other.y);
    }
    Vector2D operator-() const {
        return Vector2D(-this->x, -this->y);
    }
    bool operator==(const Vector2D& other) const {
        return (this->x == other.x && this->y == other.y);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};