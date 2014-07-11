#include <iostream>
#include <string>
#include <stdio.h>
#include <string>

using namespace std;


struct TreeNode{
	int val;
	TreeNode *left; 
	TreeNode *right;
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
	typedef TreeNode* TreeNodePtr;

	void preTraval(TreeNode *root, TreeNodePtr *head, TreeNodePtr *tail){
		if(root->left==NULL && root->right==NULL){
			*head = *tail = root ; 
			return;
		}
		TreeNodePtr lhead = NULL , rhead = NULL , ltail = NULL , rtail = NULL ; 
		if(root->left){
			preTraval(root->left, &lhead, &ltail) ;
			*head = lhead ;
			*tail = ltail ; 
		}
		if(root->right){
			preTraval(root->right, &rhead, &rtail);
			if(*head == NULL)
				*head = rhead ; 
			else
				(*tail)->right = rhead ; 
			*tail = rtail ; 
		}
		root->right = *head; 
		root->left = NULL ;
		*head = root; 
	}
    void flatten(TreeNode *root) {
    	TreeNodePtr head = NULL , tail = NULL ;
    	if(root != NULL )
	    	preTraval(root, &head, &tail);
    }
};


int main(){
	Solution sol ; 
	TreeNode * a = new TreeNode(1);
	TreeNode * b = new TreeNode(2);
	TreeNode * c = new TreeNode(3);
	TreeNode * d = new TreeNode(4);
	TreeNode * e = new TreeNode(5);

	a->left = b ; 
	b->left = c ; 
	b->right = d ; 
	c->left = e ; 

	sol.flatten(a);
	for(TreeNode *p = a ; p!=NULL; p = p->right){
		cout << "#### :" << p->val << endl ;
	}
	return 0 ;
}