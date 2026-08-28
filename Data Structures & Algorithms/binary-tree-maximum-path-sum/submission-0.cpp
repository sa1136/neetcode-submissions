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
    int maxSum = INT_MIN;   // best path sum found anywhere in the tree so far

    int maxGain(TreeNode* node) {
        if (!node) return 0;   // empty node contributes nothing

        // get the best gain from each child, but ignore negative gains (treat as 0 -> "don't take that branch")
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // best path that PEAKS here, using both children as "arms"
        int priceNewPath = node->val + leftGain + rightGain;

        // update the global best if this peak beats everything seen so far
        maxSum = max(maxSum, priceNewPath);

        // what we hand UPWARD to our parent: we can only continue in ONE direction,
        // so pick whichever side gives the bigger gain
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};