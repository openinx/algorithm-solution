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
    vector<vector<int> > levelOrder(TreeNode *root) {
    	queue<TreeNode*> q ;
    	vector<vector<int> > result ;
    	vector<int> current ; 
    	if(root == NULL ) return result;
    	q.push(root); q.push(NULL);
    	while(!q.empty()){
    		TreeNode *node = q.front() ; q.pop() ; 
    		if(node == NULL){
    			result.push_back(current);
    			if(q.empty()) 
    				break;
    			current = vector<int>();
    			q.push(NULL);
    		}else{
    			current.push_back(node->val);
    			if(node->left) q.push(node->left);
    			if(node->right) q.push(node->right);
    		}
    	}
    	return result;
    }
};