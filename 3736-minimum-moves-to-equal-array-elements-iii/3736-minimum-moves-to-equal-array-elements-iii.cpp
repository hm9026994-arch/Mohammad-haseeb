class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Find the maximum element in the array
        int max_val = nums[0];
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
        }
        
        // Sum up the difference between the max value and each element
        int total_moves = 0;
        for (int num : nums) {
            total_moves += (max_val - num);
        }
        
        return total_moves;
    }
};