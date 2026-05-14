#include <iostream>
using namespace std;
int main() {
    long long n; 
    cin >> n;

    if (n < 2) {
        cout << "not prime" << endl;
        return 0;
    }
        bool is_prime = true; 
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) { 
            is_prime = false;
            break;
        }
    }
    if (is_prime == true) {
        cout << "prime" << endl;
    } else {
        cout << "not prime" << endl;
    }
    return 0;
}