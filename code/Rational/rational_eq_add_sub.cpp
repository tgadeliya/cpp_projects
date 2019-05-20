#include <iostream>

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

// Реализуйте для класса Rational операторы ==, + и -

bool operator== (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) & (lhs.Denominator() == rhs.Denominator());
}

Rational operator+ (const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()){
        return Rational(lhs.Numerator()+ rhs.Numerator(),lhs.Denominator());
    } else {
        int Lnumerator = lhs.Numerator()* rhs.Denominator();
        int Rnumerator = rhs.Numerator()* lhs.Denominator();
        return Rational((Lnumerator + Rnumerator), lhs.Denominator() * rhs.Denominator());
    }
}

Rational operator- (const Rational& lhs, const Rational& rhs) { 
    int Lnumerator = lhs.Numerator()* rhs.Denominator();
    int Rnumerator = rhs.Numerator()* lhs.Denominator();
    return Rational((Lnumerator - Rnumerator), lhs.Denominator() * rhs.Denominator());
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    
    cout << "OK" << endl;
    return 0;
}
