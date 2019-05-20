#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<vector<string>,int> database;

void ProcessQuery(){
    int n_stations; cin>>n_stations;

    vector<string> way(n_stations);
    for(int i=0; i<n_stations;i++){
        cin>> way[i];
    }
    if (database.count(way)==0){
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
