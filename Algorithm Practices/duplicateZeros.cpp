#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;

        while( left < n){
            if(arr[left] == 0){
                arr.insert(arr.begin()+left, 0);
                arr.pop_back();
                left += 2;
            }
            else {
                left++;
            }
        }
    }
};

int main(){

    vector<int> arr = {1, 0, 2, 0, 3, 4, 5, 0, 0, 2, 3, 4, 0, 7};
    
    Solution().duplicateZeros(arr);

    for(int i: arr){
        cout << i << "  ";
    }
   return 0;
}



