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

	void tailInsert(ListNode* &head, ListNode* &tail, ListNode *p){
		if(tail == NULL ){
			head = tail = p ; p->next = NULL ;
		}else{
			tail->next = p ; tail = p ; 
		}
	}

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	int t = 0, sum; 
    	ListNode *head=NULL, *tail=NULL, *p1, *p2 ; 
    	p1 = l1 ; p2 = l2 ;
    	while(p1 || p2){
    		sum = (p1==NULL?0:p1->val) + (p2==NULL?0:p2->val) + t; 
    		ListNode *p = new ListNode(sum % 10 ) ; 
    		t = sum / 10 ; 
    		tailInsert(head, tail, p);
    		p1 = (p1==NULL? NULL: p1->next);
    		p2 = (p2==NULL? NULL: p2->next);
    	}
    	if(t > 0 ){
    		ListNode *p = new ListNode(t) ; 
    		tailInsert(head, tail, p);
    	}
    	return head; 
    }
};