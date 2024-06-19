class Solution {
public:
    int help(int i, vector<int>& nums, vector<int>& dp, int flag) {
        if (flag == 0) {
            if (i == 0) {
                return dp[i] = nums[0];
            }
            if (i < 0) {
                return 0;
            }
        } else {
            if (i == 1) {
                return dp[i] = nums[1];
            }
            if (i < 1) {
                return 0;
            }
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int pick = nums[i] + help(i - 2, nums, dp, flag);
        int notpick = help(i - 1, nums, dp, flag);
        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            //you missed edge case last time 
            return nums[0];
        }
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        vector<int> dp(nums.size(), -1);
        vector<int> d(nums.size(), -1);
        int value1 = help(i, nums, dp, 0);
        int value2 = help(j, nums, d, 1);
        return max(value1, value2);
    }
};