class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, list<pair<int, int>>> adj;

        // Build adjacency list
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        // (distance, node)
        set<pair<int, int>> st;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {

            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            for (auto neighbour : adj[topNode]) {

                int nextNode = neighbour.first;
                int weight = neighbour.second;
                if (nodeDistance+weight<dist[nextNode]) {

                    // Remove old record if present
                    auto record = st.find({dist[nextNode],nextNode});
                    if (record != st.end())
                        st.erase(record);
                    dist[nextNode] = nodeDistance+weight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};