#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std ;

const int MAXN = 90005 ;
const int dx[] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
const int dy[] = {1  , 2  , 2 , 1 ,-1 ,-2 , -2 , -1};

struct node{
       int x , y ;
       void init(int _x ,int _y){
            x = _x , y = _y ;
       } 
}src ,des , qSrc[MAXN] , qDes[MAXN] ;

struct type{
       int tag , step ; 
       void init(int _tag ,int _step){
            tag = _tag , step = _step ;
       }
}hash[305][305];

int n , qsHead , qsTail , qdHead ,qdTail ; 
int srcStep , desStep ;

bool isOut(node a){
     return a.x<0||a.y<0||a.x>=n||a.y>=n ;
}

int bfs(){
    if(src.x == des.x && src.y == des.y ) return 0 ; 
    node now , next ;
    int L , R , i , j ;
    for(i = 0 ; i < n ; ++ i) for(j = 0 ; j < n ; ++ j)  hash[i][j].init(-1,-1);
          
    qsHead = qsTail = 0 ;  qSrc[qsTail ++ ] = src ;  
    hash[src.x][src.y].init(0 , 0);
    
    qdHead = qdTail = 0 ;  qDes[qdTail ++ ] = des ; 
    hash[des.x][des.y].init(1 , 0); 
    
    srcStep = desStep = 0 ; 
    
    while(qsHead < qsTail || qdHead < qdTail){
          L = qsHead , R = qsTail , qsHead = qsTail ; srcStep ++ ; 
          while(L < R ){
                 now = qSrc[L ++ ] ; 
                 for(i = 0 ; i < 8 ; ++ i){
                     next.x = now.x + dx[i] ; 
                     next.y = now.y + dy[i] ; 
                     if(isOut(next) || hash[next.x][next.y].tag==0)  continue ;
                     if(hash[next.x][next.y].tag == 1)
                          return hash[next.x][next.y].step + srcStep ;
                     else {
                          hash[next.x][next.y].tag  = 0 ;
                          hash[next.x][next.y].step = srcStep ;
                          qSrc[qsTail ++ ] = next ;
                     }
                 }
          }
          L = qdHead , R = qdTail , qdHead = qdTail ; desStep ++ ; 
          while(L < R ){
                 now =qDes[L ++ ];
                 for(i = 0 ; i < 8 ; ++ i){
                      next.x = now.x + dx[i] ; 
                      next.y = now.y + dy[i] ; 
                      if(isOut(next) || hash[next.x][next.y].tag==1) continue ;
                      if(hash[next.x][next.y].tag == 0 )
                         return hash[next.x][next.y].step + desStep ;
                      else{
                         hash[next.x][next.y].tag = 1 ; 
                         hash[next.x][next.y].step = desStep ;
                         qDes[qdTail ++ ] = next ;
                      }
                 }
          }
    }
    return -1;
}

int main(){
    int acase ; 
    scanf("%d" ,&acase );
    while(acase -- ){
          scanf("%d" , &n);
          scanf("%d%d" ,&src.x , &src.y);
          scanf("%d%d" ,&des.x , &des.y);
          int res = bfs();
          cout << res << endl ;
    }  
    //system("pause");
    return 0 ;
}
