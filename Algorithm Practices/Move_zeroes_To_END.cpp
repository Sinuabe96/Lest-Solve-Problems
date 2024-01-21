#include <iostream>
using namespace std;
#include <vector>

void Move_zeroes_To_END(vector<int>& nums){
    int left =0;
    int right = nums.size()-1;

    while(left <= right){
      if(nums[left] == 0){
        nums.insert(nums.begin()+right+1, 0);
        nums.erase(nums.begin() + left);
        right--;
      }

      else if(nums[left] != 0){
        left++;
      }
    }
}



int main(){
  vector<int> nums = {1, 0, 2, 3, 0, 0, 3, 4};
  Move_zeroes_To_END(nums);
  for(int i: nums){
    cout << i <<"  ";
  }
}