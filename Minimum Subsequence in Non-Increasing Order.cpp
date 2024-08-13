#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        // Sort the array in non-increasing order
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        vector<int> prefixSums(nums.size());
        prefixSums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }
        vector<int> result;
        int totalSum = prefixSums[n-1]; // The last element in prefixSums is the total sum
        // Add elements to the subsequence until its sum is greater than the remaining sum
        for (int i = 0; i < nums.size(); i++){
            result.push_back(nums[i]);
            int subsequenceSum = prefixSums[i];
            int remainingSum = totalSum - subsequenceSum;

            // Check if the subsequence sum is now greater than the remaining sum
            if (subsequenceSum > remainingSum) {
                break;
            }
        }

        return result;
    }
};
