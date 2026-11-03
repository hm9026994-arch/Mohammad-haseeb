class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min_val = nums[0];
        int max_val = nums[0];

        for (int num : nums) {
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }

        long long max_subarray_value = max_val - min_val;
        return max_subarray_value * k;
    }
};