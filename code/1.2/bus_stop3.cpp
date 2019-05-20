#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<set<string>,int> database;

void ProcessQuery(){
    int n_stations;
    cin>>n_stations;
    
    set<string> way;

    for(int i=0; i<n_stations;i++){
        string station;
        cin >> station;
        way.insert(station);
    }
    // way - set of stations
    bool flag = true;
    for (auto& pair :database){
        if (pair.first == way) {
            flag=false;
        }
    }

    if (flag){
        int new_value = database.size()+1;
        database[way]= new_value;
        cout<<"New bus "<<new_value<<endl;
    } else {
        cout<<"Already exists for "<<database[way]<<endl;
    }
}
int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    for(int i=0;i< n ;++i){
        ProcessQuery();
    }
    return 0;
}
