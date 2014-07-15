#include <iostream>
#include <stdlib.h>
#include <algorithm>

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

	void insertHead(ListNode* &head, ListNode* &tail, ListNode *p){
		if(head == NULL ){
			tail = head = p ; 
		}else{
			p->next = head; head = p;
		}
	}

    ListNode* reverseKGroup(ListNode *head, int k) 	{
    	if( k <= 1) return head;
    	ListNode *preHead, *p, *front, *back, *next, *temp;
    	preHead = new ListNode(0);
    	preHead->next = head;
    	front = preHead;
    	back = preHead;
    	do{
    		for(int i = 0 ;i < k && back; ++ i)
    			back = back->next;
    		if(back == NULL)  break;
    		next = back->next;
    		ListNode *chead = NULL , *ctail = NULL;
    		for(p = front->next; p && p!=next; p = temp){
    			temp = p->next;
    			insertHead(chead, ctail, p);
    		}
    		ctail->next = next;
    		front->next = chead; 
    		front = back = ctail;
    	}while(1);
    	head = preHead -> next;
    	delete preHead;
    	return head;
    }
};


int main(){
	int n , x, k ;
	while(cin >> n >> k){
		ListNode *head = NULL, *tail = NULL;
		for(int i = 0 ; i < n; ++ i){
			cin >> x ;
			ListNode *p = new ListNode(x);
			if(head == NULL){
				tail = head  = p ;
			}else{
				tail->next = p ; tail = p ;
			}
		}
		Solution sol;
		ListNode *p;
		cout << "#########################################" << endl;
		head = sol.reverseKGroup(head, k);
		for(p = head; p != NULL ; p = p ->next ){
			cout << "**** " << p->val << endl;
		}
	}
	return 0;
}