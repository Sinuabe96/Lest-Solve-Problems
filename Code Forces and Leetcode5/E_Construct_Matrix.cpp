#include <iostream>
#include <vector>
using namespace std;
void printMattrix(int n, long long k){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(k == 0){
        cout << 0 << " ";
      }

      
      else if(k == n){
        if( i == j){
          cout << 1 << " ";
        }
        else {
          cout << 0 << " ";
        }

      }
      
      else if( k == n*(n-1)){
        if( i == j){
          cout << 0 << " ";
        }
        else {
          cout << 1 << " ";
        }
      }
      else if(k == n*n){
        cout << 1 << " ";
      }
    }
    cout << endl;
  }
}

int main(){
  int n;
  long long k;
  int t;
  cin >> t;
  while(t--){
  cin >> n >> k;
  if(k == 0 || k == n || k == n*(n-1) || k == n*n){
    cout << "Yes" << endl;
    printMattrix(n, k);
  }
  else {
    cout << "No" << endl;
  }
  }
  return 0;
}