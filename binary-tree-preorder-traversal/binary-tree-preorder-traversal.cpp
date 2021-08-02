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
    vector<int> ans;
    
    void helper( TreeNode *root){
               
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> state;
        st.push(root);
        
        while(!st.empty()){
            TreeNode * curr = st.top();
            if(curr == NULL){st.pop(); continue;}
            if(state[curr] == 1)
                st.push(curr->left);
            else if(state[curr] == 0)
                ans.push_back(curr->val);
            else if(state[curr] ==2)
                st.push(curr->right);
            else
                st.pop();
            state[curr]++;
        }
            
    }
    

    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};