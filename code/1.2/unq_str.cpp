#include <iostream>
#include <set>


using namespace std;



int main(int argc, char const *argv[])
{
    int n; cin>>n;
    set<string> set_of_strings;

    for (int i=0;i<n;i++){
        string str;
        cin >> str;
        set_of_strings.insert(str);
    }

    cout << set_of_strings.size();
    return 0;
}
