#include <string>
#include <vector>
#include <iostream>

using namespace std;



vector<int> Reversed(const vector<int>& nums){
    vector<int> t;
    int len = nums.size();
    for (int i = 0 ; i<len ; ++i){
        t.push_back(nums[len-1-i]) ;
    }
    return t;
}
