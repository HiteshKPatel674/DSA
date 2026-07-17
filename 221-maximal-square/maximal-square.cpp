class Solution {
int solve(int curr_row,int curr_col,int n,int m,vector<vector<char>>& matrix,vector<vector<int>>&dp)
{
    if(curr_row>=n || curr_col>=m) return 0;

    if(matrix[curr_row][curr_col]=='0') return 0;

    if(dp[curr_row][curr_col]!=-1) return dp[curr_row][curr_col];

    int right=solve(curr_row,curr_col+1,n,m,matrix,dp);
    int down=solve(curr_row+1,curr_col,n,m,matrix,dp);
    int diagonal=solve(curr_row+1,curr_col+1,n,m,matrix,dp);
    
    return dp[curr_row][curr_col]=1 + (min(right,min(down,diagonal)));

}
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int max_ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ans=solve(i,j,n,m,matrix,dp);
                max_ans=max(ans,max_ans);
            }
        }

        

        return max_ans *max_ans;

        
        
    }
};