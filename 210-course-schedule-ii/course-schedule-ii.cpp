class Solution {
bool isCycle(int node,vector<int>&dfsvisited,vector<int>&visited, unordered_map<int,list<int>>&adjlist,vector<int>&order)
{
    visited[node]=true;
    dfsvisited[node]=true;

    for(auto neighbour:adjlist[node])
    {   
        if(!visited[neighbour])
        {
            bool cycle=isCycle(neighbour,dfsvisited,visited,adjlist,order);

            if(cycle) return true;
        }
        else if(dfsvisited[neighbour]) return true;
        
    }

    dfsvisited[node]=false;
    order.push_back(node);
    

    return false;
}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        vector<int>dfsvisited(n,0);
        vector<int>visited(n,0);

        unordered_map<int,list<int>>adjlist;
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];

            adjlist[v].push_back(u);
        }

        vector<int>order;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(isCycle(i,dfsvisited,visited,adjlist,order))
                {
                    order.clear();
                    return order;
                }
            }
        }

        reverse(order.begin(),order.end());
        return order;

    }
};