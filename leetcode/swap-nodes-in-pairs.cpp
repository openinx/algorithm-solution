#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

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
    ListNode *swapPairs(ListNode *head) {
    	if(head == NULL || head->next == NULL ) return head ; 
    	ListNode *p1, *p2, *q1, *q2, *next, *prevHead; 
    	prevHead = new ListNode(0);
    	prevHead->next = head ;
    	p1 = prevHead;
    	p2 = p1->next;
    	for(; p1->next && p2->next; ){
    		q1 = p1->next ; q2 = p2->next;
    		q1->next = q2->next;
    		q2->next = q1 ;
    		p1->next = q2;
    		if(q1 == head)
    			head = q2;
    		p1 = q1;
    		p2 = p1->next;
    	}
    	head = prevHead->next;
    	delete prevHead;
    	return head ;
    }
};

void addElem(ListNode* &head, ListNode * &tail, ListNode*p){
	if(head == NULL){
		head = tail = p ;
	}else{
		tail->next = p ; tail = p ;
	}
}

int main(){
	ListNode *head;
	int n, x; 
	while( cin >> n){
		ListNode *head = NULL, *tail=NULL;
		for(int i = 0 ;i < n ; ++ i){
			cin >> x; 
			ListNode *p = new ListNode(x);
			addElem(head, tail, p);
		}
		addElem(head, tail, NULL);
		Solution sol;
		head = sol.swapPairs(head);
		for(ListNode *p = head; p != NULL ; p = p->next){
			cout << "**** " << p->val << endl;
		}
	}
	return 0 ;
}