class Solution {
    typedef long long ll;
ll solve(const vector<int>&nums,int idx,bool flag,int n,vector<vector<long long>> &dp)
{
    if(idx>=n) return 0;

    if(dp[idx][flag]!=-1) return dp[idx][flag];

    ll skip=solve(nums,idx+1,flag,n,dp);
    //Exclude don not change the current sign to opposite one.
    //If flag==true..then if we skip the current idx then we didn't insert the element in odd index..therefore no change in flag.

    ll val= nums[idx];
    if(flag==false) val=-val;

    ll include=solve(nums,idx+1,!flag,n,dp)+val;
    //Include changes the current sign to opposite one.
    //If flag==true i.e., flag is showing that its even index...therefore next element will be odd one...therefore flag==false.

    return dp[idx][flag]=max(include,skip); 
}

public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        //return solve(nums,0,true,n);

        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return solve(nums,0,true,n,dp);
        //true==1 and false==0
        //0-index is the even index
    }
};