// time comp = o(n) , space comp = o(n)

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
      vector<int> pref(n, 0);
        vector<int> answer(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++){
            pref[i] = pref[i - 1] * nums[i];
        }
        // Compute suffix products and combine with prefix products
        int suffix_product = 1;
        for (int i = n - 1; i > 0; i--) {
            answer[i] = pref[i - 1] * suffix_product;
            suffix_product *= nums[i];
        }
        answer[0] = suffix_product; // For the first element, there's no prefix product

        return answer;
    }
};
