#include <iostream>
#include <vector>

using namespace std; 


struct TreeNode {
	int val ; 
	TreeNode *left; 
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

	void dfs(TreeNode *root, int sum, int now, vector<int> &current, vector< vector<int> > &result){
		now += root->val ; 
		current.push_back(root->val);
		if(root->left == NULL && root->right==NULL){
			if(sum == now){
				vector<int> ret(current) ; 
				result.push_back(ret);
			}
		}else{
			if(root->left)
				dfs(root->left, sum, now, current, result);
			if(root->right)
				dfs(root->right, sum, now, current, result);
		}
		current.pop_back();
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector< int > current ; 
        vector< vector<int> > result; 
    	if(root != NULL ) 
	        dfs(root, sum, 0, current , result ); 
        return result; 
    }
};


int main(){
	Solution sol ;
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	a->left = b ; 
	vector< vector<int> > result = sol.pathSum(a, 0); 
	cout << "#####################" << endl ;
	for(int i = 0 ; i < result.size() ; ++ i){
		cout << "[";
		for(int j = 0 ; j < result[i].size() ; ++ j)
			cout << " " << result[i][j];
		cout << "]" << endl ;
	}
	return 0;
}