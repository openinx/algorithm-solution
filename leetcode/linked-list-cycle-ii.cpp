#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct ListNode{
	int val ; 
	ListNode *next ; 
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
    ListNode *detectCycle(ListNode *head) {
    	if(head == NULL || head->next == NULL ) return NULL;
    	ListNode *p1, *p2, *ph;
    	ph = new ListNode(0); ph->next = head ; 
    	for(p1=p2=ph; 
    		p2 && p2->next && p2->next->next && ((p1==ph) || (p1!=ph && p1!=p2)) ; 
    		p1=p1->next, p2=p2->next->next); 
    	if(p1!=p2) return NULL;
    	for(p1=ph; p1!=p2 ; p1=p1->next, p2=p2->next);
    	return p1 ;
    }
};


int main(){
	ListNode *a , *b, *c , *d, *e, *f ; 
	a = new ListNode(0);
	b = new ListNode(1); a->next = b ;
	c = new ListNode(2); b->next = c ;
	c->next = c;
	//d = new ListNode(3); c->next = d; 
	//d->next = b;
	Solution sol ; 
	ListNode *p =sol.detectCycle(a);
	cout << "######:" << p->val << endl ;
	return 0 ;
}