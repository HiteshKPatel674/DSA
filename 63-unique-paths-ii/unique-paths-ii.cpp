class Solution {
int solve(vector<vector<int>>& obstacleGrid,int curr_row,int curr_col,int n,int m,vector<vector<int>>&dp)
{   
    if(curr_row>=n || curr_col>=m) return 0; 

    if(obstacleGrid[curr_row][curr_col]==1) return 0;

    if(curr_row==n-1 && curr_col==m-1)
    {
        return dp[curr_row][curr_col]=1 ;
    }
    if(dp[curr_row][curr_col]!=-1) return dp[curr_row][curr_col];

    int down=solve(obstacleGrid,curr_row+1,curr_col,n,m,dp);
    int right=solve(obstacleGrid,curr_row,curr_col+1,n,m,dp);

    return dp[curr_row][curr_col]=(right+down);
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        //vector<vector<int>>visited(n.vector<int>(m,0));

        vector<vector<int>>dp(n,vector<int>(m,-1));
        //Number of unique paths from (i,j) to (n-1,m-1).

   
        int ans=solve(obstacleGrid,0,0,n,m,dp);
        return ans;
        


        
    }
};