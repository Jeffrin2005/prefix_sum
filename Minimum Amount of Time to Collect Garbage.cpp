class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> prefix(travel.size(), 0);
        int n = garbage.size();
        prefix[0] = travel[0];
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i - 1] + travel[i];
        }
        // Last positions where 'M', 'P', 'G' are found
        int lastM = -1, lastP = -1, lastG = -1;
        // Total minutes to pick up each type of garbage
        int totalM = 0, totalP = 0, totalG = 0;
        // Calculate total time to pick up garbage and find last positions
        for(int i = 0; i < n; i++){
            for(auto&ch : garbage[i]){
                if(ch == 'M'){
                    totalM++;
                    lastM = i;
                }else if (ch == 'P'){
                    totalP++;
                    lastP = i;
                }else if (ch == 'G'){
                    totalG++;
                    lastG = i;
                }
            }
        }
        int totalTime = totalM + totalP + totalG; // Time for taking each M, P, G is 1 minute
        if (lastM > 0) totalTime+=prefix[lastM - 1];
        if (lastP > 0) totalTime+=prefix[lastP - 1];
        if (lastG > 0) totalTime+=prefix[lastG - 1];

        return totalTime;
    }
};
