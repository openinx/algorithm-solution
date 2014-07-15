#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};


class classcmp{
public:
	bool operator() (const ListNode* a, const ListNode* b)const{
		return a->val > b->val ;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void addElem(ListNode* &head, ListNode* &tail, ListNode *p){
	if(tail == NULL ){
		head = tail = p ;
	}else{
		tail->next = p; tail = p;
	}
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
    	ListNode* head = NULL, *tail = NULL;
    	priority_queue<ListNode*, vector<ListNode*>, classcmp> que ;
    	for(int i = 0 ; i < lists.size(); ++ i) 
    		if(lists[i] != NULL ) que.push(lists[i]);
    	while(!que.empty()){
    		ListNode* p = que.top(); que.pop();
    		if(p->next != NULL)
    			que.push(p->next);
			addElem(head, tail, p);
    	}
    	if(tail)
    		tail->next = NULL;
    	return head;
    }
};

void show(ListNode *p){
	cout << "####: ";
	for(; p!=NULL; p=p->next)
		cout << " " << p->val ;
	cout << endl;
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
		/*for(ListNode *p = head; p != NULL ; p = p->next){
			cout << "******: " << p->val << endl;
		}*/
	}
}