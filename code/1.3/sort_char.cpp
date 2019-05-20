#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(string s1,string s2){
    for(int i=0;i<max(s1.size(),s2.size());i++){
        if (tolower(s1[i]) < tolower(s2[i])){
            return true;
        } else if (tolower(s1[i]) > tolower(s2[i])){
            return false;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<v.size();i++){
        cin >> v[i];
    }
    
sort(begin(v),end(v),cmp);

    for(const string& num:v){
        cout << num << " ";
    }
    return 0;
}
