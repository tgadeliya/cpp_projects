#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string,vector<string>> database;
vector<string> order;
string Make_string (const vector<string>& stops){
    string stops_string;
    for(const string& num: stops){
        stops_string += num+" ";
    }
    return stops_string;
}

bool Check_stops (const vector<string>& bus_stops, const string& stop){
    for (string b_stop : bus_stops){
        if (b_stop == stop){
            return true;
        }
    }
    return false;
}

string buses_for_stop(const string& stop, const string& bus){
    bool flag = false;
    string buses_list;
        for (const auto& bus_name: order){
            if (Check_stops(database[bus_name], stop) & bus != bus_name){
                buses_list += bus_name+" ";
                flag = true;
            }
        }
        if (!flag) {
            buses_list = "No stop";;
        }
    return buses_list;
}

void PerformQuery(string command) {
    if (command =="ALL_BUSES"){
        if (database.size() == 0){
        cout << "No buses"<<endl;
        } else {
            for (const auto& pair : database){
            cout <<"Bus "<<pair.first<<": "<< Make_string(pair.second)<<endl;
            }
        }
    } else if (command == "BUSES_FOR_STOP"){

        string stop; cin >> stop;
        cout << buses_for_stop(stop, "")<<endl;
    } else if (command == "STOPS_FOR_BUS"){
        string bus;
        cin >> bus;
        if (database.count(bus) == 0){
            cout << "No bus"<<endl;
        } else {
        for (const string& stop_on_way: database[bus]){
            string t = buses_for_stop(stop_on_way, bus);
            if(t == "No stop"){
                t = "no interchange";
            }
            cout <<"Stop "<< stop_on_way<<": "<< t<<endl;
        }
        }
    } else if (command == "NEW_BUS"){
        string bus; 
        cin >> bus;
        order.push_back(bus);
        int n;
        cin >> n;
        vector<string> bus_stop(n);
        for (int i=0;i<n;i++){
            cin >> bus_stop[i];
        }
        database[bus] = bus_stop;
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
        //cout<<endl;
    }
    return 0;
}
