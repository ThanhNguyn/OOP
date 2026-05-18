#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
class Polynomial {
private:
    std::vector<long long> coeffs;
public:
    Polynomial(const std::vector<int>& c) {
        for (int x : c) coeffs.push_back(x);
    }
    Polynomial(const std::vector<long long>& c) {
        coeffs = c;
    }
    std::string str() const {
        int n = coeffs.size();
        std::string res;

        for (int i = 0; i < n; ++i) {
            long long coef = coeffs[i];
            if (coef == 0) continue;

            int degree = n - i - 1;
            long long absCoef = std::llabs(coef);

            std::string term;

            if (degree == 0) {
                term = std::to_string(absCoef);
            } else if (degree == 1) {
                if (absCoef == 1)
                    term = "x";
                else
                    term = std::to_string(absCoef) + "x";
            } else {
                if (absCoef == 1)
                    term = "x^" + std::to_string(degree);
                else
                    term = std::to_string(absCoef) + "x^" + std::to_string(degree);
            }
            if (res.empty()) {
                if (coef < 0) res += "-";
                res += term;
            } else {
                if (coef < 0)
                    res += " - " + term;
                else
                    res += " + " + term;
            }
        }
        if (res.empty()) return "0";
        return res;
    }
    long long operator()(long long x) const {
        long long result = 0;
        for (long long coef : coeffs) {
            result = result * x + coef;
        }
        return result;
    }
    Polynomial operator+(const Polynomial& other) const {
        int n = coeffs.size();
        int m = other.coeffs.size();
        int len = std::max(n, m);
        std::vector<long long> a(len, 0), b(len, 0);
        for (int i = 0; i < n; ++i) {
            a[len - n + i] = coeffs[i];
        }
        for (int i = 0; i < m; ++i) {
            b[len - m + i] = other.coeffs[i];
        }
        std::vector<long long> sum(len);
        for (int i = 0; i < len; ++i) {
            sum[i] = a[i] + b[i];
        }
        return Polynomial(sum);
    }
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        os << p.str();
        return os;
    }
};