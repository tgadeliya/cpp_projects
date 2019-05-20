#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int res = -2;
    string word;
    cin >> word;
    int i = 0;
    for(char c :word) {   
        if (c == 'f' && res == -2) {
            res = -1;
        } else if (c == 'f' && res == -1){
            res = i;
            break;
        }
        ++i;
    }
    
    cout << res <<endl;

    return 0;
}
