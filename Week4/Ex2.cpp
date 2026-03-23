#include <bits/stdc++.h>
using namespace std;
class Point{
    public:
        int x, y;
        Point(int x = 0 , int y = 0) : x(x), y(y) {}
};
class LineSegment{
    private:
        Point d1, d2;
    public:
        LineSegment(){
            d1 = Point(8, 5);
            d2 = Point(1, 0);
        }
        LineSegment(Point p1,Point p2){
            d1 = p1;
            d2 = p2;
        }
        LineSegment(int x1, int y1, int x2, int y2){
            d1 = Point(x1, y1);
            d2 = Point(x2, y2);
        }
        LineSegment(const LineSegment& s){
            d1 = s.d1;
            d2 = s.d2;
        }
        void display(){
            cout << "Diem dau: (" << d1.x << ", " << d1.y << ")\n";
            cout << "Diem cuoi: (" << d2.x << ", " << d2.y << ")\n";

        }
};
int main(){
    cout << "Ham mac dinh:\n";
    LineSegment l1;
    l1.display(); // default constructor
    cout << "Ham co 2 tham so:\n";
    Point pA(2, 3), pB(4, 5);
    LineSegment l2(pA, pB); // constructor with 2 Point parameters
    l2.display();
    cout << "Ham co 4 tham so:\n";
    LineSegment l3(6, 7, 8, 9); // constructor with 4 parameters
    l3.display();
    cout << "Ham sao chep:\n";
    LineSegment l4(l3); // copy constructor
    l4.display();
    return 0;
}