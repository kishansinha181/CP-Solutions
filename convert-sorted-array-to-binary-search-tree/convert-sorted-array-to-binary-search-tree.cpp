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
    
    TreeNode *convert(vector<int> arr, int s, int e){
        if(s>e){
            return NULL;
            
        }
        int mid = s + (e - s)/2;
        
        TreeNode *root = new TreeNode(arr[mid]);
        
        root->left = convert(arr,s,mid-1);
        root->right = convert(arr,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums, 0, n-1);
    }
};