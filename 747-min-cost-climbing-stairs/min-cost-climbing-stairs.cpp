class Solution {
int solve(vector<int>&cost,int startindex,vector<int>&dp)
    {   
        int n=cost.size();
        if(startindex>=n)
        {
            return 0;
        }

        if(dp[startindex]!=-1) return dp[startindex];
        int onestep=cost[startindex]+solve(cost,startindex+1,dp);
        int twostep=cost[startindex]+solve(cost,startindex+2,dp);

        return dp[startindex]=min(onestep,twostep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int>dp2(n,-1);
        vector<int>dp1(n,-1);

        int ans=min(solve(cost,0,dp1),solve(cost,1,dp2));

        return ans;

        
    }
};