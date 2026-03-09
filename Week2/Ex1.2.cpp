#include <iostream>
#include <iomanip> //setprecision
using namespace std;

int main() {
    int minutes = 42, seconds = 42; // thời gian chạy 42 phút 42 giây
    double km = 10.0; // quãng đường chạy 10 km
    double km_per_mile = 1.61; // 1 mile = 1.61 km

    int total_seconds = minutes * 60 + seconds;      // câu 1
    double miles = km / km_per_mile;                 // câu 2
    double pace_seconds = total_seconds / miles;     // tổng thời gian trên mỗi mile
    int pace_min = (int)(pace_seconds / 60); // đổi dây sang phút, ép kiểu int 
    double pace_sec = pace_seconds - pace_min * 60; // tổng thời gian còn lại trên mỗi mile
    double speed_mph = miles / (total_seconds / 3600.0); // miles / (giờ) = miles / (giây / 3600)

    cout << "1) Seconds in 42m42s: " << total_seconds << " s\n";

    cout << fixed << setprecision(5); // 5 chữ số sau dấu phẩy
    cout << "2) Miles in 10 km: " << miles << " miles\n";

    cout << setprecision(2);
    cout << "3) Average pace: " << pace_min << " min " << pace_sec << " sec per mile\n";
    cout << "   Average speed: " << speed_mph << " mph\n";

    return 0;
}
