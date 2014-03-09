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

const int MAXN = 100005 ; 
const int MAXE = 400004 ;

struct Edge{
    int y , next , c ;
};
int  hd[MAXN] , es , N , E ; 
Edge e[MAXE] ;

void addEdge(int x ,int y , int c){
     e[es].y = y , e[es].c = c ,  e[es].next = hd[x] , hd[x] = es ++ ; 
     e[es].y = x , e[es].c = c ,  e[es].next = hd[y] , hd[y] = es ++ ; 
}

int que[MAXN] , head ,tail , toSrc[MAXN] , toDes[MAXN] , vis[MAXN] , ans[MAXN] ;

void bfs(int s , int *dist ){
     head = tail = 0 ; 
     for(int i = 0 ; i < N ; ++ i) dist[i] = -1 ;  
     dist[s] = 0 ;  que[tail ++ ] = s ; 
     while(head < tail ){
          int x = que[head ++ ] ; 
          for(int i = hd[x] ; i!=-1 ; i = e[i].next ){
               int y = e[i].y ; 
               if(dist[y] == -1){
                     dist[y] = dist[x] + 1 ;            
                     que[tail ++ ] = y ;
               }
          }
     }
}

int main(){
    int i , j , x , y , c , L , R , d ;
    scanf("%d%d" , &N , &E);
    es = 0 ; 
    for(i = 0 ; i < N ; ++ i) hd[i] = -1 ;
    for(i = 0 ; i < E ; ++ i){
          scanf("%d%d%d" , &x , &y , &c) ;
          --x , --y ; 
          addEdge(x , y , c);
    }
    bfs(0 , toSrc);
    bfs(N-1 , toDes);
    int length = toSrc[N-1];   //cout << "length:=" << length << endl ;
    memset(vis , 0 , sizeof(int) * (N+1) );  
    vis[0] = 1 ;
    head = tail = 0 ; que[tail ++ ] = 0 ; 
    for(d = 0 ; d < length ; ++ d){
            int minColor = 0x7FFFFFFF ; 
            L = head ; R = tail ; 
            while(L < R ){
                  x = que[L ++ ] ; 
                  for(i = hd[x] ; i!=-1 ; i=e[i].next ){
                       y = e[i].y ; 
                       if(toSrc[y]==toSrc[x]+1 && toSrc[y] + toDes[y]==length)
                           minColor = min(minColor , e[i].c );
                  }
            }
            L = head ; R = tail ; 
            
            //cout << "minColor:=" << minColor << endl ;
            
            while(L < R ){
                  x = que[L ++ ] ; 
                  for(i = hd[x] ; i!=-1 ; i=e[i].next ){
                       y = e[i].y ; 
                       if(toSrc[y]==toSrc[x]+1 && toSrc[y]+toDes[y]==length){
                               if(!vis[y] && minColor == e[i].c ){
                                   que[tail++] = y , vis[y] = 1 ;
                                   //cout << "y:=" << y << endl ;
                               }
                       }
                  }
            }
            head = R ; 
            ans[d] = minColor ;
    }
    printf("%d\n" , length);
    printf("%d"   , ans[0]);
    for(i = 1 ; i < length ; ++ i)
        printf(" %d" , ans[i]);
    printf("\n");
    //system("pause");
    return 0 ;
}
