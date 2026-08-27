class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

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

        int finish = 0;

        // Topological Sort using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            finish++;

            for (int nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // If all courses were finished, no cycle exists
        return finish == numCourses;
    }
};