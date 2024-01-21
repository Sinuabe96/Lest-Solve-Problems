#include <iostream>
#include <vector>
using namespace std;

pair<int, int> max_sum_of_Subarray(vector<int> nums){
    int start = 0, end = 0;
    int current_sum = nums[0];
    int max_sum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i] + current_sum){
            current_sum = nums[i];
            start = i;
        }
        else {
            current_sum = current_sum + nums[i];
        }

        if( current_sum > max_sum){
            end = i;
            max_sum = current_sum;
        }
    }

    return {start, end};


}


int main(){

    vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5, 1};

    pair<int, int> val = max_sum_of_Subarray(nums);

    cout << "Start: " << val.first << endl;
    cout << "Second: " << val.second << endl;



    return 0;
}