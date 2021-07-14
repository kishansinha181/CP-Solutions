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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        bool order = true;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            while(s--){
            TreeNode* node = q.front();
            temp.push_back(node->val);
            q.pop();
            
            if(node->left){
                q.push(node->left);
                
                
            }
            if(node->right){
                q.push(node->right);
               
                
            }
            }
            
            if(!order)
                reverse(temp.begin(), temp.end());
            order = !order;
            
            ans.push_back(temp);
        }
        
        return ans;
        
        
        
    }
};