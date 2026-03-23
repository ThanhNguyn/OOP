#include <bits/stdc++.h>
using namespace std;
class NhanVien{
    private:
        string name;
        double salary;
        double basicSalary;
        double salaryCoefficient;
    public:
        double MAX_SALARY;
        NhanVien(string name = "", double basicSalary = 0.0, double salaryCoefficient = 1.0, double MAX_SALARY = 0.0 ){ // constructor
            this->name = name;
            this->basicSalary = basicSalary;
            this->salaryCoefficient = salaryCoefficient;
            this->MAX_SALARY = MAX_SALARY;
        }
        string getName(){return name;}
        void setName(string name){this->name = name;}
        string getBasicSalary(){return to_string(basicSalary);}
        void setBasicSalary(double basicSalary){this->basicSalary = basicSalary;}
        string getSalaryCoefficient(){return to_string(salaryCoefficient);}
        void setSalaryCoefficient(double salaryCoefficient){this->salaryCoefficient = salaryCoefficient;}
        double salaryCalc(){return basicSalary * salaryCoefficient;}
        void printInfo(){
            cout << "===========THONG TIN NHAN VIEN===========\n";
            cout << "Ten nhan vien: " << name << "\n";
            cout << "Luong co ban: " << basicSalary << "\n";
            cout << "He so luong: " << salaryCoefficient << "\n";
            cout << "Luong toi da: " << MAX_SALARY << "\n";
            cout << "Luong: " << salaryCalc() << "\n";
        }
        bool increaseSalary(double increaseCoefficient){
            double newSalaryCofficient = salaryCoefficient + increaseCoefficient;
            double newSalary = basicSalary * newSalaryCofficient;
            if(newSalary > MAX_SALARY){
                cout << "Khong the tang luong, Luong moi: " << newSalary << " vuot qua muc luong toi da cho phep" << MAX_SALARY << "\n";
                return false;
            } else {
                salaryCoefficient = newSalaryCofficient;
                cout << "Tang luong thanh cong. Luong moi: " << newSalary << "\n";
                return true;
            }
        }
};
int main(){
    return 0;
}