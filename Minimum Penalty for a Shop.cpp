class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefixY(n + 1, 0); // Prefix sum for 'Y'
        vector<int> prefixN(n + 1, 0); // Prefix sum for 'N'
        for (int i = 0; i < n; ++i) {
            prefixY[i + 1] = prefixY[i] + (customers[i] == 'Y');
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');
        }
        int minPenalty = INT_MAX;
        int bestHour = 0;
        // Calculate penalty for each closing hour and find the minimum
        for (int j = 0; j <= n; ++j) {
            int penalty = prefixN[j] + (prefixY[n] - prefixY[j]);
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        return bestHour;
    }
};
