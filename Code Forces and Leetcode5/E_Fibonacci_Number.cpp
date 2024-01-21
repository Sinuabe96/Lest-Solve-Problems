#include <iostream>
#include <vector>
using namespace std;

vector<long long> find(int num, vector<long long> fib){
  long long first = 0;
  long long second = 1;
  long long next, sum = 0;
  fib.push_back(first);
  fib.push_back(second);

  for(int i =1; i < num; i++){
    next = first + second;
    fib.push_back(next);
    first = second;
    second = next;
  }

  return fib;
}



using namespace std;


int main(){


  vector<long long>fib;
  int n;
  cin >> n;
  fib = find(n, fib);
     bool found = false;
   for(int i = 0; i < fib.size(); i++){
    if(fib[i] == n){
      cout << i;
      found = true;
      fib.clear();
      break;
    }
   }
   if(!found){
    cout << -1;
   }



  return 0;
}