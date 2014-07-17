/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void addNode(ListNode* &head, ListNode* &tail, ListNode* p){
		if(head == NULL){
			head = tail = p ;
		}else{
			tail->next = p ; tail = p ;
		}
	}
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *head=NULL , *tail=NULL, *p1 = l1, *p2 = l2; 
    	while(p1 && p2){
    		if(p1->val < p2->val){
    			addNode(head, tail, p1);
    			p1 = p1->next;
    		}else{
    			addNode(head, tail, p2);
    			p2 = p2->next;
    		}
    	}
    	while(p1) {addNode(head, tail, p1); p1=p1->next; }
    	while(p2) {addNode(head, tail, p2); p2=p2->next; }
    	if(tail) tail->next = NULL;
    	return head;
    }
};