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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(! root|| !p||!q) return nullptr;

        if(max(p->val,q->val)<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if (min(p->val,q->val)>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
        
    }
};

// Time: O(h) — At each step, you move only left or right down the BST, visiting at most the tree height h.

// Space: O(h) — Because the solution is recursive, the call stack can contain up to h calls.
