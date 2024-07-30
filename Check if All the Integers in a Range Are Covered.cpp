class Solution {
//Time complexity:o(n)
//Space complexity:o(1)
//
//
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>cover(52, 0); 
        for(auto& range : ranges){
            cover[range[0]]++;
            cover[range[1] + 1]--;
        }
        int currentCoverage = 0;
        for (int i = 1; i <= 50; i++) {
            currentCoverage+=cover[i];
            if (i >= left && i <= right && currentCoverage == 0) {
                return false; 
            }
        }
// ranges = [[1,2],[4,5]]
// left = 1
// right = 5
// [0, 1, 0, -1, 1, 0, -1, 0, ...]
//For the range [1,2], increment cover[1] and decrement cover[3].
// For the range [4,5], increment cover[4] and decrement cover[6].
// After marking, the cover array looks like this (only showing indices 0 to 7 for brevity):
// Step 3: Calculate the prefix sum and check coverage
// Initialize currentCoverage to 0.
// Iterate from i = 1 to 50 and update currentCoverage using the prefix sum technique.
// Detailed Iteration:
// At i = 1: currentCoverage += cover[1] → currentCoverage = 1 (covered)
// At i = 2: currentCoverage += cover[2] → currentCoverage = 1 (still covered)
// At i = 3: currentCoverage += cover[3] → currentCoverage = 0 (not covered)  so return false 
// At i = 4: currentCoverage += cover[4] → currentCoverage = 1 (covered again)
// At i = 5: currentCoverage += cover[5] → currentCoverage = 1 (still covered)

        return true;
    }
};
