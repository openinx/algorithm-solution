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

	bool isBST(TreeNode *root, TreeNode* &max, TreeNode* &min){
		max = min = root; 
		if(root->left==NULL && root->right==NULL){
			return true;
		}
		TreeNode *lmax, *rmin ; 
		if(root->left){
			if(!(isBST(root->left, lmax, min) && (lmax->val < root->val)))
				return false;
		} 
		if(root->right){
			if(!(isBST(root->right, max, rmin) && (root->val < rmin->val)))
				return false;
		}
		return true;
	}

    bool isValidBST(TreeNode *root) {
    	if(root == NULL ) return true;
    	TreeNode *max, *min ; 
    	return isBST(root, max, min);
    }
};