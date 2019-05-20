#include <string>
#include <vector>
#include <iostream>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    
    for (auto s: source){
        destination.push_back(s);
    }
    source.clear();
}


int main(int argc, char const *argv[])
{
    vector<string> source, destination;

    source = {"a","b","c"};
    destination = {"z","o","b"};

    MoveStrings(source,destination);

    for (auto s: source){
        cout << s;
    }
    cout <<endl;
    for (auto b: destination){
        
        cout << b;
    }
    return 0;
}
