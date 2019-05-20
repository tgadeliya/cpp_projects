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

Rational operator* (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("");
    } 
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

bool operator== (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) & (lhs.Denominator() == rhs.Denominator());
}

istream& operator>>(istream& stream, Rational& r){
    int num = r.Numerator();
    int den = r.Denominator();
    stream >> num;
    stream.ignore(1);
    stream >> den;
    r = Rational(num,den);
    return stream;
}

ostream& operator<< (ostream& stream, const Rational& r){
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

Rational Perform_op (string op, Rational a, Rational b){
    if (op == "+"){
        return a + b;
    } else if (op == "-"){
        return a - b;
    } else if (op == "/"){
        return a / b;
    } else if (op == "*"){
        return a * b;
    }
}

int main(int argc, char const *argv[])
{
    try {
    Rational a,b;
    string op;
    cin >> a;
    cin >> op;
    cin >> b;

    cout << Perform_op(op, a, b);

    } catch (invalid_argument&) {
        cout << "Invalid argument";
    } catch(domain_error& ){
        cout << "Division by zero";
    }
    
    return 0;
}
