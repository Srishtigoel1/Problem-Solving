class Solution {
public:
int  help(vector<int>&nums,int n,vector<int>&dp)
{
    // if(n==0)
    // {
    //     return dp[0]=nums[0];
    // }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int twostep=INT_MIN;
    int onestep;
     onestep=help(nums,n-1,dp);
    // if(n-2>=0)
     twostep=help(nums,n-2,dp)+nums[n];
    return dp[n]=max(onestep,twostep);
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        help(nums,nums.size()-1,dp);
        // if(nums[nums.size()-1]>dp[nums.size()-1])
        // {
        //     return nums[nums.size()-1];
        // }
        return dp[nums.size()-1];
        
    }
};