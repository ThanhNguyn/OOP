#include <cmath>
class Shape {
public:
    virtual double area() const = 0; 
    virtual ~Shape() = default; 
};
class Circle : public Shape {
private:
    int r;
public:
    explicit Circle(int radius) : r(radius) {}
    double area() const override {
        const double PI = acos(-1.0); 
        return PI * r * r;
    }
};
class Rectangle : public Shape {
private:
    int w, h;
public:
    Rectangle(int width, int height) : w(width), h(height) {}
    double area() const override {
        return static_cast<double>(w * h);
    }
};