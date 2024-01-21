#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution{
  public:
      bool valid_sudoku(vector<vector<int>> sudo){
              vector<int> test_raw;
      vector<int> test_col;

      for(int i =0;  i < 9; i++){
        for(int j = 0; j < 9; j++){
          test_raw.push_back(sudo[i][j]);
          test_col.push_back(sudo[j][i]);
          
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
      vector<int> test_group;
      while(r !=9 ){
        k = c + 3;
        f = r + 3;
        for(int i = c; i < k; i++){
          for(int j = r; j < f; j++){
            test_group.push_back(sudo[i][j]);
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
    bool valid_elements(vector<int>& elements){
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

  vector<vector<int>> sudo = {
    {1,   2,  3,      4,  5,  6,       7,  8,  9}, // 1
    {11, 12, 13,     14, 15, 16,       17, 18, 19}, // 2
    {21, 22, 23,     24, 25, 26,       27, 28, 29}, // 3


    {31, 32, 33,     34, 35, 36,       37, 38, 39}, // 4
    {41, 42, 43,     44, 45, 46,       47, 48, 49}, // 5
    {51, 52, 32,     54, 55, 56,       57, 58, 59}, // 6


    {61, 62, 63,     64, 65, 66,       67, 68, 69}, // 7
    {71, 72, 73,     74, 75, 76,       77, 78, 79}, // 8
    {81, 82, 83,     84, 8, 86,       87, 88, 89} // 9
  };


  if(Solution().valid_sudoku(sudo)){
    cout << "The given data is valid : " << endl;
  }
  else {
    cout << "The given data is invalid : " << endl;
  }






  return 0;
}