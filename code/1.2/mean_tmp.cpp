#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int sum = 0;
    int mean = 0;
    cin >> n;
    vector<int> v(n);

    for (int i=0;i<n;i++){
        cin >>v[i];
        sum += v[i];
    }
    mean = sum / n;

    vector<int> res;
    for (int i=0; i < v.size() ;i++){
        if (v[i] > mean){
            res.push_back(i);
        }
    }
    
    cout<< res.size()<<endl;

    for (auto d: res){
        cout << d << " ";
    }

    return 0;
}
