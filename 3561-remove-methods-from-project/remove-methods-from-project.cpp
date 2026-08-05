class Solution {
void dfs(unordered_map<int,list<int>>&adj,int node,vector<int>&bugs,vector<int>&visited)
{
    if(!visited[node])
    {
        bugs.push_back(node);
        visited[node]=true;
    }

    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour]) dfs(adj,neighbour,bugs,visited);
    }

    return;
}
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int,list<int>>adj;

        unordered_map<int, list<int>> parent;

        for(auto it:invocations)
        {
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);

            parent[v].push_back(u);
        }

        vector<int>visited(n,0);
        vector<int>bugs;

        dfs(adj,k,bugs,visited);

        vector<int>suspicious(n,false);
        for(int i=0;i<bugs.size();i++)
        {
            suspicious[bugs[i]]=true;
        }

        vector<int>allmethods;
        for(int i=0;i<n;i++)
        {
            allmethods.push_back(i);
        }

        for(int node:bugs)
        {
            for(int p:parent[node])
            {
                if(!suspicious[p]) return allmethods;//outside->inside
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!suspicious[i]) ans.push_back(i);
        }

        return ans;


        
        
    }
};