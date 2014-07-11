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
	bool dfs(TreeNode *root, int sum, int now, vector<int> &current){
		now += root->val ; 
		current.push_back(root->val);
		int answer = 0 ; 
		if(root->left == NULL && root->right == NULL ){
			answer = (sum == now) ; 
		}else{
			if(answer == 0 && root->left && dfs(root->left, sum, now, current)) 
				answer = 1 ;
			if(answer == 0 && root->right && dfs(root->right, sum, now, current))
				answer = 1 ; 
		}
		current.pop_back();
		return answer;
	}
    bool hasPathSum(TreeNode *root, int sum) {
        vector<int> current ; 
        if(root!=NULL)
        	return dfs(root, sum, 0, current);
        return 0;
    }
};