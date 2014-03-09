/*
* auther  : huzijin
* contact : huzijin_happy@126.com
*/
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

#define fout(x) cout<<"Program.Debug #: "<<(x)<<endl;
using namespace std ;

typedef long long lld  ;

struct RMQ_Max{
       const static int LOGN = 32 ;
       const static int MAXN = 50005 ;
       int dp[LOGN][MAXN];
       void init(int *_value , int n){
            int i , j ; 
            for(i = 0 ; i < n ; ++ i ) dp[0][i] = _value[i] ; 
            for(i = 1 ; i < LOGN ; ++ i)
                for(j = 0 ; j+(1<<i)-1 < n ; ++ j)
                   dp[i][j] = max(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
       }
       int query(int l , int r ){
            int t = (int)(log10(r-l+1)/log10(2.0)) ;
            return max(dp[t][l] , dp[t][r-(1<<t)+1]);
       }    
}Max;

struct RMQ_Min{
       const static int LOGN = 32 ;
       const static int MAXN = 50005 ;
       int dp[LOGN][MAXN];
       void init(int *_value , int n){
            int i , j ; 
            for(i = 0 ; i < n ; ++ i ) dp[0][i] = _value[i] ; 
            for(i = 1 ; i < LOGN ; ++ i)
                for(j = 0 ; j+(1<<i)-1 < n ; ++ j)
                   dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
       }
       int query(int l , int r ){
            int t = (int)(log10(r-l+1)/log10(2.0)) ;
            return min(dp[t][l] , dp[t][r-(1<<t)+1]);
       }    
}Min;

int x[50001];

#define for_n(i , x ,y) for(i=(x);i<(y);++i)

int main(){
    int i , N , Q , s , e ; 
    scanf("%d%d" , &N , &Q);
    for_n(i , 0 , N) scanf("%d" , &x[i]);
    Max.init(x , N);  Min.init(x , N);
    for_n(i , 0 , Q){
         scanf("%d%d" , &s , &e); --s , --e ;
         printf("%d\n" , Max.query(s , e) - Min.query(s , e));
    }
    //system("pause");
    return 0 ;
}
