#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

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
    Person(string first_name_,  string last_name_, int birth_year_) {
        history_first_name.push_back({birth_year_,first_name_});
        history_last_name.push_back({birth_year_,last_name_});
        birth_year = birth_year_;
    }

  void ChangeFirstName(int year, string first_name) {
    if (birth_year <= year) {
        history_first_name.push_back(year_with_name{year,first_name});
    }
  }
  void ChangeLastName(int year,string last_name) { 
    if (birth_year <= year) {
        history_last_name.push_back(year_with_name{year,last_name});}
  }
  
  string GetFirstName(int year) {
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
        for (int i=hn.size()-2; i>=0;i--){
             result +=  (i != 0) ? hn[i]+", " : hn[i]+")";
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
      if (birth_year > year) {return "No person";}

      sort(begin(history_last_name),end(history_last_name),cmp);
      sort(begin(history_first_name),end(history_first_name),cmp);
      vector<string> first_name_history = {};
      vector<string> last_name_history = {};
      
      for (auto year_db: history_first_name){
          if (year >= year_db.year){
              if (first_name_history.empty()){
                first_name_history.push_back(year_db.name);
              } else if (first_name_history.back() != year_db.name){
                first_name_history.push_back(year_db.name);
              }   
          }
      }

      for (auto year_db : history_last_name){
          if (year >= year_db.year){
               if (last_name_history.empty()){
                last_name_history.push_back(year_db.name);
               } else if (last_name_history.back() != year_db.name){
                last_name_history.push_back(year_db.name);
               }
          }
      }
      
     return MakeFullNameWithHistory(first_name_history,last_name_history);
  }

  string GetFullName(int year) {
      if (birth_year > year) {return "No person";}
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
  int birth_year;
  vector<year_with_name> history_first_name;
  vector<year_with_name> history_last_name;
};


int main() {
//   Person person("Polina", "Sergeeva", 1960);
//   for (int year : {1959, 1960}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1965, "Appolinaria");
//   person.ChangeLastName(1967, "Ivanova");
//   for (int year : {1965, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  vector<int> mm(2,1);
  return 0;
}

