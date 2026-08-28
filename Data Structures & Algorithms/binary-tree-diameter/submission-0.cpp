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
    int diameter = 0;   // tracks the best answer found anywhere in the tree so far

    int height(TreeNode* root) {
        if (!root) return 0;   // empty node has height 0

        int left = height(root->left);    // height of left subtree
        int right = height(root->right);  // height of right subtree

        // path through THIS node = left height + right height (in edges)
        diameter = max(diameter, left + right);

        // return this node's own height so the parent can use it
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);       // this single pass fills in `diameter` as a side effect
        return diameter;
    }
};
