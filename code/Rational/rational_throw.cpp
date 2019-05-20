#include <iostream>
#include <exception>


using namespace std;

int gcd (int a, int b){
    while (a != 0 && b != 0)
    {
        if (a > b) {
            a = a%b;            
        } else {
            b = b%a;
        }
    }
    return a+b;
}

class Rational {
    public:
    Rational() {
        // Default constructor
        num = 0;
        den = 1; 
    }

    Rational(int numerator, int denominator) : Rational() {
        if (denominator == 0) {
            throw invalid_argument("");
        }
        if (numerator == 0) {
            Rational();
        } else{
            int GCDivisor = gcd(abs(numerator), abs(denominator));
            if ((numerator * denominator) > 0){
                numerator = abs(numerator);
                denominator = abs(denominator);  
            } else if (denominator < 0){
                numerator = -numerator;
                denominator = abs(denominator);
            } 
            num = numerator/GCDivisor;
            den = denominator/GCDivisor;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {

        return den;
    }

    private:
    int num;
    int den;
};

Rational operator* (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("");
    } 
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}


int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
