/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto *curr = root;
        // Assume that p < q; else swap
        if (p->val > q->val)
            swap(p,q);
        while (curr->val < p->val || curr->val > q->val) {
            while (curr->val < p->val) {
                curr = curr->right;
            }
            while(curr->val > q->val) {
                curr = curr->left;
            }
        }
        return curr;
    }
};