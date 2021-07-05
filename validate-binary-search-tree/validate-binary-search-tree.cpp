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
     bool Util(TreeNode *root, long max,long min){
        if(root==NULL) return(true);
        if(root->val>max || root->val<min) return(false);
        long data=root->val;
        bool left_val,right_val;
        left_val=Util(root->left,data-1,min);
        right_val=Util(root->right,max,data+1);
        return(right_val && left_val);
        
    }
    bool isValidBST(TreeNode* root) {
       bool result=Util(root,INT_MAX,INT_MIN);
        return(result);
        
    }
};