#include<iostream>

using namespace std;

struct TreeLinkNode{
	int val ; 
	TreeLinkNode *left, *right, *next ; 
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	TreeLinkNode *head=root, *prev, *p, *firstChild; 
    	while(head !=NULL ){
    		firstChild = NULL;
    		for(prev=NULL, p=head; p!=NULL; p=p->next){
    			if(prev!=NULL){
    				if(p->left)
    					prev->next = p->left;
    				else if(p->right)
    					prev->next = p->right;
    			}
    			if(p->left && p->right){
    				p->left->next = p->right; 
    				prev = p->right;
    				firstChild = (NULL==firstChild ? p->left: firstChild);
    			}else if(p->right){
    				prev = p->right;
    				firstChild = (NULL==firstChild ? p->right: firstChild);
    			}else if(p->left){
    				prev=p->left;
    				firstChild = (NULL==firstChild ? p->left: firstChild);
    			}
    		}
    		head = firstChild;
    	}
    }
};


int main(){
	TreeLinkNode *root = new TreeLinkNode(0) ; 
	Solution sol ;
	sol.connect(root) ; 
}