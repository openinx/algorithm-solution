#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std ;
const int maxn = 100005 ;

struct Edge{
     int y , next ;
};
int es ;
int c[maxn] , range[maxn][2] , hd[maxn] , N ; 
Edge e[2*maxn] ;

inline int lowbit(int x){ return x&(-x) ;}

void add(int x ,int d){
     for( ; x <=N ; x+=lowbit(x)) c[x]+=d ;
}

int sum(int x ){
    int res = 0 ; 
    for( ; x > 0 ; x-=lowbit(x)) res +=c[x] ; 
    return res ; 
} 

int idx = 0 , vis[maxn] , state[maxn] ;

void dfs(int x ){
     int i , y ;
     range[x][0] = range[x][1] =vis[x]= ++idx ;
     for(i = hd[x] ; i!=-1 ; i=e[i].next )
        if(!vis[y=e[i].y]){
               dfs(y);
               range[x][0] = min(range[x][0] , range[y][0]);
               range[x][1] = max(range[x][1] , range[y][1]);
        }
     //printf("vertex[%d] is in range[%d , %d]\n" ,x , range[x][0] , range[x][1]);
}

int main(){
    int i , x , y , cmds , branch ;
    char cmd[5] ;
    scanf("%d" ,&N);
    memset(vis , 0 ,sizeof(vis)); memset(c , 0 ,sizeof(c));  memset(hd ,-1 ,sizeof(hd));
    es = 0 ; 
    for(i = 1 ; i < N ; ++ i){
         scanf("%d%d" ,&x ,&y);
         e[es].y = y , e[es].next = hd[x] , hd[x] = es ++ ; 
         e[es].y = x , e[es].next = hd[y] , hd[y] = es ++ ;
    }   
    idx = 0 ;   dfs(1);
    for(i = 1 ; i<=N ; ++i) { 
          add(i , +1) ; state[i] = 1 ;
    }
    scanf("%d" , &cmds);
    while(cmds--){
          scanf("%s%d" ,cmd , &branch);
          if(cmd[0]=='Q'){
                printf("%d\n" , sum(range[branch][1]) - sum(range[branch][0]-1));
          }else{
                if(state[branch]==1){
                     state[branch] = 0 ;  
                     add(vis[branch] , -1);
                }else{
                     state[branch] = 1 ;
                     add(vis[branch] , +1);
                }
          }
    } 
    //system("pause");
    return 0 ;
}


