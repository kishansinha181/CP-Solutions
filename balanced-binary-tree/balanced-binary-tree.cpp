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
    
    
    class Pair2 {
public:
	int height;
	bool isBalanced;
};

Pair2 isTreeHeightBalanced(TreeNode *root) {
	Pair2 p;
	if (root == NULL) {
		p.height = 0;
		p.isBalanced = true;
		return p;
	}
	Pair2 p1 = isTreeHeightBalanced(root->left);
	Pair2 p2 = isTreeHeightBalanced(root->right);

	int h1 = p1.height;
	int h2 = p2.height;

	p.height = 1 + max(h1, h2);

	if (abs(h1 - h2) <= 1 && p1.isBalanced && p2.isBalanced)
		p.isBalanced = true;
	else
		p.isBalanced = false;

	return p;


}
    bool isBalanced(TreeNode* root) {
        Pair2 p = isTreeHeightBalanced(root);
        return p.isBalanced;
    }
};