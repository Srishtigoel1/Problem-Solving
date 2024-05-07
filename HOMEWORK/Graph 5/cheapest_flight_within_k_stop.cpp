class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int, int>>> adj(n);
        for ( auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dis(n, INT_MAX);
        while (!q.empty()) {
            auto x = q.front();
            int steps = x.first;
            int node = x.second.first;
            int distance = x.second.second;
            q.pop();

            if (steps > k) {
                continue;
            }

            for (auto i : adj[node]) {
                if (distance + i.second < dis[i.first]) {
                    dis[i.first] = distance + i.second;
                    q.push({steps + 1, {i.first, dis[i.first]}});
                }
            }
        }

        return (dis[dst] == INT_MAX) ? -1 : dis[dst];
        
    }
};