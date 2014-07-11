#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 


struct TreeNode{
	int val ; 
	TreeNode *left ; 
	TreeNode *right ; 
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

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

	TreeNode* build(vector<int> &inorder, int si, int ei, vector<int> &postorder, int sp, int ep){
		if(si > ei || sp > ep) return NULL ;
		int root_val = postorder[ep], root_idx;
		for(int i = si ; i <= ei ; ++ i){
		 	if(inorder[i] == root_val){
		 		root_idx = i ; break; 
		 	}
		}
		TreeNode* root = new TreeNode(root_val); 
		root->left = build(inorder, si, root_idx-1, postorder, sp, sp + root_idx - si - 1) ; 
		root->right = build(inorder, root_idx+1, ei, postorder, sp + root_idx - si, ep-1); 
		return root;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};


void traval(TreeNode *root){
	if(root == NULL ) return ; 
	//cout << root->val << endl ;
	if(root->left)
		traval(root->left);
	if(root->right)
		traval(root->right);
	cout << root->val << endl ;
}


int main(){
	int in[] = {1, 2} , out[] = {2, 1}; 
	vector<int> inorder(in, in + 2), postorder(out, out+2); 
	Solution sol ; 
	TreeNode *root= sol.buildTree(inorder, postorder); 
	traval(root);
	return 0; 
}