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
    int inorderPredecssor ( TreeNode *root)
    {
        root = root->left;
        while ( root->right ) {
            root = root->right;
        }
        return root->val;
    }
    
    void fourcases ( TreeNode* &root)
    {
        if ( !root->left && !root->right ) {
            root = nullptr; 
        }
        else if ( root->left && !root->right ) {
            root = root->left;
        }
        else if ( !root->left && root->right ) {
            root = root->right;
        }
        else { // root->left && root->right 
            int value = inorderPredecssor(root);
            root->val = value;
            deleteNode(root->left, value);
        }
    }
    
    TreeNode* deleteNode ( TreeNode* &root, int key)
    {
        if ( !root ) {
            return root;
        }    
        if ( key < root->val ) {
            deleteNode(root->left, key);
        }
        else if ( key > root->val ) {
            deleteNode(root->right, key);
        }
        else { // key == root->val
            fourcases(root);
        }
        return root;
    }
};