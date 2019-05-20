#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator== (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) & (lhs.Denominator() == rhs.Denominator());
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

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
    return lhs + Rational( -1 * rhs.Numerator(), rhs.Denominator());
}


bool operator< (const Rational& lhs, const Rational& rhs){
    return (rhs - lhs).Numerator() > 0; 
}



int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
