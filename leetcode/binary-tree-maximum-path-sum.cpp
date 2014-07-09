#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct TreeNode{
    int val ; 
    TreeNode *left;
    TreeNode *right; 
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    static const int MINV_VAL = -(1<<28);
    int solve(TreeNode *root, int *rootval){ 
        if(root->left==NULL && root->right == NULL ) { 
            *rootval = root->val ;
            return root->val;
        }
        int maxval = MINV_VAL, lt=MINV_VAL, rt=MINV_VAL, lt1 = MINV_VAL, rt1 = MINV_VAL;
        *rootval = MINV_VAL;
        if(root->left){
            lt = solve(root->left, &lt1); 
            *rootval = max(*rootval, max(root->val, root->val + lt1)) ;
        }
        if(root->right){
            rt = solve(root->right, &rt1);
            *rootval = max(*rootval, max(root->val, root->val + rt1));
        }
        //cout << "lt: " << lt << " rt:" << rt << " rootval:" << *rootval << endl ;
        return max( max(max(lt, rt), *rootval), lt1 + root->val + rt1 ) ;
    }

    int maxPathSum(TreeNode *root) {
        int t = MINV_VAL;
        return solve(root, &t);
    }
};

int main(){
    TreeNode *a = new TreeNode(1) ;
    TreeNode *b = new TreeNode(2) ; 
    TreeNode *c = new TreeNode(-3) ; 
    a->left  = b ; 
    a->right = c ; 
    Solution sol ; 
    cout << "####: " << sol.maxPathSum(a) << endl ;
    return 0; 
}