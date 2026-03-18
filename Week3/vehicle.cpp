#include <string>
using namespace std;
class Vehicle{
    private:
        string brand;
        string size;
        string colour;
        double price;
    public:
        Vehicle(){}
        void accelerate(){}
        void brake(){}
        void crash(){}
};
int main(){
    Vehicle myVehicle;
    return 0;
}