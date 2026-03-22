#include <iostream>
#include <cmath>

using namespace std;


class Point {
public:
    double x, y;
    
    // Constructor
    Point(double x = 0, double y = 0){
    this->x = x;
    this->y = y;
    }
};


class Rectangle {
public:
    Point corner; // Góc dưới cùng bên trái
    double width, height;
    
    // Constructor
   Rectangle(Point c, double w, double h) {
    corner = c;
    width = w;
    height = h;
   }
};


class Circle {
public:
    Point center;
    double radius;
    
    // Constructor
    Circle(Point c, double r){
     center = c;
     radius = r;
    }
};

// Hàm point_in_circle (Chỉ giữ lại 1 bản duy nhất)
bool point_in_circle(const Circle& c, const Point& p) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    double distance = sqrt(dx * dx + dy * dy);
    
    // Trả về true nếu khoảng cách <= bán kính
    return distance <= c.radius;
}

bool rect_in_circle(const Circle& c, const Rectangle& r) {
    Point bottom_left = r.corner;
    Point bottom_right(r.corner.x + r.width, r.corner.y);
    Point top_left(r.corner.x, r.corner.y + r.height);
    Point top_right(r.corner.x + r.width, r.corner.y + r.height);

    // Cả 4 góc phải nằm trong hình tròn
    return point_in_circle(c, bottom_left) &&
           point_in_circle(c, bottom_right) &&
           point_in_circle(c, top_left) &&
           point_in_circle(c, top_right);
}

bool rect_circle_overlap(const Circle& c, const Rectangle& r) {
    Point bottom_left = r.corner;
    Point bottom_right(r.corner.x + r.width, r.corner.y);
    Point top_left(r.corner.x, r.corner.y + r.height);
    Point top_right(r.corner.x + r.width, r.corner.y + r.height);


    return point_in_circle(c, bottom_left) ||
           point_in_circle(c, bottom_right) ||
           point_in_circle(c, top_left) ||
           point_in_circle(c, top_right);
}

int main() {

    Point center(150, 100);
    Circle my_circle(center, 75);


    Point rect_corner(100, 50);
    Rectangle my_rect(rect_corner, 40, 30);

    if (rect_in_circle(my_circle, my_rect)) {
        cout << "Hinh chu nhat nam tron trong hinh tron!" << endl;
    } else {
        cout << "Hinh chu nhat KHONG nam tron trong hinh tron." << endl;
    }

    return 0;
}