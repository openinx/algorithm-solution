#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
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
 	TreeNode *right;
 	TreeNode(int x): val(x), left(NULL), right(NULL){}
 };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	vector<int> result;
    	stack<TreeNode*> s; 
    	TreeNode *i, *p; 
    	if(root == NULL) return result;
    	s.push(root); i = s.top();
    	do{
    		while(i->left || i->right){
    			while(i->left){
    				s.push(i->left); 
    				i=i->left;
    			}
    			if(i->right==NULL)
    				break;
    			s.push(i->right);
    			i = i->right ;
    		}
    		i = s.top(); s.pop();
    		result.push_back(i->val); 
    		if(s.empty()) break;
    		p = s.top(); 
    		while((p->left==i && !p->right) || (p->right==i))	{
    			result.push_back(p->val); s.pop(); 
    			if(s.empty()) break;
    			i = p ;
    			p = s.top(); 
    		}
    		if(s.empty()) break;
    		i = p->right; s.push(i);
    	}while(1);
    	return result;
    }
};


int main(){
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
	vector<int> v = sol.postorderTraversal(root);
	for(int i = 0 ;i < v.size(); ++ i)
		cout << v[i] << " " << endl ;
	return 0;
}