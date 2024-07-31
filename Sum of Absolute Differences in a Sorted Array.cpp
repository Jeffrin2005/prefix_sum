class Solution {
// time comp = o(n) space comp = O(n)
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums){
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        vector<int> result(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            // Sum of absolute differences for elements before i
            if (i > 0) {
                int sumBefore = prefixSum[i - 1];
                result[i] += i * nums[i] - sumBefore;
            }
            // Sum of absolute differences for elements after i
            if (i < n - 1){
                int sumAfter = prefixSum[n - 1] - prefixSum[i];
                result[i] += sumAfter - (n - i - 1) * nums[i];
            }
        }
        return result;
    }
};
