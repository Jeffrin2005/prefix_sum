class Solution {
// time comp = o(n) ,space comp = o(n)
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int minPrefix = *min_element(prefixSum.begin(), prefixSum.end());
        if(minPrefix >= 1){
            return 1; // If all prefix sums are >= 1, startValue can be 1
        }else{
            return 1 - minPrefix; // Adjust startValue to make the smallest prefix sum equal to 1
        }
    }
};
