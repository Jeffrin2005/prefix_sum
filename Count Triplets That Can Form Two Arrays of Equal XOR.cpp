class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXor(n + 1);

        // Compute the prefix XOR array
        for (int i = 0; i < n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }

        int count = 0;
        // Use prefix XOR to find triplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prefixXor[i] == prefixXor[j + 1]) {
                    count += (j - i);
                }
            }
        }

        return count;
    }
};
