
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;



void CheckDayMonth(int month, int day) {
  if ( (month > 12) || (month <= 0) ) {
    string error_message  = "Month value is invalid: " + to_string(month);
    throw runtime_error(error_message);
  }
  if ( (day > 31) || (day <= 0) ) {
    string error_message  = "Day value is invalid: " + to_string(day);
    throw runtime_error(error_message);
  }
}


class Date {
  public:
    Date(string str){
      int y,m,d;
      char del1,del2;
      stringstream ss(str);
      try{
        
        if (!(ss >> y >> del1 >> m >> del2 >> d)) {
          throw exception();
        }
        
        //  // cout << !(ss.peek() == EOF)<<endl;
        // cout << y <<endl;
        // cout << del1 <<endl;
        // cout << m <<endl;
        // cout << del2 <<endl;
        // cout << d <<endl;  

        if ( !(ss.peek() == EOF) || (del1 != '-') || (del2 != '-') || ((y) > 9999)){
          throw exception();
        }
      } catch (exception& e) {
          string error_message = "Wrong date format: " + str;
          throw runtime_error(error_message);
        }
      CheckDayMonth(m, d);
      SetDate(y,m,d);
    }
  
  int GetYear() const {
    return year;
  };
  int GetMonth() const{
    return month;
  };
  int GetDay() const{
    return day;
  };

  vector<int> GetVector() const{
      return {year, month, day};
  }
  
  void SetDate(const int& new_year, const int& new_month, const int& new_day){
    year = new_year;
    month = new_month;
    day = new_day;
  };
  private:
  int year;
  int month;
  int day;
};

void CheckDateAndSkip(istream& stream){
  if (stream.peek()!= '-'){
    throw exception();
    cout << ""<<endl;
  } else {
    stream.ignore(1);
  }
};

string SetToString(set<string> str_set){
    string concat_string;
    for (auto el: str_set){
      concat_string += " "+ el ;
    }
    return concat_string;
};

bool operator<(const Date& lhs, const Date& rhs){
  return lhs.GetVector() < rhs.GetVector();  
}

string generate_zeros(int num){
  string zeros;
  for (int i=0;i<num;i++){
    zeros += "0";
  }
  return zeros;
}
string PrepareDate(Date date){
  string right_format;
  
  string year = to_string(date.GetYear()) ;
  string month = to_string(date.GetMonth());
  string day = to_string(date.GetDay());
  
  right_format += generate_zeros(4 - year.size()) + year+'-';
  right_format += generate_zeros(2 - month.size())+ month+'-';
  right_format += generate_zeros(2 - day.size()) + day;

  return right_format;
};

class Database {
  public:
    void AddEvent(const Date& date, const string& event) {

      if (database.count(date) == 0){
        database[date] = {event};
      } else {
        database[date].insert(event);
      }
    };

    void DeleteEvent(const Date& date, string event){
          if (database[date].count(event) == 0 ) {
            cout << "Event not found" << endl;
          } else {
            database[date].erase(event);
            cout << "Deleted successfully" << endl;
          }
    };

    void DeleteDate(const Date& date) {
        int number_of_events = database[date].size();
        database.erase(date);
        cout <<"Deleted " << number_of_events << " events" << endl;
    };
    
    void Find(const Date& date) const {
          if (database.count(date) == 0){
                cout << endl;
          } else {
            for (const string& event : database.at(date)){
                cout << event << endl;
            }
          }
    };  

    void Print() const {
          for(auto& item : database) {
            string prepared_date = PrepareDate(item.first);
            for (auto& event : item.second){
              cout << prepared_date << " " << event << endl;   
            }
          }
    };

  private:
    map<Date,set<string>> database;
};

vector<string> ParsingCommandLine (const string& line, const char& delimeter){
      vector<string> result = {};
      string arg;
      stringstream text(line);
      while (getline(text,arg, delimeter)) {
        result.push_back(arg);
      }
      return result;
}

int main() {
  Database db;
  try{
  string line;
  while (getline(cin, line)) {
      vector<string> commands = ParsingCommandLine(line, ' ');

      if (commands.empty()){
        // Empty line. Nothing to do
      } else if (commands[0] == "Add") {
          Date date(commands[1]);
          db.AddEvent(date, commands[2]);
      } else if (commands[0] == "Del") {
          Date date(commands[1]);
          if (commands.size() == 2) { 
              db.DeleteDate(date);
          } else {
              db.DeleteEvent(date, commands[2]); 
          }
      } else if (commands[0] == "Find") { 
          Date date(commands[1]);
          db.Find(date);
      } else if (commands[0] == "Print") {
          db.Print();  
      } else { 
          string str = "Unknown command: "+commands[0];
          throw runtime_error(str);
      } 
           
  }

  } catch (exception& e){
    cout << e.what() << endl;
    return 1;
  }
  return 0;
}


