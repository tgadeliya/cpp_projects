#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool IsPalindrom(string str) {
        int len = str.size();
        for (int i=0; i < len / 2; ++i) {
            if (str[i] != str[len - i - 1]){
                return false;
            } 
        }
        return true;
    }

vector<string> PalindromFilter(vector<string> words,int minLength) {
    vector<string> res;
    for (auto w: words){
        if (!(w.size() < minLength) && IsPalindrom(w)) {
            res.push_back(w);
        }
    }
    return res;
}