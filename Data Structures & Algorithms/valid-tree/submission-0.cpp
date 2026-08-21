class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit;
        queue<pair<int, int>> q;
        q.push({0, -1});  // {current node, parent node}
        visit.insert(0);

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (nei == parent) {
                    continue;
                }
                if (visit.count(nei)) {
                    return false;
                }
                visit.insert(nei);
                q.push({nei, node});
            }
        }

        return visit.size() == n;
    }
};