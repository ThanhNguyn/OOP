#include <iostream>
#include <string>
class Money {
public:
    int amount;
    std::string currency;
    Money(int amount, std::string currency = "VND") 
        : amount(amount), currency(currency) {}
    friend bool operator==(const Money& lhs, const Money& rhs) {
        return (lhs.amount == rhs.amount) && (lhs.currency == rhs.currency);
    }
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        os << m.amount << " " << m.currency;
        return os;
    }
};