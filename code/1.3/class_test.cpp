#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    string_list.push_back(s);
    sort_list();
  }
  vector<string> GetSortedStrings() {return string_list;}
private:
  void sort_list(){
      sort(begin(string_list),end(string_list));
  }
  vector<string> string_list;
};
