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
#define  LLD  "%lld"
using namespace std ;

typedef long long lld ;

const int MAXN = 110 ;
const int INF  = 0x7FFFFFFF ;

char a[MAXN] , b[MAXN] ;

int  V[][5]= { {5 , -1 , -2 , -1 , -3} , 
               {-1,  5 , -3 , -2 , -4} ,
               {-2, -3 ,  5 , -2 , -2} ,
               {-1, -2 , -2 ,  5 , -1} ,
               {-3, -4 , -2 ,  -1,  0} };
               
int opt[MAXN][MAXN] ,  to[130] ;

int dp(int i , int j){ 
    if(opt[i][j] != INF )  return opt[i][j] ; 
    int x , y , z ;
    x = dp(i , j-1) + V[to[b[j]]][to[' ']]  ;
    y = dp(i-1 , j) + V[to[a[i]]][to[' ']]  ; 
    z = dp(i-1 ,j-1)+ V[to[a[i]]][to[b[j]]] ;
    opt[i][j] = max(x , max(y , z));
    return opt[i][j] ;
}

int main(){
    to['A'] = 0 ; to['C'] = 1 ; to['G'] = 2 ; to['T'] = 3 ; to[' '] = 4 ;
    int acase , i , j , ans , n , m  ;
    scanf("%d" , &acase);
    while(acase--){
         scanf("%d" , &n);  scanf("%s" , a+1);
         scanf("%d" , &m);  scanf("%s" , b+1); 
         for(i = 0 ; i < MAXN ; ++ i) for(j = 0 ; j < MAXN ; ++ j) opt[i][j] = INF ;
         opt[0][0] = 0 ; 
         for(i = 1 ; i <= n ; ++ i)  opt[i][0] = opt[i-1][0] + V[to[a[i]]][4] ;
         for(i = 1 ; i <= m ; ++ i)  opt[0][i] = opt[0][i-1] + V[4][to[b[i]]] ;
         ans = dp(n , m );
         printf("%d\n" , ans);
    }
    //system("pause");
    return 0 ;
}
