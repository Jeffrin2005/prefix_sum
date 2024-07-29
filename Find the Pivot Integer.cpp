

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;
       vector<int> prefixSum(n+1, 0);
        prefixSum[0] = 0;
        for (int i = 1; i <= n; ++i){
            prefixSum[i] = prefixSum[i - 1] + i;
        }
        for (int x = 1; x <= n; ++x) {
            int suffixSum = totalSum - prefixSum[x - 1];
            if (prefixSum[x] == suffixSum){
                return x;
            }
        }
        return -1;
    }
};
