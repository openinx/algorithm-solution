#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <vector>

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
    ListNode *rotateRight(ListNode *head, int k) {
    	int len = 0;
    	ListNode *p1, *p2, *p, *prevHead;
    	prevHead = new ListNode(0); 
    	prevHead->next = head;
    	for(p=head; p!=NULL; p=p->next, ++len);
    	if(len <= 1 || k % len == 0) return head;
    	k %= len;
    	for(p2=prevHead; k>0 && p2; p2=p2->next, --k);
    	assert (p2 != NULL);
    	for(p1=prevHead; p2->next != NULL; p1=p1->next, p2=p2->next);
    	p2->next = prevHead->next;
    	prevHead->next = p1->next;
    	p1->next = NULL;
    	head = prevHead->next;
    	delete prevHead;
    	return head;
    }
};

int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	a->next = b;
	b->next = c;
	Solution sol;
	for(ListNode *p = sol.rotateRight(a, 1); p != NULL; p=p->next){
		cout << p->val << endl;
	}
	return 0;
}