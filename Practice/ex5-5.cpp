#include <stdexcept>
class Temperature {
private:
    double _c;
public:
    Temperature(double c = 0.0) {
        _c = 0.0;
        set_celsius(c); 
    }

    double celsius() const {
        return _c;
    }

    void set_celsius(double value) {
        if (value < -273.15) {
            throw std::invalid_argument("");
        }
        _c = value;
    }

    double fahrenheit() const {
        return _c * 9.0 / 5.0 + 32.0;
    }

    void set_fahrenheit(double value) {
        set_celsius((value - 32.0) * 5.0 / 9.0);
    }
};