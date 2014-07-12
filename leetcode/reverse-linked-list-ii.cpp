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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       ListNode *prevHead = new ListNode(0) ; 
       ListNode *prev1, *prev2, *p1, *p2, *newhead=NULL, *next, *p2next, *tail=NULL;
       prevHead->next = head ; 
       prev1 = prevHead ; 
       for(int i = 1 ; i < m ; ++ i) prev1=prev1->next;
       prev2 = prev1 ; 
       for(int i = 0 ; i < n -m ; ++ i) prev2=prev2->next;
       p2 = prev2->next ;  p2next = p2->next; 
       for(p1=prev1->next; p1!=NULL && p1!=p2next ; p1=next){
       		next = p1->next;
       		if(newhead==NULL){
       			newhead = tail = p1 ;
       			p1->next = NULL ; 
       		}else{
       			p1->next = newhead ; 
       			newhead = p1 ; 
       		}
       	}
       	prev1->next = newhead ; 
       	tail->next = p2next;
       	if(prev1 == prevHead){
       		head = newhead;
       	}
       	delete prevHead;
       	return head; 
    }
};