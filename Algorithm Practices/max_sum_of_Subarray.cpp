#include <iostream>
#include <vector>
using namespace std;

int max_sum_of_Subarray(vector<int> nums){
    int max_sum = nums[0];
    int current_sum = nums[0];

    for(int i =1; i < nums.size(); i++){
        current_sum = max(current_sum + nums[i], nums[i]);

        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}


int main(){

    vector<int> nums = {1, -2, 3, 0, -4, 7, 2, -5, 1};

    cout << "Max Sum: " << max_sum_of_Subarray(nums);



    return 0;
}