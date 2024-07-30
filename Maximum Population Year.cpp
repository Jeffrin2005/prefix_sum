
class Solution {
// time comp = o(n) , space comp = o(1)
public:
    int maximumPopulation(vector<vector<int>>& logs){
        vector<int>pref(2054);
        for(auto&x : logs){
            pref[x[0]]++;
            pref[x[1]]--;
        }
         int maxi = 0;
          int year = 0; 
        pref[0] = 0;
        for(int i=1; i<pref.size(); i++){
            pref[i]+=pref[i-1];
        }
        for(int i=1950; i<=2050; i++){
            if(pref[i] > maxi){
                maxi = pref[i];
                year = i; 
            }
        }
        return year;
    }
};
