#include <iostream>

using namespace std;


int aux(int n,int acc){
    if (n == 0){
        return acc;
    } else {
        return aux((n-1),acc*n);
    }

    }
int Factorial(int n){
    if (n<0) {
        return 1;
    } else {
    return aux(n,1);
    }
}

int main(int argc, char const *argv[])
{   
    int n;
    cin >> n;
    cout << Factorial(n);
    return 0;
}

