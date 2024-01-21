#include <iostream>
#include <vector>
using namespace std;

pair<int, int> scoreOfTwoPlayers(vector<int> val){
    if(val.size() == 0){
        return {0, 0};
    }
    int Score_A = 0,  Score_B = 0;
    int left = 0,  right = val.size()-1;
    bool play_A = true;
    bool play_B = false;
    while(left <= right){
        int Max = max(val[left], val[right]);
        if(play_A){
            Score_A += Max;
            play_A = false;
            play_B = true;
        }
        else {
            Score_B += Max;
            play_B = false;
            play_A = true;
        }
        if( val[left] == Max){
        left++;
        }
        else {
            right--;
        }
    }
    return {Score_A, Score_B};
    
}


int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        nums.push_back(s);
    }
    
    pair<int, int> score = scoreOfTwoPlayers(nums);
    cout << score.first << " " << score.second;   
    
    
    
    
    
    return 0;
}