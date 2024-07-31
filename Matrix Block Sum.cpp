class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int  m = mat[0].size();
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0)); 
        prefix[0][0] = mat[0][0];
        //  the first row of the prefix sum matrix
        for(int j = 1; j < m; j++){ 
            prefix[0][j] = prefix[0][j-1] + mat[0][j];
        }

        //  the first column of the prefix sum matrix
        for(int i = 1; i < n;i++){
            prefix[i][0] = prefix[i-1][0] + mat[i][0];
        }
        for(int i = 1; i < n;i++){
            for (int j = 1; j < m;j++){
                prefix[i][j] = mat[i][j] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];
            }
        }
        vector<vector<int>>answer(n,vector<int>(m, 0)); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(n - 1, i + k), c2 = min(m - 1, j + k);
                answer[i][j] = prefix[r2][c2];
                if(r1 > 0) answer[i][j]-=prefix[r1-1][c2];
                if(c1 > 0) answer[i][j]-=prefix[r2][c1-1];
                if(r1 > 0 && c1 > 0) answer[i][j]+=prefix[r1-1][c1-1];
            }
        }

        return answer;
    }
};
