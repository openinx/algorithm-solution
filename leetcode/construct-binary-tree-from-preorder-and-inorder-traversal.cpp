/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* build(vector<int> &preorder, int sp, int ep, vector<int> &inorder, int si, int ei){
		if(sp > ep || si > ei ) return NULL;
		int i, root_val = preorder[sp], root_idx;
		for(i = si ; i <= ei && inorder[i]!=root_val; ++ i);
		root_idx=i;
		TreeNode *root = new TreeNode(root_val);
		root->left = build(preorder,sp+1, sp+root_idx-si, inorder, si, root_idx-1);
		root->right = build(preorder,sp+root_idx-si+1, ep, inorder, root_idx+1, ei);
		return root; 
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};