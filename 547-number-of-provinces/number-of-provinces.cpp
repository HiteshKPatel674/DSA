class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>> &isConnected)
{
    vis[node]=true;
    for(int neighbour = 0; neighbour < isConnected.size(); neighbour++)
    {
        if(isConnected[node][neighbour] == 1 && !vis[neighbour])
        {
            dfs(neighbour, vis, isConnected);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V=isConnected.size();
        vector<bool>vis(V,false);
        int count=0;


        for(int i=0;i<V;i++)
        {   
            if(!vis[i])
            {
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
        
    }
};