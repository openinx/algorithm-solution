#include<stdio.h>
#define  maxn 101 
#define  INF  (1<<29)

int main(){
    int N ,i,j , v , tr , gh[maxn][maxn] , vis[maxn] , d[maxn] , ans; 
    
  while(scanf("%d",&N)!=EOF){    
    for(i = 0 ; i<N ; ++i)
       for(j = 0 ; j<N ; ++j)
       scanf("%d",&gh[i][j]); 
    ans = 0 ;
    for(i = 0 ; i<N ; ++i)   d[i] = gh[0][i] , vis[i] = 0 ;
    vis[0] = 1 ;
    for(i = 0 ; i<N-1 ; ++i){
        tr = INF , v = -1 ;
        for(j = 0 ; j<N ; ++j)
           if(!vis[j] && d[j] < tr)  
              tr = d[j] , v = j ;  
        ans += tr ;  vis[v] = 1 ;
        for(j = 0 ; j<N ; ++j)
           if(!vis[j] && d[j] > gh[v][j])  
            d[j] = gh[v][j] ; 
    }
    printf("%d\n",ans);
  }
  return 0 ;
} 

