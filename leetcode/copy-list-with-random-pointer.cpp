#include<algorithm>
#include<vector>
#include<iostream>

using namespace std ;

struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p, *newnode, *newhead, *newtail, *next; 
        for(p = head ; p!=NULL; p=p->next->next){
            newnode = new RandomListNode(p->label);
            newnode->next = p->next ; 
            p->next = newnode ; 
        }
        for(p = head ; p!=NULL; p=p->next->next){
            newnode = p->next ;
            newnode->random = p->random ? p->random->next: NULL; 
        }
        for(p = head , newhead = newtail = NULL ; p!=NULL ; p = p->next ){
            newnode = p->next ; 
            p->next = p->next->next;
            newnode->next = NULL ;
            if(newhead == NULL ){
                newhead = newtail = newnode ;  
            }else{
                newtail->next = newnode; 
                newtail = newnode;
            }
        }
        return newhead ; 
    }
};

int main(){
    RandomListNode *a = new RandomListNode(-1) ;
    a->next = NULL ;
    a->random = a ; 
    //RandomListNode *b = new RandomListNode(3)  ; 
    //RandomListNode *c = new RandomListNode(5)  ; 
    //a->next = b ; 
    //b->next = c ; 
    //a->random = c ; 
    //b->random = c ; 
    //c->random = a ; 
    Solution sol; 
    RandomListNode *head = sol.copyRandomList(a);
    for(RandomListNode *p = head ; p!=NULL ; p=p->next){
        cout << "##### " << p->label <<  endl ;
    }
    return 0 ;
}