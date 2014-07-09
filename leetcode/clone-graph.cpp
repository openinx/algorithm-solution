#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>


using namespace std;


struct UndirectedGraphNode{
    int label; 
    vector<UndirectedGraphNode *> neighbors ;
    UndirectedGraphNode(int x): label(x) {};
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *start, *p, *cur, *now, *son; 
        unordered_set<int,  UndirectedGraphNode* > dict; 
        queue<UndirectedGraphNode*> q ; 
        q.push(node) ;  
        dict[node->label] = new UndirectedGraphNode(node->label); 
        while(!q.empty()){
            cur = q.front() ; q.pop();
            p = dict[cur->label];
            for(int i = 0 ; i < cur->neighbors.size() ; ++ i){
                now = cur->neighbors[i] ; 
                if(dict.find(now->label) != dict.end()){
                    son  = *(dict.find(now->label)));
                    p->neighbors.push_back(son);
                }else{
                    son = new UndirectedGraphNode(now->label);
                    p->neighbors.push_back(son);
                    q.push(now) ; 
                }
            }
        }
    }
};

int main(){
    return 0 ;
}