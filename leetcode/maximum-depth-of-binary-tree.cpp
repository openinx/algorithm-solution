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
    int maxDepth(TreeNode *root) {
    	if(root==NULL) return 0 ; 
    	int depth = 1 ; 
    	if(root->left) depth = max(maxDepth(root->left) + 1, depth) ;
    	if(root->right) depth = max(maxDepth(root->right) + 1, depth);
    	return depth;
    }
};