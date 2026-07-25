class Solution {
public:
    int solve(vector<int>& coins, int index, int target,vector<vector<int>>& dp)
    {
        if(target == 0)
            return 0;

        if(index == coins.size())
            return INT_MAX;

        if(dp[index][target] != -1)
            return dp[index][target];

        int mini = INT_MAX;

        for(int i = index; i < coins.size(); i++)
        {
            if(coins[i] <= target)
            {
                int ans = solve(coins, i, target - coins[i], dp);

                if(ans != INT_MAX)
                    mini = min(mini, ans + 1);
            }
        }

        return dp[index][target] = mini;
    }

    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end());

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};