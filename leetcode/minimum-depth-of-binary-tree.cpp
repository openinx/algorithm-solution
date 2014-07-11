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
	int height(TreeNode *root){
		if(root  == NULL ) return 0 ;
		if(root->left==NULL && root->right==NULL) return 1;
		int lh = 0 , rh = 0 ;
		if(root->left) lh = height(root->left) ;
		if(root->right) rh = height(root->right);
		if(lh < 0 || rh < 0 || abs(lh -rh) > 1)
			return -1;
		return max(lh, rh) + 1 ;
	}
    bool isBalanced(TreeNode *root) {
    	return height(root) < 0 ? false: true;
    }
};