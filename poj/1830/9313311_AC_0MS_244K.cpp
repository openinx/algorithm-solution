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
#define for_n(i,x,y) for(i=(x);i<(y);++i)
#define for_each(i,x)for(i=(x).begin();i!=(x).end();i++)
using namespace std ;

typedef long long lld  ;

struct Gauss{
   const static int maxn = 31 ;
   int n ;
   bool (*a)[maxn]; 
   void init(bool (*_a)[maxn] , int _n ){
        a = _a ; n = _n ; 
   }
   int  solve(){
        int i , j , k , res = 0 ;
        for(i = 0 ; i < n ; ++ i){
                for(k = i ; k < n ; ++ k)
                   if(a[k][i]) break ;
                if(k == n ) continue ;
                if(k != i ){
                    for(j = 0 ; j <= n ; ++ j) swap(a[i][j] , a[k][j]);
                }
                for(k = i+1 ; k < n ; ++ k)
                  if(a[k][i]){
                       for(j = i ; j <= n ; ++ j)  
                          a[k][j] = a[i][j]^a[k][j] ;
                  }
        }
        for(i = 0 ; i < n ; ++ i)
          if(!a[i][i] && a[i][n]) return -1 ;
        for(i = 0 ; i < n ; ++ i) 
          res += !a[i][i];
        return 1<<res ;
   }   
}G;

int main(){
    bool a[31][31];
    int n , acase , i , j; 
    cin >> acase ; 
    while(acase -- ){
          scanf("%d" , &n);
          memset(a , 0 , sizeof(a));
          for(i = 0 ; i < n ; ++ i)  scanf("%d" , &j) , a[i][n] = j ;
          for(i = 0 ; i < n ; ++ i)  scanf("%d" , &j) , a[i][n]^= j ; 
          for(i = 0 ; i < n ; ++ i) a[i][i] = 1 ;
          while(1){
                scanf("%d%d" , &i ,&j); 
                if((i+j)==0) break ;  
                a[--j][--i] = 1 ; 
          }
          G.init(a , n);
          int res = G.solve() ; 
          if(res == -1){
              printf("Oh,it's impossible~!!\n");
          }else {
              printf("%d\n" , res);
          }
    }
    //system("pause");
    return 0 ;
}
