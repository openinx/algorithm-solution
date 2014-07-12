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

	void listInsert(ListNode* &head, ListNode* &tail, ListNode* p){
		p->next = NULL;
		if(head == NULL ){
			head = tail = p ;
		}else{
			tail->next = p ; tail = p ; 
		}
	}

    ListNode *partition(ListNode *head, int x) {
    	ListNode *lh=NULL, *lt=NULL, *rh=NULL, *rt=NULL, *p, *next;
    	for(p = head ; p!=NULL ; p = next){
    		next = p->next ; 
    		if(p->val < x)
    			listInsert(lh, lt, p);
    		else
    			listInsert(rh, rt, p);
    	}
    	if(lh){
    		lt->next = rh ; return lh; 
    	}else{
    		return rh ;
    	}
    }
};