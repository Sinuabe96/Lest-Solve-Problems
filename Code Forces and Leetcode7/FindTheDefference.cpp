#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int n = nums.size();

    // Maximum product of three numbers can be either the product of the three largest numbers or
    // the product of the two smallest numbers (negative) and the largest number (positive).
    int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int option2 = nums[0] * nums[1] * nums[n - 1];

    // Handle the case where all numbers are negative.
    int option3 = nums[0] * nums[1] * nums[2];

    return std::max({option1, option2, option3});
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::cout << "Example 1: " << maximumProduct(nums1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout << "Example 2: " << maximumProduct(nums2) << std::endl;

    std::vector<int> nums3 = {-1, -2, -3};
    std::cout << "Example 3: " << maximumProduct(nums3) << std::endl;

    std::vector<int> nums4 = {-4, -5, 1, 4, 5};
    std::cout << "Example 4: " << maximumProduct(nums4) << std::endl;

    return 0;
}
