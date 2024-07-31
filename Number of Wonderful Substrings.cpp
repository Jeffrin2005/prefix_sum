#include <bits/stdc++.h>
// time comp = o(n) , space comp = o(1)
#define ll long long 
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        vector<int>prefix(n + 1, 0); 
        map<int, int> freq;
        ll count = 0;
        freq[0] = 1;  

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ (1 << (word[i] - 'a'));  
            count+=freq[prefix[i + 1]];  // even character 
            for (int j = 0; j < 10; ++j) {
                count+=freq[prefix[i + 1] ^ (1 << j)];// one odd charcater
            }
            freq[prefix[i + 1]]++;
        }

        return count;
    }
};
