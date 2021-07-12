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
    
    void ans(bool& isDone,TreeNode* head,int& count, int k){
        if(head==NULL) return;
        if(isDone) return;
        ans(isDone,head->left,count,k);
        if(isDone) return;
        count++;
        if(count==k) {
            count=head->val;
            isDone=true;
            return;
        }
                if(isDone) return;
        ans(isDone,head->right,count,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int a=0;
        bool d=false;
        ans(d,root,a,k);
        return a;
    }
};