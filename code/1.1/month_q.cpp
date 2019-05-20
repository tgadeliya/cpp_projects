#include <iostream>
#include <vector>
#include <string>

using namespace std;

int month = 0;
vector<int> calendar = {31,28,31,30,31,30,31,31,30,31,30,31};
    
vector<vector<string>> tasks(31);

void Process(string comm){
    if (comm == "NEXT"){
        int old_month_days = calendar[month];
        month = (month+1) % 12;
        int n_month_days = calendar[month];
        if(old_month_days > n_month_days) {
          //New month has LESS days then previous    
            for (int i = (n_month_days);i< old_month_days;i++){
                tasks[n_month_days-1].insert(end(tasks[n_month_days-1]),begin(tasks[i]),end(tasks[i]));
            }
            tasks.resize(n_month_days);
        } else {
          //New month has MORE days then previous
            tasks.resize(n_month_days,{});
        }
    } else if (comm == "DUMP"){
        int day;
        cin >> day;
        cout << tasks[day-1].size()<<" ";
        for (auto task: tasks[day-1]) {
            cout << task << " "; 
        }
        cout <<endl;
    } else if (comm == "ADD"){
        int day;
        string task;
        cin >> day;
        cin >> task;
        tasks[day-1].push_back(task);
    }
}

int main(){
    int n_oper;
    cin >> n_oper;

    for (int i=0;i < n_oper;i++){
        string comm;
        cin >> comm;
        Process(comm);
    }

    return 0;
}
