

class Solution {
public:
    int maxSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> psum(m, std::vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                psum[i][j+1] = psum[i][j] + grid[i][j];
            }
        }
        
        int max_so_far = 0;
        for (int i = 2; i < m; ++i) {
            for (int j = 2; j < n; ++j) {
                int first_row = psum[i-2][j+1] - psum[i-2][j-2];
                int third_row = psum[i][j+1] - psum[i][j-2];
                max_so_far = std::max(max_so_far, first_row + grid[i-1][j-1] + third_row);
            }
        }
        
        return max_so_far;
    }
};
