class Solution {

    int solve(vector<int>&nums,int startindex,int endindex,vector<int>&dp)
    {   
        if(startindex>endindex)
        {
            return 0;
        }

        if(dp[startindex]!=-1) return dp[startindex];
        int include=nums[startindex]+solve(nums,startindex+2,endindex,dp);
        int exclude=solve(nums,startindex+1,endindex,dp);

        return dp[startindex]=max(include,exclude);
    }
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        if(n==1) return nums[0];
        int ans=max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
        return ans;
        
    }
};