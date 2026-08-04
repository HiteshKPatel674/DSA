class Solution {
    public:
    int solve(int l,int r,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(r-l<2) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];

        int result=INT_MAX;
        for(int index=l+1;index<=r-1;index++)
        {
            int cost=(cuts[r]-cuts[l])+solve(l,index,cuts,dp)+solve(index,r,cuts,dp);
            result=min(cost,result);
        }

        return dp[l][r]=result;
    }
    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));

        return solve(0, cuts.size()-1, cuts, dp);

    }
};