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
     bool Util(TreeNode *root, long minVal,long maxVal){
       if(root == NULL)
           return (true);
        long data = root->val;
         if(data < minVal || data > maxVal )
             return (false);
         bool checkLeft = Util(root->left, minVal, data-1);
         bool checkRight = Util(root->right, data+1, maxVal);
         
         return (checkLeft && checkRight);
        
    }
    bool isValidBST(TreeNode* root) {
       bool result=Util(root,INT_MIN,INT_MAX);
        return(result);
        
    }
};