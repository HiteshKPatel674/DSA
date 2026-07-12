class Solution {
const long long MOD = 1e9 + 7;
long long solve(int stepsLeft,int pos,int arrLen,vector<vector<long long>>&dp)
{
    if(stepsLeft==0)
    {
        if(pos==0) return 1;
        else return 0;
    }

    if (pos > stepsLeft) return 0;
    //as u can't reach the index 0

    if(dp[stepsLeft][pos]!=-1)
    {
        return dp[stepsLeft][pos];
    }
    long long left = 0;
    long long right = 0;

    long long stay=solve(stepsLeft-1,pos,arrLen,dp);
    if(pos+1<arrLen) right=solve(stepsLeft-1,pos+1,arrLen,dp); 
    if(pos-1>=0) left=solve(stepsLeft-1,pos-1,arrLen,dp);

    return dp[stepsLeft][pos]=(((stay%MOD)+(right%MOD))%MOD+(left%MOD))%MOD;
}
public:
    int numWays(int steps, int arrLen) {

        long long ans=0;
        arrLen = min(arrLen, steps + 1);
        //If steps=5... then maximum we can go from index 0 is till index 0->1..1->2..2->3..3->4..4->5..5->6
        //That is till index 6..therefore arrLen is prune to steps+1.
        vector<vector<long long>>dp(steps+1,vector<long long>(arrLen,-1));
        return solve(steps,0,arrLen,dp);

        // solve(stepsLeft, pos);
        // Number of valid ways to end at index 0 after stepsLeft remaining moves, when I'm currently at pos.
        
    }
};