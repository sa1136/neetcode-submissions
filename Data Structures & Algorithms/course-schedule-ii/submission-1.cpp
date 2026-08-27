class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // indegree[i] = number of prerequisites for course i
        vector<int> indegree(numCourses, 0);

        // adj[i] = courses that can be taken after course i
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

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // Add course to our answer
            result.push_back(node);

            // Remove this course as a prerequisite
            for (int nei : adj[node]) {

                indegree[nei]--;

                // All prerequisites are completed
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // If we couldn't take all courses, there is a cycle
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};