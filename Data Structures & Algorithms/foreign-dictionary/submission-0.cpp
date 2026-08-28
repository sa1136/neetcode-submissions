class Solution {
public:

    string foreignDictionary(vector<string>& words) {

        int V = 26;

        // Adjacency list: adj[u] contains characters that come after u
        vector<vector<int>> adj(V);

        // indegree[i] = number of characters that must come before i
        vector<int> indegree(V, 0);

        // present[i] = true if character i appears in the dictionary
        vector<bool> present(V, false);

        // Mark all characters that appear in the words
        for (auto& word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Compare every pair of adjacent words
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            // Compare only up to the length of the shorter word
            int len = min(s1.size(), s2.size());

            bool found = false;

            // Find the first character where the two words differ
            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    // s1[j] comes before s2[j]
                    // Example: z -> o
                    adj[u].push_back(v);

                    // v has one more prerequisite
                    indegree[v]++;

                    found = true;

                    // Only the first different character matters
                    break;
                }
            }

            // Invalid case:
            // Example: ["abc", "ab"]
            // A longer word cannot come before its prefix
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Queue stores characters with no prerequisites
        queue<int> q;

        // Add only characters that actually appear
        // and have indegree 0
        for (int i = 0; i < V; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string result = "";

        // BFS Topological Sort (Kahn's Algorithm)
        while (!q.empty()) {

            // Take a character with no remaining prerequisites
            int node = q.front();
            q.pop();

            // Convert number back to character and add to answer
            result += char(node + 'a');

            // Process all characters that depend on this character
            for (auto nei : adj[node]) {

                // One prerequisite is now completed
                indegree[nei]--;

                // If all prerequisites are completed,
                // this character can now be processed
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Count how many unique characters actually appear
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (present[i]) {
                count++;
            }
        }

        // If we could not process all characters,
        // there is a cycle, so no valid ordering exists
        if (result.size() != count) {
            return "";
        }

        // Time Complexity: O(N * L + V + E)
        // We compare adjacent words in O(N * L), then process every character and edge once.

        // Space Complexity: O(V + E)
        // The adjacency list stores V characters and E edges, while indegree, queue, and result use O(V).

        return result;
    }
};