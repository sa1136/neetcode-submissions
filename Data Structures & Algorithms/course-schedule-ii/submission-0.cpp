class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;

        // Add courses with no prerequisites
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // Topological Sort using BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int nei : adj[node]) {

                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // If we could not process all courses,
        // there is a cycle
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};

// Time Complexity: O(V + E) — we visit every course (V) and every prerequisite/edge (E) once.

// Space Complexity: O(V + E) — the adjacency list stores all edges, while the indegree array, queue, and result array use O(V) space.