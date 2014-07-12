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

	bool bothSymmetric(TreeNode *a, TreeNode *b){
		if(a==NULL || b==NULL){
			return a == b ; 
		}
		if(a->val != b->val ) return false;
		return bothSymmetric(a->left, b->right) && bothSymmetric(a->right, b->left);
	}

    bool isSymmetric(TreeNode *root) {
    	if(root == NULL ) return true;
    	return bothSymmetric(root->left, root->right);
    }
};