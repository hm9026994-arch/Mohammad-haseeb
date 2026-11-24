#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1;
        const long long MAX_LG = 2520LL * 10LL; // 25200

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                if (prod > MAX_LG / x) {
                    break; // prod already exceeds max possible l * g
                }
                prod *= x;
                g = (g == 0) ? static_cast<int>(x) : std::gcd(g, static_cast<int>(x));
                l = (l / std::gcd<long long>(l, x)) * x;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
