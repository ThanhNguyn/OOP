#include <iostream>
#include <ctime> // time_t, time tính từ mốc 01/01/1970 (UTC/GMT)
using namespace std;

int main() {
    time_t now = time(0);// tgian hiện tại tính từ mốc, đơn vị sec
    long long total = now;

    long long days = total / (24*60*60); // số ngày tính từ mốc
    long long remain = total % (24*60*60); // số giây còn lại sau khi trừ đi số ngày

    int hours = remain / (60*60); // số giờ còn lại sau khi trừ đi số ngày
    remain %= (60*60); // số giây còn lại sau khi trừ đi số ngày và số giờ

    int minutes = remain / 60; // số phút còn lại sau khi trừ đi số ngày, số giờ
    int seconds = remain % 60; // số giây còn lại sau khi trừ đi số ngày, số giờ, số phút

    cout << "Seconds since epoch: " << total << "\n";
    cout << "Days since epoch   : " << days << "\n";
    cout << "Time of day (GMT)  : "
         << hours << "h " << minutes << "m " << seconds << "s\n";

    return 0;
}