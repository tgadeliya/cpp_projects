#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream input("input.txt");
    if (input){
        string line;
        while (getline(input,line)){
        cout << line << endl;
        }
    
    }

    return 0;
}
