#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long res = 1;
    while (n > 0) {
        res = res * n; 
        n--;    
    }
    cout << res << "\n";
    return 0;
}