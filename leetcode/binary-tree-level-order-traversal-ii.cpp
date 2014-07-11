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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector< vector<int> > result ; 
    	if(root == NULL ) return result;
    	vector<int> v ; 
    	queue<TreeNode*> q; 
    	TreeNode *current, *child; 
        q.push(root); 
        q.push(NULL);
        while(!q.empty()){
        	current = q.front() ; q.pop();
        	if(current == NULL ){
        		result.push_back(v);
        		v = vector<int>();
        		if(q.empty()) break; 
        		q.push(NULL);
        	}else{
        		v.push_back(current->val);
        		if(current->left) 
        			q.push(current->left);
        		if(current->right)
        			q.push(current->right);
        	}
        }
        reverse(result.begin(), result.end());
        return result;
    }
};