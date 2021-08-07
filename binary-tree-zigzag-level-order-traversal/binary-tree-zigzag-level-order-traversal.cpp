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
        bool order = false;
        if(!root)
            return {};
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            
            int s = q.size();
            while(s -- ){
                TreeNode *curr = q.front();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                q.pop();
                
                    temp.push_back(curr->val);
                
            }
            
            if(order) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            order = !order;
            
        }
        
        
        return ans;
        
        
        
    }
};