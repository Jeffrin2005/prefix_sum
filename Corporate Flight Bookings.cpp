#include <vector>
// time comp = o(n) space comp = o(n)
class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> seats(n + 1, 0); // Create a vector of size n+1 to handle the prefix sum easily

        // Apply the difference array concept
        for (const auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seatCount = booking[2];

            seats[first - 1] += seatCount;
            if (last < n) {
                seats[last] -= seatCount;
            }
        }
      vector<int> result(n);
        result[0] = seats[0];
        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + seats[i];
        }

        return result;
    }
};
