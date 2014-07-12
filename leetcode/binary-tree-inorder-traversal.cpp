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
    vector<int> inorderTraversal(TreeNode *root) {
    	stack<TreeNode*> s ;
    	unordered_set<TreeNode*> visisted;  
    	vector<int> ret ; 
    	if(root == NULL ) return ret;
    	s.push(root); 
    	while(!s.empty()){
    		TreeNode *cur = s.top(); s.pop();
    		if(visisted.find(cur) != visisted.end()){
    			ret.push_back(cur->val);
    		}else{
    			visisted.insert(cur);
    			if(cur->right) s.push(cur->right);
    			s.push(cur);
    			if(cur->left) s.push(cur->left);
    		}
    	}
    	return ret;
    }
};