#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(1) {}
    Point(int x, int y) : x(x), y(y) {}

    void read() { cin >> x >> y; }
    void print() { cout << "(" << x << ", " << y << ")"; }
    void move(int dx, int dy) { x += dx; y += dy; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setXY(int x, int y) { this->x = x; this->y = y; }

    double distance() const { return sqrt((double)x*x + (double)y*y); }
    double distance(Point P) const {
        int dx = x - P.x, dy = y - P.y;
        return sqrt((double)dx*dx + (double)dy*dy);
    }
};

class ColorPoint : public Point {
private:
    string color;
public:
    ColorPoint() : Point(), color("xanh") {}
    ColorPoint(int x, int y, string color) : Point(x, y), color(color) {}
    ColorPoint(const ColorPoint& cp) : Point(cp), color(cp.color) {}

    void read() {
        Point::read();
        cin >> color;
    }

    void print() {
        cout << "(" << getX() << ", " << getY() << "): " << color << "\n";
    }

    void setColor(string color) { this->color = color; }
};