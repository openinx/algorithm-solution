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

	TreeNode * build(vector<int> &num, int lidx, int ridx){
		if(lidx > ridx) return NULL;
		int mid = (lidx + ridx) >> 1 ;
		TreeNode *p = new TreeNode(num[mid]), *left=NULL, *right=NULL;
		if(lidx == ridx) return p ; 
		if(lidx < mid ){
			left = build(num, lidx, mid-1);
		}
		if(mid < ridx){
			right = build(num, mid+1, ridx);
		}
		p->left = left ; 
		p->right = right;
		return p ; 
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
    	return build(num, 0, num.size()-1);
    }
};