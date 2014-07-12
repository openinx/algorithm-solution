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

    void deleteNodes(ListNode *p, ListNode *end){
        while(p!=end){
            ListNode *next =  p->next ; 
            delete p; 
            p = next; 
        }
    }
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL ) return head; 
        ListNode *prevHead, *p1, *p2, *prev1, *prev2, *next;
        prevHead = new ListNode(0); 
        prevHead->next = head ; 
        for(prev1 = prevHead; prev1->next!=NULL; prev1=next){
            p1 = prev1->next ; 
            if(p1 == NULL ) break;
            p2 = p1->next ; 
            for(; p2 && p2->val == p1->val ; p2=p2->next);
            if(p1->next != p2){
                prev1->next = p2;
                deleteNodes(p1, p2);
                next = prev1; 
            }else
                next = prev1->next; 
        }
        head = prevHead->next; 
        delete prevHead;
        return head;
    }
};