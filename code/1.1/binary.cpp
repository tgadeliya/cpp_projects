#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{   
    int a;
    string bin_a = "";
    cin >> a;

    while (a != 0){
        if (a%2 == 0){
            bin_a = "0" + bin_a;
            a /= s2;
        } else {
            bin_a = "1" + bin_a;
            a = (a-1)/2;
        }
    }
    cout << bin_a <<endl;
    return 0;
}
