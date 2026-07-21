class Solution {
int solve(vector<vector<int>>&grid,int curr_row,int curr_col,int sum,int&min_sum,vector<vector<int>>&dp)
{   
    if(curr_row>=grid.size() || curr_col>=grid[0].size()) return INT_MAX;

    if(curr_row==grid.size()-1 && curr_col==grid[0].size()-1)
    {   
       return grid[curr_row][curr_col];
    }

    if(dp[curr_row][curr_col]!=-1) return dp[curr_row][curr_col];

    //going down
    int down=solve(grid,curr_row+1,curr_col,sum+grid[curr_row][curr_col],min_sum,dp);
    int right=solve(grid,curr_row,curr_col+1,sum+grid[curr_row][curr_col],min_sum,dp);

    return dp[curr_row][curr_col]=grid[curr_row][curr_col]+min(down,right);
    //f(i,j) = grid[i][j] + min(f(i+1,j), f(i,j+1))
}
public:
    int minPathSum(vector<vector<int>>& grid) {

        int sum=0;
        int min_sum=INT_MAX;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=solve(grid,0,0,sum,min_sum,dp);
        return ans ;
        
    }
};