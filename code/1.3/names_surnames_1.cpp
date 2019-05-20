#include <vector>
#include <iostream>
#include <algorithm>
#include <string>;

using namespace std;


struct year_with_name {
    int year;
    string name;
};

bool cmp(year_with_name p1,year_with_name p2){
    return  p1.year < p2.year;
}
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) { 
    history_first_name.push_back({year,first_name});
  }
  void ChangeLastName(int year, const string& last_name) { 
    history_last_name.push_back({year,last_name});
  }
  
  string GetFirstName(int year){
      if (history_first_name.size() == 0 ) { 
          return "None";
      }
      sort(begin(history_first_name),end(history_first_name),cmp);
      if (history_first_name.back().year <= year){
          return history_first_name.back().name;
      } else if (history_first_name.front().year > year){
          return "None";
      } else {
      for (int i=1;i<history_first_name.size();i++){
          if (year < history_first_name[i].year & year >= history_first_name[i-1].year){
              return history_first_name[i-1].name;
          }
      }
      }   
  }
  string GetLastName(int year){
      if (history_last_name.size() == 0 ) { return "None";}
      sort(begin(history_last_name),end(history_last_name),cmp);
      if (history_last_name.back().year <= year){
          return history_last_name.back().name;
      } else if (history_last_name.front().year > year){
          return "None";
      } else {
       for (int i=1;i<history_last_name.size();i++){
          if (year < history_last_name[i].year & year >= history_last_name[i-1].year){ return history_last_name[i-1].name;}
        }
      }
      
  }

  string make_order(vector<string> hn){
      if (hn.size() > 1){
        string result= " (";
        for (int i=0; i<hn.size()-1;i++){
             result +=  (i != hn.size()-2) ? hn[i]+", " : hn[i]+")";
        }
        return hn.back()+result;
      } else {
        return hn.back();
      }
  }
  string MakeFullNameWithHistory(vector<string> fnh,vector<string> lnh){
      if (fnh.empty() & lnh.empty()){
          return "Incognito";
      } 

      if (fnh.empty()){
          return make_order(lnh) + " with unknown first name";
      } else if (lnh.empty()){
          return make_order(fnh) + " with unknown last name";
      } else {
          return make_order(fnh) +" "+ make_order(lnh);
      }
  }
  string GetFullNameWithHistory(int year){
      sort(begin(history_last_name),end(history_last_name),cmp);
      sort(begin(history_first_name),end(history_first_name),cmp);
      vector<string> first_name_history ={};
      vector<string> last_name_history = {};
      for (auto year_db : history_first_name){
          if (year >= year_db.year & first_name_history.back() != year_db.name){
                first_name_history.push_back(year_db.name);   
          }
      }
      }
      for (auto year_db : history_last_name){
          if (year >= year_db.year & last_name_history.back() != year_db.name){
                last_name_history.push_back(year_db.name);   
          }
      }
     return MakeFullNameWithHistory(first_name_history,last_name_history);
  }

  string GetFullName(int year) {
      string first_name = GetFirstName(year);
      string last_name = GetLastName(year);
    
      if (last_name == "None" & first_name == "None") {
          return "Incognito";
      } else if (last_name == "None"){
          return first_name+" with unknown last name";
      } else if (first_name == "None"){
          return last_name+" with unknown first name";
      } else {
          return first_name+" "+last_name;
      }
      
   }
private:
  vector<year_with_name> history_first_name;
  vector<year_with_name> history_last_name;
};



int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}