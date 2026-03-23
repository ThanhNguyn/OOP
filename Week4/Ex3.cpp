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
            cout << "[(" << d1.x << ", " << d1.y << ") - (" << d2.x << ", " << d2.y << ")]";

        }
        double calcLength(){
            return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
        }
};
int main(){
    int n;
    LineSegment list[n];
    cout << "Enter the number of line segments: ";
    cin >> n;
    cout << "Enter "<< n << " line segments (x1 y1 x2 y2):\n";
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        list[i] = LineSegment(x1, y1, x2, y2);
    };
    cout << "Line segments and their lengths:\n";
    double minLength = list[0].calcLength();
    int minIndex = 0;
    for(int i = 1; i < 5; i++){
        double currentLength = list[i].calcLength();
        if(currentLength < minLength){
            minLength = currentLength;
            minIndex = i;
        }
    }
    cout << "\nShortest line segment(s) with length " << minLength << ":" << endl;
    for(int i = 0; i < 5; i++){
        if(list[i].calcLength() == minLength){
            cout << "- ";
            list[i].display();
            cout << endl;
        }
    }
    return 0;
}