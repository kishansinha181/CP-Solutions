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
    
    class Pair{
        public:
        int height;
        int diameter;
    };
    
    Pair diameterHelper(TreeNode * root){
        Pair p;
        if(root == NULL){
            p.height = 0;
            p.diameter = 0;
            
            return p;
        }
        
        Pair left = diameterHelper(root->left);
        Pair right = diameterHelper(root->right);
        
        p.height = max(left.height,right.height) + 1;
        
        //max of three options 
        int op1 = left.height + right.height;
        int op2 = left.diameter;
        int op3 = right.diameter;
        p.diameter = max({op1, op2, op3});
        
        return p;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelper(root).diameter;
        
        
    }
};