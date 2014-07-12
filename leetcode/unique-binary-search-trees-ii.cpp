#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode{
	int val; 
	TreeNode *left ; 
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

	vector<TreeNode*> dfs(vector<int> &arr, int start, int end){
		vector<TreeNode*> result ; 
		if(start > end){
			result.push_back(NULL);
			return result;
		}
		int a , b;
		for(int i = start ; i <= end ; ++ i){
			vector<TreeNode*> lchildren = dfs(arr, start, i-1);
			vector<TreeNode*> rchildren = dfs(arr, i+1, end);
			for(a = 0 ; a < lchildren.size() ; ++ a){
				for(b = 0 ; b < rchildren.size(); ++ b){
					TreeNode *root = new TreeNode(arr[i]) ; 
					root->left = lchildren[a];
					root->right = rchildren[b];
					result.push_back(root);
				}
			}
		}
		return result;
	}

    vector<TreeNode *> generateTrees(int n) {
    	vector<int> arr ; 
    	for(int i = 1 ; i <=n ; ++ i)
    		arr.push_back(i);
    	return dfs(arr, 0 , arr.size() - 1 );
    }
};


int main(){
	Solution sol ;
	vector<TreeNode*> v = sol.generateTrees(1) ; 
	cout << v.size() << endl ;
	return 0; 
}