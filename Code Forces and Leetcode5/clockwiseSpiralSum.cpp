#include <iostream>
#include <vector>

using namespace std;

int clockwiseSpiralSum(const vector<vector<int>>& matrix) {
    int col = matrix[0].size();
    int raw = matrix.size();
    int left = 0, right = col - 1, top = 0, bottom = raw - 1;
    int sum = 0;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i) {
            sum += matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            sum += matrix[i][right];
        }
        right--;
        if (left <= right) {
            for (int i = right; i >= left; --i) {
                sum += matrix[bottom][i];
            }
            bottom--;
        }
        if (top <= bottom) {
            for (int i = bottom; i >= top; --i) {
                sum += matrix[i][left];
            }
            left++;
        }
    }

    return sum;
}

int main() {
    vector<vector<int>> matrixC = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Calculate the clockwise spiral sum
    int result = clockwiseSpiralSum(matrixC);

    // Output the result
    cout << "The Sum of the matrix in the clockwise spiral  is: " << result << endl;

    return 0;
}
