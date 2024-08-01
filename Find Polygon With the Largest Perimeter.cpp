#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
// time comp = o(nlogn) , space comp = o(n)
    long long largestPerimeter(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        // Compute the prefix sums
        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + nums[i];
        }
        // Check for the largest valid perimeter
        for (int i = n - 1; i >= 2; i--){
            ll lsum = pref[i - 1]; // Sum of all elements before nums[i]
            if (lsum > nums[i]){ // Check if we can form a polygon
                return pref[i]; 
            }
        }
        return -1; 
    }
};
