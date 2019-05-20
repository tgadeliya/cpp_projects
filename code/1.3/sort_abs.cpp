#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<v.size();i++){
        cin >> v[i];
    }
    sort(begin(v),end(v),[](int i,int j){return abs(i)< abs(j);});

    for(const int& num:v){
        cout << num << " ";
    }
    return 0;
}
