class Solution {
private:
    long long solve(vector<vector<int>>& questions,int n,int index,vector<long long>&dp)
    {
        if(index>=n) return 0;
        //either we might have included the current vector and skipping the mentioned vector
        //questions[index][1] + index should be questions[index][1] + index + 1 to move past the blocked questions correctly.

        if(dp[index]!=-1) return dp[index];

        long long include=questions[index][0]+solve(questions,n,questions[index][1]+index+1,dp);
        //either we have excluded the current vector nad going for next vector
        long long exclude=solve(questions,n,index+1,dp);

        return dp[index]=max(include,exclude);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {

        long long max_points=0;
        int n=questions.size();
        int index=0;
        vector<long long>dp(n,-1);
        return solve(questions,n,index,dp);



        
    }
};