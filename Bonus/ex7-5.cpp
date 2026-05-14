#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if (cin >> n){
        int even_count=0;
        int odd_count=0;
        for(int i=0; i<n; i++){
            int num;
            if (cin >> num){
                if (num % 2 == 0){
                    even_count++;
                } else {
                    odd_count++;
                }
            }
        }
        cout << "Chẵn: " << even_count << ", " << "Lẻ: " << odd_count << endl;
    }
    return 0;
}