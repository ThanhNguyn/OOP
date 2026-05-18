#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(1) {}
    Point(int x, int y) : x(x), y(y) {}
    void read() { cin >> x >> y; }
    void print() { cout << "(" << x << ", " << y << ")\n"; }
    void move(int dx, int dy) { x += dx; y += dy; }
    int getX() const { return x; }
    int getY() const { return y; }
    double distance() const { return sqrt((double)x*x + (double)y*y); }
    double distance(Point P) const {
        int dx = x - P.x, dy = y - P.y;
        return sqrt((double)dx*dx + (double)dy*dy);
    }
};

class LineSegment {
private:
    Point d1, d2;
public:
    LineSegment() : d1(8, 5), d2(1, 0) {}
    LineSegment(Point d1, Point d2) : d1(d1), d2(d2) {}
    LineSegment(int x1, int y1, int x2, int y2) : d1(x1, y1), d2(x2, y2) {}
    LineSegment(const LineSegment& S) : d1(S.d1), d2(S.d2) {}

    void read() {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d1 = Point(x1, y1);
        d2 = Point(x2, y2);
    }

    void print() {
        cout << "[(" << d1.getX() << ", " << d1.getY()
             << "); (" << d2.getX() << ", " << d2.getY() << ")]\n";
    }

    void move(int dx, int dy) {
        d1.move(dx, dy);
        d2.move(dx, dy);
    }

    double length() { return d1.distance(d2); }

    int angle() {
        int dx = d2.getX() - d1.getX();
        int dy = d2.getY() - d1.getY();
        double deg = atan2((double)dy, (double)dx) * 180.0 / M_PI;
        int result = (int)round(deg);
        return ((result % 360) + 360) % 360;
    }
};

class LineSegmentTest {
public:
    void testCase() {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        LineSegment ls1(x1, y1, x2, y2);
        ls1.print();

        double len = ls1.length();
        if (len == (int)len)
            cout << fixed << setprecision(1) << len << "\n";
        else
            cout << len << "\n";

        cout << ls1.angle() << "\n";

        LineSegment ls2(ls1);
        ls1.move(1, 1);
        ls1.print();
        ls2.print();
    }
};