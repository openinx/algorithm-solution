#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode{
    int val ; 
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<TreeNode*> current, next ;
    	vector< vector<int> > result ;
    	int leftToRight = 1 ; 
    	if(root == NULL ) return result; 
    	current.push_back(root);
    	vector<int> v ; v.push_back(root->val); result.push_back(v);
    	while(!current.empty()){
    		TreeNode *node = current.back(); current.pop_back(); 
    		if(node){
    			if(leftToRight){
    				if(node->left)  next.push_back(node->left);
    				if(node->right) next.push_back(node->right);
    			}else{
    				if(node->right) next.push_back(node->right);
    				if(node->left) next.push_back(node->left);
    			}
    		}    	
    		if(current.empty()){
    			if(next.empty())
    				break;
    			leftToRight = !leftToRight;
    			swap(current, next);
    			vector<int> vv;
                for(int i = current.size()-1; i>=0; --i)
                    vv.push_back(current[i]->val);
    			result.push_back(vv);
    		}
    	}
    	return result;
    }
};


int main(){
   return 0 ; 
}