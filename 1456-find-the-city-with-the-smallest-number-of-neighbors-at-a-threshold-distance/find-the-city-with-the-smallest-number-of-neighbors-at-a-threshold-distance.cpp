class Solution {
vector<int>djkstra(unordered_map<int,list<pair<int,int>>>&adj,int src,int n)
{   
    set<pair<int,int>>st;//Nodedistance,Node

    vector<int>distance(n,INT_MAX);
    distance[src]=0;
    st.insert({0,src});
    while(!st.empty())
    {
        auto top=*(st.begin());

        int nodedistance=top.first;
        int node=top.second;

        st.erase(top);

        for(auto neighbour:adj[node])
        {
            if(nodedistance+neighbour.second<distance[neighbour.first])
            {
                auto record=st.find(make_pair(distance[neighbour.first],neighbour.first));
                if(record!=st.end()) st.erase(record);

                distance[neighbour.first]=nodedistance+neighbour.second;

                st.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }

    return distance;
}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,list<pair<int,int>>>adj;

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            adj[u].push_back(make_pair(v,w));
            adj[v].push_back({u,w});
        }

        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(djkstra(adj,i,n));
        }

        vector<vector<int>>cities;
        for(int i=0;i<v.size();i++)
        {   
            vector<int>city;
            for(int  j=0;j<v[0].size();j++)
            {
                if(v[i][j]<= distanceThreshold && i!=j)
                {
                    city.push_back(j);
                }
            }
            cities.push_back(city);
        }

        int mini = INT_MAX;
        int mini_city = -1;

        for(int i=0;i<cities.size();i++)
        {
            int size=cities[i].size();
            int city=i;
            if(size < mini || (size == mini && i > mini_city))
            {
                mini = size;
                mini_city = i;
            }
        }
        return mini_city;
        
    }
};