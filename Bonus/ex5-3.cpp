#include <string>
class Animal {
protected:
    std::string name_;
public:
    Animal(const std::string& n) : name_(n) {}
    virtual ~Animal() = default;
        virtual std::string make_sound() const { 
        return "generic sound"; 
    }
    std::string describe() const {
        return "Tôi là " + name_ + ", tiếng kêu: " + make_sound();
    }
};
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    std::string make_sound() const override {
        return "Gâu!";
    }
};
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    std::string make_sound() const override {
        return "Meo!";
    }
};