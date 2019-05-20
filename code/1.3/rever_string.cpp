#include <string>
#include <iostream>

using namespace std;

class ReversibleString {
    public:
    ReversibleString() {}
    ReversibleString(const string& str){
        string_value = str;
    }
    string ToString() const{
        return string_value; 
    }
    void Reverse(){
        string temp = "";

        for (auto literal: string_value){
            temp = literal + temp; 
        }
        string_value = temp;
    }

    private:
    string string_value; 
};


int main(int argc, char const *argv[])
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
  
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
  
    return 0;
}