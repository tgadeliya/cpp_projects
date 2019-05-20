#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

map<string,set<string>> database;

void ProcessQuery(const string& command){
    if (command == "ADD"){
        string word1,word2;
        cin >> word1 >> word2;
        database[word1].insert(word2);
        database[word2].insert(word1);
    } else if(command == "COUNT"){
        string word;
        cin >> word;
        // int counter = 0;
        // for (auto pair : database){
        //     if ( pair.first == word || pair.second.count(word) != 0){
        //         counter++;
        //     } 
        // }
        cout <<database[word].size()<<endl;
    } else if (command == "CHECK") {
        string word1, word2;
        cin >> word1 >> word2;
        if (database[word1].count(word2) != 0 || database[word2].count(word1) != 0 ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        string command;
        cin >> command;
        ProcessQuery(command);
    }
    return 0;
}
