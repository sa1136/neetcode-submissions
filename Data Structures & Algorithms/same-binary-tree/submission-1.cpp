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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case:
        // If both nodes are NULL, both trees have ended at this point.
        // So they are the same.
        if (!p && !q) {
            return true;
        }

        // If both nodes exist AND their values are equal,
        // recursively check:
        // 1. Left subtrees
        // 2. Right subtrees
        if (p && q && p->val == q->val) {

            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }

        // If:
        // - One node is NULL and the other is not, OR
        // - Their values are different
        // Then the trees are not the same.
        else {
            return false;
        }
    }
};

/*
    TIME COMPLEXITY: O(N)

    We visit each node once in the worst case.
    N = number of nodes in the trees.

    SPACE COMPLEXITY: O(H)

    Due to the recursive call stack.
    H = height of the tree.

    - Balanced tree  -> O(log N)
    - Skewed tree    -> O(N)
*/
