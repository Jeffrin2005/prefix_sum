// time comp = o(n^2) space comp = o(n)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>costs(n, 0);
        // Calculate the cost for each character change
        for(int i = 0; i < n;i++){
            costs[i] = abs(s[i] - t[i]);
        }
        vector<int>prefixSum(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefixSum[i + 1] = prefixSum[i] + costs[i];
        }
        // Find the maximum length of substring with cost <= maxCost
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int currentCost = prefixSum[j + 1] - prefixSum[i];
                if (currentCost <= maxCost){
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};
