#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>

using namespace std ;

int n , caseNumber , c[1001] ,  cnt , ans[1001] ;

int main(){
    
    //freopen("2.std.in" , "r" , stdin);
    //freopen("2.std.out" , "w" , stdout);
    
    int now , i ;
    cin >> caseNumber ; 
    while(caseNumber--){
          cin >> n ; 
          for(i = 1 ; i <= n ; ++ i)  cin >> c[i] ; 
          memset(ans , 0 , sizeof(ans));
          now = 1 ; 
          for(i = 1 ; i <= n ; ++ i){
               cnt = 1 ; 
               while(cnt < i ){
                   while(ans[now])  now = now % n + 1 ; 
                   cnt ++  ; now = now % n + 1 ; 
               }
               while(ans[now]) now = now  % n + 1 ;
               ans[now] = i ; 
               now = now % n + 1 ; 
          }
          cout << c[ ans[1] ] ; 
          for(i = 2 ; i <= n ; ++ i) 
             cout << " " << c[ ans[i] ] ;
          cout << endl ; 
    }     
    //system("pause");
    return 0 ;
}
