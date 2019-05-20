#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream input("input.txt");
    int n,m;
    input >> n;input >> m;
    input.ignore(1);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            string line;
            (j != m-1) ? (getline(input,line,',')) : (getline(input,line,'\n'));
            (j == (m-1)) ? (cout << fixed << setw(10) << line) : (cout << fixed << setw(10) << line << ' ' );
        }
        if (i != n-1) {cout << endl;};
    }

    return 0;
}
