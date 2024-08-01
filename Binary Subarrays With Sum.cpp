class Solution {
// time comp =o(n) space comp =o(n)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
        prefixSumCount[0] = 1;
        for(auto&num : nums){
            prefixSum += num;
            if(prefixSumCount.find(prefixSum - goal) != prefixSumCount.end()) {
                count+=prefixSumCount[prefixSum - goal];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
