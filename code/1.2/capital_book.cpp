#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,string> database;

void PerformQuery(string command){
    if (command =="DUMP"){
        if(database.size()==0){
            cout << "There are no countries in the world";
        } else {
            for (auto pair: database){
                cout << pair.first <<"/"<<pair.second<<" ";
            }
        }
    } else if (command == "ABOUT"){
        string country;
        cin >> country;
        if (database.count(country) == 0){
            cout << "Country "<< country<< " doesn't exist";
        } else {
            cout << "Country "<< country<< " has capital " << database[country]; 
        }
    } else if (command == "RENAME"){
        string old_country_name, new_country_name;
        cin >> old_country_name >> new_country_name;
        if (database.count(old_country_name)==0 ||database.count(new_country_name) == 1 ||  (old_country_name == new_country_name)) {
            cout << "Incorrect rename, skip";
        } else {
            database[new_country_name] = database[old_country_name];
            database.erase(old_country_name);
            cout <<"Country "<< old_country_name << " with capital "<< database[new_country_name] << " has been renamed to "<< new_country_name;
        }

    } else if (command == "CHANGE_CAPITAL"){
        string country, new_capital;
        cin >> country >> new_capital;
        if (database.count(country) == 0){
            database[country] = new_capital;
            cout << "Introduce new country "<<country<< " with capital "<< new_capital;
        } else if (database[country] == new_capital){
            cout << "Country "<< country<< " hasn't changed its capital";
        } else {
            string old_capital = database[country];
            database[country] = new_capital;
            cout << "Country "<<country<<" has changed its capital from "<< old_capital << " to "<<database[country];
        }
            
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i=0;i<n;i++){
        string query;
        cin >> query;
        PerformQuery(query);
        cout<<endl;
    }
    return 0;
}
