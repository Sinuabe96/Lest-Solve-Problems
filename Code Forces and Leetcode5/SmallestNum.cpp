#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0; 
        }
      bool negative = false;
      if(num < 0) {
        negative = true;
        num = -num;
      }
        vector<long long> digits;
        while (num > 0) {
            long long rem = num % 10;
            digits.push_back(rem);
            num /= 10;
        }

        if(negative){
          sort(digits.begin(), digits.end(),greater<int>());
        }
        else {
          sort(digits.begin(), digits.end());
        }

        if (digits.size() > 1 && digits[0] == 0) {
            for(int i = 1; i < digits.size(); i++){
              if(digits[i]!=0){
                int temp = digits[i];
                digits[i] = digits[0];
                digits[0] = temp;
                break;
              }
            }
        }

        long long answer = 0;
        long long exp = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            answer += digits[i] * exp;
            exp *= 10;
        }

        if(negative){
          return -answer;
        }
        return answer;
    }
};

int main(){

  Solution sol;
  long long num;
  cin >> num;

  cout << sol.smallestNumber(num) << endl;


  return 0;
}