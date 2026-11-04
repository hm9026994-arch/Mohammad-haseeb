class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        multiset<long long> low, high;
        long long sum_low = 0, sum_high = 0;
        
        auto balance = [&]() {
            int k1 = (x + 1) / 2;
            while (low.size() < k1 && !high.empty()) {
                auto it = high.begin();
                sum_low += *it;
                sum_high -= *it;
                low.insert(*it);
                high.erase(it);
            }
            while (low.size() > k1) {
                auto it = prev(low.end());
                sum_high += *it;
                sum_low -= *it;
                high.insert(*it);
                low.erase(it);
            }
        };

        auto add = [&](long long val) {
            if (low.empty() || val <= *prev(low.end())) {
                low.insert(val);
                sum_low += val;
            } else {
                high.insert(val);
                sum_high += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto it = low.find(val);
            if (it != low.end()) {
                sum_low -= val;
                low.erase(it);
            } else {
                it = high.find(val);
                if (it != high.end()) {
                    sum_high -= val;
                    high.erase(it);
                }
            }
            balance();
        };

        vector<long long> windowCost(n - x + 1, 0);
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *prev(low.end());
                long long cost = (median * low.size() - sum_low) + (sum_high - median * high.size());
                windowCost[i - x + 1] = cost;
            }
        }

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 1e18));
        
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            long long min_prev = 1e18;
            for (int i = 1; i <= n; ++i) {
                if (i >= x) {
                    min_prev = min(min_prev, dp[j - 1][i - x] + windowCost[i - x]);
                }
                dp[j][i] = min(dp[j][i - 1], min_prev);
            }
        }

        return dp[k][n];
    }
};