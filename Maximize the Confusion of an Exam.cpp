

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k){
        int n = answerKey.size();
        vector<int> prefixT(n + 1, 0);
        vector<int>prefixF(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(answerKey[i] == 'T'){
                prefixT[i + 1] = prefixT[i] + 1;
                prefixF[i + 1] = prefixF[i];
            }else{
                prefixF[i + 1] = prefixF[i] + 1;
                prefixT[i + 1] = prefixT[i];
            }
        }
        return max(maxConsecutiveChar(prefixT, k, n), maxConsecutiveChar(prefixF, k, n));
    }

private:
    int maxConsecutiveChar(const vector<int>& prefixCount, int k, int n) {
      int maxLen = 0;
        int l = 0;
        int r = 0; 
        while(r < n){
            while(prefixCount[r + 1] - prefixCount[l] + k < r - l + 1) {
                l++; 
            }
            maxLen = max(maxLen, r - l + 1);
            r++; 
        }

return maxLen;
    }
};
