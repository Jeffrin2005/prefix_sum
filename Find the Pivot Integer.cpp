

class Solution {
public:
    int pivotInteger(int n) {
        // Calculate the total sum of numbers from 1 to n
        int totalSum = n * (n + 1) / 2;
        // Create a vector to store prefix sums
       vector<int> prefixSum(n + 1, 0);
        // Calculate prefix sums
        prefixSum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + i;
        }

        // Iterate through numbers from 1 to n to find the pivot integer
        for (int x = 1; x <= n; ++x) {
            // Calculate the suffix sum using prefix sums
            int suffixSum = totalSum - prefixSum[x - 1];
            // Check if prefix sum equals suffix sum
            if (prefixSum[x] == suffixSum){
                return x;
            }
        }

        // If no pivot integer is found, return -1
        return -1;
    }
};
