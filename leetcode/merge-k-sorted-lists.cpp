#include <iostream>
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

	void addElem(ListNode* &head, ListNode* &tail, ListNode *p){
		if(tail == NULL ){
			head = tail = p ;
		}else{
			tail->next = p; tail = p;
		}
	}
	
	ListNode *mergeTwo(ListNode *a , ListNode *b){
		ListNode *head = NULL , *tail = NULL , *next; 
		while(a && b){
			if(a->val < b->val ){
				next = a->next;
				a->next = NULL;
				addElem(head, tail, a);
				a = next;
			}else{
				next = b->next;
				b->next = NULL;
				addElem(head, tail, b);
				b = next;
			}
		}
		if(a == NULL ) addElem(head, tail, b);
		if(b == NULL ) addElem(head, tail, a);
		return head;
	}

    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	ListNode *head = NULL;
    	for( int i = 0 ; i < lists.size(); ++ i)
    		head = mergeTwo(head, lists[i]);
    	return head;
    }
};


void addElem(ListNode* &head, ListNode* &tail, ListNode *p){
	if(tail == NULL ){
		head = tail = p ;
	}else{
		tail->next = p; tail = p;
	}
}

int main(){
	int n, k, j, x; 
	while(cin >> n){
		vector<ListNode*> lists;
		for(int i = 0 ; i < n ; ++ i){
			cin >> k; 
			ListNode *head = NULL , *tail = NULL ;
			for(int j = 0 ; j < k ; ++ j){
				cin >> x;
				ListNode *p = new ListNode(x);
				addElem(head, tail, p);
			}
			lists.push_back(head);
		}
		Solution sol;
		ListNode *head = sol.mergeKLists(lists);
		for(ListNode *p = head; p != NULL ; p = p->next){
			cout << "######: " << p->val << endl;
		}
	}
	Solution sol; 

}