#include <iostream>
#include <vector>
#include <string>

using namespace std;


 vector<bool> queue;
// true - worry, false - quiet


void ProcessQueue(string command){
    if (command == "WORRY_COUNT"){
        int i = 0;
        for (auto s: queue){
            if (s == true){
                ++i;
            }
            //cout << s << " ";
        }
        //cout<<endl;
        cout << i << endl;
    } else {
        int num;
        cin >> num;
        if (command == "WORRY"){
            queue[num]= true;
        } else if (command == "COME"){
            if (num <0){
                queue.resize(queue.size()+num);
            } else {
                queue.resize(queue.size()+num,false);
            }
        } else if (command == "QUIET"){
            queue[num]=false;
        }
        
    }
}

int main() {    
    int n_command;
    string inp_command;
    cin >> n_command;
    while (n_command != 0){
        cin >> inp_command;
        ProcessQueue(inp_command);
        --n_command;  
    }
    return 0;
}
