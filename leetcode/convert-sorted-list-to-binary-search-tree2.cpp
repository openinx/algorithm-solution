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

	TreeNode* buildTree(ListNode *list){
		if(list == NULL ) return NULL;
		if(list->next == NULL) return TreeNode(list->val);
		ListNode *p1, *p2, *mid, *prevHead = new ListNode(0); 
		prevHead->next = list;
		for(p1=p2=prevHead; p2 && p2->next && p2->next->next; p1=p1->next, p2=p2->next->next);
		mid = p1->next;
		p1->next = NULL;
		TreeNode *left = buildTree(p1 == prevHead ? NULL: list);
		TreeNode *right = buildTree(mid->next);
		TreeNode *root = new TreeNode(mid->val);
		root->left = left;
		root->right = right;
		delete prevHead;
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
        return buildTree(head);
    }
};