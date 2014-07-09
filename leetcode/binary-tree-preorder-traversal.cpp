#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std; 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode{
 	int val ; 
 	TreeNode *left ;
 	TreeNode *right ; 
 	TreeNode(int x): val(x), left(NULL), right(NULL){}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
    	vector<int> out;
    	stack<TreeNode*> s ; 
    	if(root==NULL) return out;
    	s.push(root);
    	while(!s.empty()){
    		TreeNode *cur = s.top(); s.pop() ; 
    		out.push_back(cur->val);
    		if(cur->right) s.push(cur->right);
    		if(cur->left) s.push(cur->left);
    	}
    	return out;
    }
};

int main(int argc, char ** args){
	Solution sol ; 
	TreeNode * root  ; 
	TreeNode *a = new TreeNode(1);
	root = a ; 
	TreeNode *b = new TreeNode(2);
	a->left = b ;
	TreeNode *c = new TreeNode(3);
	a->right = c ;
	TreeNode *d = new TreeNode(4);
	b->right = d ;
	vector<int> v = sol.preorderTraversal(root);
	for(int i = 0 ;i < v.size(); ++ i)
		cout << v[i] << " " << endl ;
	return 0;	
}