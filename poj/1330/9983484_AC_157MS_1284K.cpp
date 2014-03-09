#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

class LeastCommonAncestor{
      const static int MAXN = 10005 ; 
      bool visit[MAXN] ;
      vector<int>  tree[MAXN] , ques[MAXN] ;
      int father[MAXN] , rank[MAXN] , ancestor[MAXN];
      //disjoint set base function.
      int find(int n){
              return father[n]==n ? n : father[n]=find(father[n]);
      }
      int merge(int x ,int y){
              int a = find(x) , b = find(y) ;
              if(a!=b){
                    if(rank[a] <= rank[b]) 
                        father[a] = b , rank[a] += rank[b] ; 
                    else 
                        father[b] = a , rank[b] += rank[a] ; 
              } 
              return a!=b ; 
      }
public :
      void init(int n){
           int i ;
           for(i = 0 ; i < n ; ++ i){
               father[i] = i ;  rank[i] = 1 ; ancestor[i] = i ; visit[i] = 0 ; 
               tree[i].clear() ;  ques[i].clear() ;
           }
      }
      void add_edge(int x ,int y){
           tree[x].push_back(y);
      }
      void add_ques(int x ,int y){
           ques[x].push_back(y);
           ques[y].push_back(x);
      }
      void LCA(int u){
           int i ;
           for(i = 0 ; i < tree[u].size() ; ++i){
                 LCA(tree[u][i]);
                 merge(u , tree[u][i]);
                 ancestor[ find(u) ] = u ;  
           }
           visit[u] = 1 ; 
           for(i = 0 ; i < ques[u].size() ; ++ i)
             if(visit[ ques[u][i] ] == 1 ){
                      cout << ancestor[ find( ques[u][i] ) ] + 1 << endl ;
             }
      }
};

LeastCommonAncestor lca ; 

int main(){
    int cas , n , i , x , y ;
    bool isroot[10005] ; 
    cin >> cas ; 
    while(cas--){
       cin >> n ; 
       fill(isroot , isroot+n , true);
       lca.init(n) ; 
       for(i = 1 ; i < n ; ++ i){
           cin >> x >> y ; --x ; --y ;
           isroot[y]=false; 
           lca.add_edge(x , y) ; 
       }
       cin>> x >> y ; --x ; --y ; 
       lca.add_ques(x , y) ; 
       for(i = 0 ; i < n ; ++ i)
         if(isroot[i]){
               lca.LCA(i) ; 
         }
    }
    //system("pause");
    return 0 ;
}
