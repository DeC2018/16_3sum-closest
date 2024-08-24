#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);

        for (int i = 0; i < nums.size() - 2; i++) {
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int currentSum = nums[i] + nums[front] + nums[back];
                int diff = abs(currentSum - target);

                if (diff == 0) {
                    return currentSum;
                } else if (diff < minDiff) {
                    closestSum = currentSum;
                    minDiff = diff;
                }

                if (currentSum > target) {
                    back--;
                } else {
                    front++;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    Solution sol;
    int result1 = sol.threeSumClosest(nums1, target1);
    cout << "For input nums = ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << ", target = " << target1 << ", the sum closest to the target is: " << result1 << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    int result2 = sol.threeSumClosest(nums2, target2);
    cout << "For input nums = ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << ", target = " << target2 << ", the sum closest to the target is: " << result2 << endl;

    return 0;
}