class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            adj[u].push_back({v, wt});
        }

        // dist[node][edges_used] = minimum cost
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // {cost, node, edges_used}
        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()) {

            auto [cost, node, edges] = pq.top();
            pq.pop();

            if(node == dst)
                return cost;

            if(edges == k + 1)
                continue;

            for(auto &[next, wt] : adj[node]) {

                int newCost = cost + wt;

                if(newCost < dist[next][edges + 1]) {

                    dist[next][edges + 1] = newCost;
                    pq.push({newCost, next, edges + 1});
                }
            }
        }

        return -1;
    }
};