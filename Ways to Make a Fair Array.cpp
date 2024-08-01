
class Solution {
public:
// time comp =o(n) space comp =o(n)
    int waysToMakeFair(vector<int>& nums){
        int n = nums.size();
        vector<int> prefixEven(n + 1, 0), prefixOdd(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefixEven[i + 1] = prefixEven[i] + (i % 2 == 0 ? nums[i] : 0);
            prefixOdd[i + 1] = prefixOdd[i] + (i % 2 != 0 ? nums[i] : 0);
        }
        int res = 0;
        int rightEven = 0, rightOdd = 0;

        // Initialize right sums
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                rightEven += nums[i];
            }else{
                rightOdd += nums[i];
            }
        }
        // Calculate right sums and check for fairness
        for (int i = 0; i < n; ++i) {
            // Remove the current element from the right sums
            if(i % 2 == 0){
                rightEven -= nums[i];
            }else{
                rightOdd -= nums[i];
            }
            // Check for fairness using prefix sums and current right sums
            if(prefixEven[i] + rightOdd == prefixOdd[i] + rightEven){
                res++;
            }
            // Update prefix sums for the next iteration
            if (i % 2 == 0) {
                prefixEven[i + 1] = prefixEven[i] + nums[i];
            }else{
                prefixOdd[i + 1] = prefixOdd[i] + nums[i];
            }
        }

        return res;
    }
};
