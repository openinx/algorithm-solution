#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std ; 
typedef __int64 lld ;
const   char opech[] ="+-." ;
const   lld  maxn    = 20 ;
const   lld  table[] = {0,0,0,1,1,1,1,6,10,11,17,88,162,197,437,1350} ;

lld n ;

lld s1[maxn] , s2[maxn] , t1 , t2 ;
lld comp(lld xx[]){
    lld i , ans;
    t1 = t2 = 0 ;  s1[t1++] = 1 ;
    for(i = 2 ; i<=n ; ++i)
        if(xx[i] == 2)
             s1[t1-1] =  s1[t1-1]*( i<10 ? 10 : 100) + i ;
         else 
             s1[t1++] = i  , s2[t2++] = xx[i] ;
    for(i = 0 , ans = s1[0] ; i < t2 ; ++ i)
          ans = ans + (s2[i]==0 ?  s1[i+1] : -s1[i+1]) ;
    return  ans ;
}

lld x[maxn] , res_cnt ; 
void dfs(int dep ){
     lld i ;
     if(res_cnt > 20 ) return ; 
     if(dep > n ){
          if(comp(x) || ++res_cnt > 20)  return ;
          printf("1");
          for(i = 2 ; i <=n ; ++ i)
             printf(" %c %I64d",opech[x[i]],i);
          printf("\n");  
          return  ;
     }
     for(i = 0 ; i < 3 ; ++ i){
          x[dep] = i ; 
          dfs(dep + 1);
     }     
}

int Try(){
    if(scanf("%I64d",&n)==EOF) return 1 ;
    res_cnt = 0  ;
    dfs(2);
    printf("%I64d\n",table[n]);
    return 0 ;
}

int main(){
    while(!Try());
    return 0 ;
}


