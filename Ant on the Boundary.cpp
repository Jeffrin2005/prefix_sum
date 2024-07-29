
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
         int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        int count = 0; 
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
              prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        for(int i=0;i<n; i++){
             if(prefixSum[i] == 0){
                count++;
            }
        }
        return count;
    }
};
