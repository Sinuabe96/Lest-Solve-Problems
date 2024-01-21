#include <iostream>
#include <vector>
using namespace std;

int maximumSumWith_len_K_Subarray(vector<int> nums, int k){
  int n = nums.size();
  int sum = 0;

  for(int i =0; i < k; i++){
    sum += nums[i];
  }
    int maxSum = sum;

  for(int i = k; i < n; i++){
     sum = sum - nums[i-k] + nums[i];
     maxSum = max(maxSum, sum);
  }


  return maxSum;
}



int main(){

  vector<int> num = {1, 2, 3, 4, 5, 6, 1};

  cout << "Max Sum " << maximumSumWith_len_K_Subarray(num, 3);



  return 0;
}