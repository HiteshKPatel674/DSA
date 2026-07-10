class Solution {
bool solve(int currindex,int previndex,vector<int>& stones,unordered_map<int,int>&mp,vector<vector<int>>&dp)
{   
    int n=stones.size();
    if(currindex==n-1) return true;
    if(currindex>=n) return false;

    if(dp[currindex][previndex]!=-1) return dp[currindex][previndex];

    int k=stones[currindex]-stones[previndex];
    int poss1=k-1;
    int poss2=k;
    int poss3=k+1;

    
    if(poss1>0)
    {
        auto it1 = mp.find(stones[currindex] + poss1);
        if(it1 != mp.end())
        {
        int next1 = it1->second;
        if(next1<n && solve(next1,currindex,stones,mp,dp)) return dp[currindex][previndex]=true;
        }
    }
    
    auto it2 = mp.find(stones[currindex] + poss2);
    if(it2 != mp.end())
    {
    int next2 = it2->second;//fetching the index of that element if its valid
    if(next2<n && solve(next2,currindex,stones,mp,dp)) return dp[currindex][previndex]=true;
    }

    auto it3 = mp.find(stones[currindex] + poss3);
    if(it3 != mp.end())
    {
    int next3 = it3->second;
    if(next3<n && solve(next3,currindex,stones,mp,dp)) return dp[currindex][previndex]=true;
    }

    return dp[currindex][previndex]=false;

}
public:
    bool canCross(vector<int>& stones) {

        unordered_map<int,int>mp;//Storing stones unit->index
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]]=i;
        }

        if(stones.size()==1)
            return true;

        if(stones[1] != 1)
            return false;
        
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(1,0,stones,mp,dp);

        //dp[currIndex][prevIndex]->Can the frog reach the last stone if it is currently at currIndex and came from prevIndex?
        return dp[1][0];
        
    }
};