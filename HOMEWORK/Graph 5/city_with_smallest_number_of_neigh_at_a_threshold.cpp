class Solution {
public:
   int findshort(unordered_map<int, vector<pair<int, int>>>& m, int i, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});
        vector<int> ans(n, INT_MAX);
        ans[i] = 0; // Initialize distance for start node
        while (!q.empty()) {
            auto x = q.top();
            int r = x.first; // Distance
            int c = x.second; // Node
            q.pop();
            for (auto j : m[c]) {
                if (j.second + r <= k && j.second + r < ans[j.first]) { // Check if within threshold and smaller distance
                    ans[j.first] = j.second + r;
                    q.push({ans[j.first], j.first});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != INT_MAX) { // Check if reachable within threshold
                count++;
            }
            
        }
        return count-1;//self deleted
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> m;
        //adjacency
        for (int i = 0; i < edges.size(); i++) {
            m[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            l[i] = findshort(m, i, n, distanceThreshold);//hrr ke liye kitni city
        }
        int mini = INT_MAX;
        int result = -1;
       for(int i=l.size()-1;i>=0;i--)
       {
        if(l[i]<mini)
        {
            mini=l[i];
            result=i;
        }
       }
        return result;
    
        
    }
};