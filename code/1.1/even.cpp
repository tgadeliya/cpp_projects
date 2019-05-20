#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int p, q;

    cin >> p >> q;

    for (int i = p; i <= q; i++){
        int t = i / 2;
        if ((2 * t) == i)
        {
            cout << i <<endl;
        }
    }

    return 0;
}
