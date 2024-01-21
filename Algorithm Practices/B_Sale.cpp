#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Max_earing(vector<int>& val, int k) {
    sort(val.begin(), val.end());
    int max = 0;
    for (int i = 0; i < k; i++) {
        if (val[i] < 0) {
            max += -val[i];
        } else {
            break;
        }
    }
    return max;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }

    cout << Max_earing(nums, k);

    return 0;
}
