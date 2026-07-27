class Solution {
int solve(vector<int>&coins,int amount,int target,int index,vector<vector<int>>&dp)
{   
    if(target>amount || index>=coins.size()) return 0;

    if(target==amount) return 1;

    if(dp[index][target]!=-1) return dp[index][target];

    int ways=0;
    for(int i=index;i<coins.size();i++)
    {
        ways+=solve(coins,amount,target+coins[i],i,dp);
    }
    return dp[index][target]=ways;
}
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,amount,0,0,dp); 
        
    }
};