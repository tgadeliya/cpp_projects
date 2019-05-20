#include <iostream>
#include <string>

using namespace std;

struct Specialization {
  string value;
 explicit Specialization (string name) {
    value = name;
  };
};

struct Course{
 string value;
 
 explicit Course (string name) {
   value = name;
 };
};

struct Week {
  string value;
  
  explicit Week(string name) {
     value = name;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  
  LectureTitle (Specialization spec, Course course_name, Week week_number){
    specialization = spec.value;
    course = course_name.value;
    week = week_number.value;
  }
};

