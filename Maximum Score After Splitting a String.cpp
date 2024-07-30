
// time comp = On) space comp  = o(n)
class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length();
        std::vector<int> prefixZeros(n + 1, 0);// prefixsum for  zeros
        std::vector<int> prefixOnes(n + 1, 0);// prefixsum for ones

        // Initialize the first element of prefix sums based on the first character
                if(s[0] == '0'){
                    prefixZeros[0] = 1;
                    prefixOnes[0] = 0;
                }else{
                    prefixZeros[0] = 0;
                    prefixOnes[0] = 1;
                }

        // compute prefix sums for zeros and ones
        for(int i = 1; i < n; i++){
                if(s[i] == '0'){
                    prefixZeros[i] = prefixZeros[i - 1] + 1;
                    prefixOnes[i] = prefixOnes[i - 1];
                }else{
                    prefixZeros[i] = prefixZeros[i - 1];
                    prefixOnes[i] = prefixOnes[i - 1] + 1;
                }
        }
        int maxScore = 0;
        // Calculate the score for each possible split point
        for(int i = 0; i < n-1; i++){
            int scoreLeftZeros = prefixZeros[i];
            int scoreRightOnes = prefixOnes[n - 1] - prefixOnes[i];
            int currentScore = scoreLeftZeros + scoreRightOnes;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};
