

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> line(102, 0); 
        for (auto& car : nums){
            line[car[0]]+=1;
            line[car[1] + 1]-=1;
        }
        line[0] =0;
        for (int i = 1; i < 102; ++i){
            line[i]+=line[i - 1];
        }
        int count = 0;
        for (int i = 1; i <= 100; ++i){ 
            if (line[i] > 0) {
                count++;
            }
        }
        return count;
    }
};
