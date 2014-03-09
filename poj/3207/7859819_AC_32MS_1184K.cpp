#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<memory>
#define  MAXN  1005
using namespace std ;
int  l[501] , r[501] , n , m;
bool gh[1001][1001];

bool IsCross(int x ,int y){
     return (l[y]<=l[x] && l[x]<=r[y]) != (l[y]<=r[x] && r[x]<=r[y]) ;  
}

int bcnt , top , idx , stk[MAXN] ,instk[MAXN] , dfn[MAXN] ,low[MAXN] , bel[MAXN];

void Tarjan(int x){
     int  y ; 
     dfn[x] = low[x] = ++ idx ;
     instk[x] = 1 ;  stk[top++] = x ;
     for(y = 1 ;  y<=2*m ; ++y)
        if(gh[x][y]){
              if(dfn[y] == -1){
                    Tarjan(y);
                    low[x] = min(low[x] , low[y]) ;
              }else if(instk[y]){
                    low[x] = min(low[x] , dfn[y]) ;
              }
     }
     if( dfn[x] == low[x]){
         ++ bcnt ;
         do{
               y = stk[--top] ; 
               instk[y] = 0 ;
               bel[y] = bcnt ;
         }while(y!=x);
     }
}

int main(){
    int i , j , k , ans;
    scanf("%d%d" , &n , &m);
    for(i = 1 ; i <= m ; ++i){
         scanf("%d%d" ,&l[i] , &r[i]);
         if(l[i] > r[i])  swap(l[i] , r[i]);
    }
    memset(gh , 0 , sizeof(gh));
    for(i = 1 ; i <= m ; ++ i){
           for( j = i + 1 ; j<= m ; ++j)
             if(IsCross(i , j)){   
                  gh[2*i-1][2*j] = gh[2*j-1][2*i] = 1 ;
                  gh[2*i][2*j-1] = gh[2*j][2*i-1] = 1 ;
             }
    }
    bcnt = top = idx = 0 ; 
    memset(dfn , -1 ,sizeof(dfn));
    memset(instk ,0 ,sizeof(instk));
    for(i = 1 ; i <=2*m ; ++i)
        if(dfn[i] == -1)
        Tarjan(i);
    ans = 1 ;
    for(i = 1 ; i<=m ; ++i)
        if(bel[2*i-1] == bel[2*i]){
         ans = 0 ;   break ;     
    }
    if(ans)  
         printf("panda is telling the truth...\n");
    else 
         printf("the evil panda is lying again\n");
    return 0 ;
}
