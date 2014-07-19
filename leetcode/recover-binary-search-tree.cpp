#include <iostream>
#include <cstdio>
#include <algorithm>

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

	void traval(TreeNode *root){
		if(root == NULL) return;
		traval(root->left);
		if(prev == NULL){
			prev = root;
		}else{
			if(prev->val > root->val){
				if(first == NULL){
					first = prev;
				}
				second = root;
			}
			prev = root;
		}
		traval(root->right);
	}

    void recoverTree(TreeNode *root) {
    	first = second = prev = NULL;
    	traval(root);
    	if(first != NULL ){
    		swap(first->val, second->val);
    	}
    }
private:
	TreeNode *first,  *second, *prev;
};


void dfs(TreeNode * root, int &index){
	if(root == NULL) return;
	dfs(root->left, index);
	cout << "## " << (++index) << ":"<< root->val << endl ; 
	dfs(root->right, index);
}

void test1(){
	int n , x ; 
	TreeNode *a1, *a3, *a6, *a8, *a7, *a4, *a10 , *a14, *a13;
	a1 = new TreeNode(1);
	a3 = new TreeNode(3);
	a6 = new TreeNode(6);
	a8 = new TreeNode(8);
	a7 = new TreeNode(7);
	a4 = new TreeNode(4);
	a10 = new TreeNode(10);
	a14 = new TreeNode(14);
	a13 = new TreeNode(13);
	a4->left = a3 ; 
	a4->right = a10;
	a3->left = a1 ;
	a3->right = a6; 
	a6->left = a8 ; 
	a6->right = a7 ; 
	a10->right = a14;
	a14->left = a13;
	int index = 0 ; 
	dfs(a4, index);

	Solution sol;
	sol.recoverTree(a4);

	index = 0;
	dfs(a4, index);
}


void test2(){
	TreeNode *a0, *a1;
	a0 = new TreeNode(0);
	a1 = new TreeNode(1);
	a0->left = a1;

	Solution sol;
	sol.recoverTree(a0);

	int index = 0;
	dfs(a0, index);
}

int main(){
	test2();
}