class Solution {
    int solve(int index,vector<int>& prices,vector<vector<int>>&dp,int buy)
    {
        if(index>=prices.size()) return 0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        int profit=0;
        if(buy)
        {
            int buykaro=-prices[index]+solve(index+1,prices,dp,0);
            int skipkaro=0+solve(index+1,prices,dp,1);
            profit=max(buykaro,skipkaro);
        }
        else
        {
            int sellkaro= +prices[index]+solve(index+2,prices,dp,1);
            int skipkaro=0+solve(index+1,prices,dp,0);
            profit=max(sellkaro,skipkaro);
        }

        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,dp,1);
        
    }
};