#include <string>
#include <iostream>
class Dog{
    private:
        std::string name;
        std::string colour;
        std::string breed;
        std::string emotion;
    public:
        Dog(std::string n, std::string c, std::string b, std::string e) {
        name = n;
        colour = c;
        breed = b;
        emotion = e;
    }
        void bark(){
            emotion = "Woof! Woof!";
            std::cout << emotion << std::endl;
        }
        void wagTail(){
            emotion = "Wagging tail!";
            std::cout << emotion << std::endl;  
        }
        void eat(){
            emotion = "Eating food!";
            std::cout << emotion << std::endl;
        }
        void run(){
            emotion = "Running around!";
            std::cout << emotion << std::endl;
        }
};
int main(){
    Dog myDog("Buddy", "Brown", "Labrador", "Happy");
    std::cout << "--- HOAT DONG CUA CHO ---\n";
    myDog.bark();
    myDog.wagTail();   
    myDog.eat();
    myDog.run();
    return 0;
}