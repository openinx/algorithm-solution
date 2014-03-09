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

const int MAXSIZE =  100005 ; 

struct DisjointSet{
       const int static MAXN = MAXSIZE ;
       int father[MAXN] , rank[MAXN] , n ;
       void init(int _N){
            n = _N ;
            fill(father , father + n + 1 , -1);
            fill(rank   , rank   + n + 1 ,  1);
       } 
       int  find(int x){
            int y , t ; 
            for(y = x ; father[y]!=-1 ; y = father[y]);
            for( ; x!=y ; x = t ) t = father[x] , father[x] = y ;
            return y ;
       }
       // x and y must be roots of some tree.
       void merge(int x , int y){
            if(rank[x] < rank[y]){
                rank[y] += rank[x]; father[x] = y ;
            }else{
                rank[x] += rank[y]; father[y] = x ; 
            }
       }
       int size(){
           int i , res = 0 ; 
           for(i = 0 ; i < n ; ++ i) 
             res += (father[i]==-1) ;
           return res ;
       }
}ds;

struct RMQ_Max{
       const static int LOGN = 32 ;
       const static int MAXN = MAXSIZE ;
       int dp[LOGN][MAXN];
       void init(int *_value , int n){
            int i , j ; 
            for(i = 0 ; i < n ; ++ i ) dp[0][i] = _value[i] ; 
            for(i = 1 ; i < LOGN ; ++ i)
                for(j = 0 ; j+(1<<i)-1 < n ; ++ j)
                   dp[i][j] = max(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
       }
       int query(int l , int r ){
            int t = (int)(log((double)(r-l+1))) ;
            return max(dp[t][l] , dp[t][r-(1<<t)+1]);
       }    
}Max;

struct RMQ_Min{
       const static int LOGN = 32 ;
       const static int MAXN = MAXSIZE ;
       int dp[LOGN][MAXN];
       void init(int *_value , int n){
            int i , j ; 
            for(i = 0 ; i < n ; ++ i ) dp[0][i] = _value[i] ; 
            for(i = 1 ; i < LOGN ; ++ i)
                for(j = 0 ; j+(1<<i)-1 < n ; ++ j)
                   dp[i][j] = min(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
       }
       int query(int l , int r ){
            int t = (int)(log((double)(r-l+1))) ;
            return min(dp[t][l] , dp[t][r-(1<<t)+1]);
       }    
}Min;


typedef long long lld  ;

#define for_n(i , x , y) for(i=(x) ;i<(y); ++i)

/*
int main(){
    int n , m , i , A[MAXSIZE] , x , y , s , e , cid = 0; 
    while( scanf("%d" , &n)!=EOF ){
         for_n(i , 0 , n) scanf("%d" ,&A[i]) , -- A[i] ;
         Max.init(A , n); 
         Min.init(A , n);
         ds.init(n);
         scanf("%d" , &m);
         for_n(i , 0 , m){
               scanf("%d%d" ,&x , &y);
               --x , --y ;
               s = ds.find(Max.query(x , y)) ; 
               e = ds.find(Min.query(x , y)) ;
               if(s != e )  ds.merge(s , e) ;
         }
         scanf("%d" , &m);
         printf("CASE %d\n" , ++ cid );
         for_n(i , 0 , m){
               scanf("%d%d",&x  , &y);
               --x , --y ;
               s = ds.find(x) , e = ds.find(y);
               puts((s==e ? "YES" : "NO"));
         }
    }
    //system("pause");
    return 0 ;
}*/

int main(){
    int n , m , i , x , y , cid = 0;
    while( scanf("%d%d" , &n , &m)!= EOF && (n|m)){
        ds.init(n) ; 
        for_n(i , 0 , m ){
              scanf("%d%d" , &x , &y); --x , --y ; 
              x = ds.find(x) , y = ds.find(y) ; 
              if(x != y )
                  ds.merge(x , y) ; 
        }
        printf("Case %d: %d\n" , ++cid , ds.size());
    }
    //system("pause");
    return 0 ;
}


