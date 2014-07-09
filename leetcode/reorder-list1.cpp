#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;



struct ListNode {
	int val; 
	ListNode *next ; 
	ListNode(int x): val(x), next(NULL) {}
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
    void reorderList(ListNode *head) {
    	if(head == NULL  || head->next == NULL) return ;
    	ListNode *p, *p1, *p2, *move,  *ph, *tail, *head1, *head2, *next1, *next2; 
    	ph = new ListNode(0);
    	ph->next = head ; 
    	for(p1=p2=ph; p2->next && p2->next->next ; p1=p1->next, p2=p2->next->next);
    	head1 = head; 
    	head2 = NULL;
    	for(p=p1; p->next!=NULL;){
    		move = p->next;
    		p->next = move->next;
    		if(head2==NULL){
    			move->next = NULL;
    			head2 = move;
    		}else{
    			move->next = head2; 
    			head2 = move;
    		}
    	}
    	int move1 = 1 ; 
    	for(p1=head1, p2=head2, head=tail=NULL; p1 && p2 ; p1=next1, p2=next2){
    		next1 = p1->next;
    		next2 = p2->next;
    		p2->next = p1->next;
    		p1->next = p2;
    	}
    	for(p1=head1; p1->next!=NULL; p1=p1->next);
    	if(p2){
    		p1->next = p2; p2->next;
    	}
    	head = head1;
    	delete ph;
    }
};

int main(){
	Solution sol ; 
	int n, x ; 
	ListNode *p ;
	while(cin >> n ){
		ListNode *head = NULL ; 
		for(int i = 0 ;i < n ; ++ i){
			cin >> x ;
			p = new ListNode(x);
			if(head == NULL ){
				head = p;
			}else{
				p->next = head ; 
				head = p ;
			}
		}
		sol.reorderList(head);
		show(head);
	}
	return 0 ;
}