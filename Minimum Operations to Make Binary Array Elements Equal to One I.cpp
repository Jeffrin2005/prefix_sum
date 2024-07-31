

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1; 
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> flip(n + 1, 0); // Array to track flips, size n+1 to handle boundary easily.
        int result = 0; // Result to store the minimum operations.
        int flips = 0; // To track the number of flips affecting the current position.

        for (int i = 0; i < n; ++i) {
            flips += flip[i]; // Update the current number of flips affecting this position.
            // Determine the effective value of nums[i] after flips.
            int previousValue = 0;
            if (i > 0) {
                previousValue = prefix[i - 1];
            }
            int effectiveValue = (prefix[i] - previousValue + flips) % 2;
            if (effectiveValue == 0) { // Check if the current element is 0 after all flips.
                if (i > n - 3) {
                    // If there's not enough space to flip this and the next two elements, return -1.
                    return -1;
                }
                // Perform a flip operation on this and the next two elements.
                result++;
                flips++; // We flip at i, affecting i, i+1, and i+2.
                flip[i] += 1;
                flip[i + 3] -= 1; // This will negate the flip effect after the third element.
            }
        }
        return result;
    }
};
