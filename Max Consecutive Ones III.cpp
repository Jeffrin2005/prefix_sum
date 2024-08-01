

class Solution {
// time comp =o(n) space comp =o(n)
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n, 0);
        if(nums[0] == 0){
            prefix[0] = 1;
        }else{
            prefix[0] = 0;
        }
        for(int i = 1; i < n; i++){
            if(nums[i] == 0){
                prefix[i] = prefix[i - 1] + 1;
            }else{
                prefix[i] = prefix[i - 1];
            }
        }
        int left = 0;
        int  right = 0;
        int  max_length = 0;
        while(right < n){
           int zeros = 0;
            if(left > 0){
                zeros = prefix[right] - prefix[left - 1];
            }else{
                zeros = prefix[right];
            }
            if (zeros <= k){
                // If the number of zeros is within the limit, update max_length
                max_length = max(max_length, right - left + 1);
                right++;
            } else{
                //move the left pointer to shrink the window
                left++;
            }
        }
        return max_length;
    }
};
