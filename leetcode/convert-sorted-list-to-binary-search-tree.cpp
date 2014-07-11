/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

	TreeNode* buildTree(ListNode * &list, int start, int end){
		if(start > end ) return NULL ;
		int mid =  (start + end ) >> 1;
		TreeNode* left = buildTree(list, start, mid-1);
		TreeNode* root = new TreeNode(list->val);
		root->left = left;  
		list=list->next;
		TreeNode *right = buildTree(list, mid+1, end);
		root->right = right;
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0 ; 
        for(ListNode *p = head ; p != NULL ; p=p->next , ++n);
       	if(n == 0) return NULL;
        return buildTree(root, 0, n-1);
    }
};