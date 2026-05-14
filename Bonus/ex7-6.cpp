#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    if (cin >> n){
        ll max_value = 0;
        cin >> max_value;
        for (int i = 1; i < n; i++){
            ll temp;
            cin >> temp;
            if (temp > max_value){
                max_value = temp;
            }
        }
        cout << max_value << endl;
    }
    return 0;
}