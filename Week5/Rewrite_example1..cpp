#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;

protected:
    int age;

public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    virtual void say_hello() const {
        cout << "Hello, my name is " << name << " and I am " << age << " years old.\n";
    }

    virtual ~Person() = default; 
};

class Student : public Person {
private:
    string student_id; 

public:
    Student(string name, int age, string student_id) 
        : Person(name, age), student_id(student_id) {}

    void say_hello() const override {
        Person::say_hello();
        cout << "My student ID is " << student_id << ".\n";
    }

    string get_student_id() const {
        return student_id;
    }
};

int main() {
    Person person("John", 25);
    person.say_hello(); 
    
    cout << "------------------\n";

    Student student("Jane", 21, "1234");
    student.say_hello();

    cout << "------------------\n";
    cout << "Name : " << student.name << "\n";
    cout << "Age : " << student.get_student_id() << "\n"; 
    cout << "Student ID : " << student.get_student_id() << "\n";

    return 0;
}