class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){.
                int r1 = max(1, i-k);
                int c1 = max(1, j-k);
                int r2 = min(n, i+k);
                int c2 = min(m, j+k);
                // finding res[i-1][j-1] = bottom right - bottom left - top right + top left
                res[i-1][j-1] = pref[r2][c2] - pref[r2][c1-1] - pref[r1-1][c2] + pref[r1-1][c1-1];
            }
        }

        return res;
    }
};
