#include <bits/stdc++.h>
using namespace std;

class SuperMan{
    private:
        string name;
        string weapon;
        string colour;
    public:
    SuperMan(){}   
    SuperMan(string n, string w, string c){
            name = n;
            weapon = w;
            colour = c;
        }
        string getName(){return name;}
        string getWeapon(){return weapon;}
        string getColour(){return colour;}
        void inputInfo(){
            cout << "Nhap ten sieu nhan: ";
            getline(cin >> ws, name);
            cout << "Nhap vu khi cua sieu nhan: ";
            getline(cin >> ws, weapon);
            cout << "Nhap mau sac cua sieu nhan: ";
            getline(cin >> ws, colour);
            cout << "-------------------------\n";
        }
        void printInfo() const{
            cout << "Name: " << name << "\n";
            cout << "Weapon: " << weapon << "\n";
            cout << "Color: " << colour << "\n";
            cout << "-------------------------\n";
        }
};
    int main(){
    list<SuperMan> superman;
    cout << "==============CHUONG TRINH QUAN LI SIEU NHAN==============\n";
    do{
        string choice;
        cout << "1. Them sieu nhan\n";
        cout << "2. Hien thi thong tin sieu nhan\n";
        cout << "3. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        if(choice == "1"){
            SuperMan new_superman("", "", "");
            new_superman.inputInfo();
            superman.push_back(new_superman);
        }
        else if(choice == "2"){
            cout << "Danh sach sieu nhan:\n";
            for(const auto& sm : superman){
                sm.printInfo();
            }
        }
        else if(choice == "3"){
            cout << "Thoat chuong trinh.\n";
            break;
        }
        else{
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    }
    while (true);
    return 0;
}