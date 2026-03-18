#include <iostream>
#include <string>
using namespace std;

class SuperMan{
public:
    string name;
    string weapon;
    string colour;
    SuperMan(string n, string w, string c){
        name = n;
        weapon = w;
        colour = c;
    }
    void printInfo(){
        cout << "Name: " << name << "\n";
        cout << "Weapon: " << weapon << "\n";
        cout << "Color: " << colour << "\n";
        cout << "-------------------------\n";
    }
};
    int main(){
        SuperMan sieu_nhan_A("A", "Sword", "Red");
        SuperMan sieu_Nhan_B("B", "Shield", "Blue");
        cout << "SuperMan A:\n";
        sieu_nhan_A.printInfo();
        cout << "SuperMan B:\n";
        sieu_Nhan_B.printInfo(); 
        return 0;
    }