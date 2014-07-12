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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL || head->next == NULL ) return head; 
    	ListNode *p , *prev, *next;
    	for(p = head ; p !=NULL ; p=next){
    		next = p->next ; 
    		if(next != NULL ){
    			if(p->val == next->val){
    				p->next = next->next; 
    				delete next ;
    				next = p;
    			}
    		}
    	}
    	return head;
    }
};