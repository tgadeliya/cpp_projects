#include <iostream>
#include <set>
#include <map>
using namespace std;

set <string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;
    for(const auto& pair : m){
        values.insert(pair.second);
    }
    return values;
}