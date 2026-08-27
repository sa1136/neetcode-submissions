/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        // Map original node -> copied node
        // Helps us avoid copying the same node again
        map<Node*, Node*> oldToNew;

        // Start DFS from the given node
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {

        // If there is no node, return nullptr
        if (node == nullptr) {
            return nullptr;
        }

        // If we already copied this node,
        // return the existing copy
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a new copy of the current node
        Node* copy = new Node(node->val);

        // Store the copy in the map
        // before visiting its neighbors
        oldToNew[node] = copy;

        // Go through all neighbors of the current node
        for (Node* nei : node->neighbors) {

            // Copy each neighbor and connect it
            // to the current copied node
            copy->neighbors.push_back(
                dfs(nei, oldToNew)
            );
        }

        // Return the copied node
        return copy;
    }
};


// Time Complexity: O(V + E) — we visit every node (V) and every edge/connection (E) once.
// Space Complexity: O(V) — the map stores every node, and the DFS recursion can go up to V nodes deep.