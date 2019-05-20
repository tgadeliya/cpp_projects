#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,int> word_map(const string& word){
    map<char,int> wordMap;
    for (const char& l : word){
        ++wordMap[l];;
    }
    return wordMap;
}

string check_maps (const map<char,int>& a,const map<char,int>& b){
    if (a == b) {
        return "YES";
    } else {
        return "NO";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string word1, word2;
    while (n!=0) {
        cin >> word1 >> word2;
        cout << check_maps(word_map(word1),word_map(word2))<<endl;
        --n;
    }
    
    return 0;
}
