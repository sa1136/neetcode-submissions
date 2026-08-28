/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;   // empty tree -> nothing visible

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();   // freeze how many nodes belong to THIS level before we start pushing next-level nodes in

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // i counts left-to-right position within the level.
            // i == size - 1 means this is the RIGHTMOST node in the row -> visible from the side
            if (i == size - 1) result.push_back(node->val);

            // queue up this node's children so they form the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}
};
