#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution{
  public:
      bool isValidSudoku(vector<vector<char>> sudo){
        vector<char> test_raw;
        vector<char> test_col;

      for(int i =0;  i < 9; i++){
        for(int j = 0; j < 9; j++){
          if(sudo[i][j] >= '0' && sudo[i][j] <= '9'){
          test_raw.push_back(sudo[i][j]);
          }
          if(sudo[j][i] >= '0' && sudo[j][i] <= '9'){
          test_col.push_back(sudo[j][i]);
          }
        }

        if(!valid_elements(test_raw)){
          return false;
          break;
        }

        if(!valid_elements(test_col)){
          return false;
          break;
            }
        test_col = {};
        test_raw = {};
      }
      int c =0, r = 0;
      int k = 0, f = 0;
      vector<char> test_group;
      while(r !=9 ){
        k = c + 3;
        f = r + 3;
        for(int i = c; i < k; i++){
          for(int j = r; j < f; j++){
            if(sudo[i][j] >= '0' && sudo[i][j] <= '9'){
              test_group.push_back(sudo[i][j]);
            }
          }
        }

        if(!valid_elements(test_group)){
          return false;
            }

          c += 3;
        if(c == 9){
          c = 0;
          r += 3;
        }
        test_group = {};
      }
          return true;

      }

    bool valid_elements(vector<char> elements){
       sort(elements.begin(), elements.end());

          for(size_t i = 0; i < elements.size()-1; i++){
            if(elements[i] == elements[i+1]){
              return false;
              break;
            }
          }
            return true;
    }

};

int main(){

  vector<vector<char>> sudo = {
    {'1', '2', '3',      '4', '5', '6',      '7', '8', '9'}, // 1
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}, // 2
    {'4', '5', '6',      '7', '8', '9',      '1', '2', '3'}, // 2


    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}, // 2
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}, // 2
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'},
    
     // 2
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}, // 2
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}, // 2
    {'.', '.', '.',      '.', '.', '.',      '.', '.', '.'}
  };



  if(Solution().isValidSudoku(sudo)){
    cout << "The given data is valid : " << endl;
  }
  else {
    cout << "The given data is invalid : " << endl;
  }

  return 0;
}