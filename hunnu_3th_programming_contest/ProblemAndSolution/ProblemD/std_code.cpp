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


int a[101][101] ;

int main(){
    
    freopen("1.std.in" , "r" ,stdin);
    freopen("1.std.out", "w" ,stdout);
    
    int n , i , j , k , acase , NUM ; 
    cin >> acase ; 
    while(acase -- ){
           cin >> n ; 
           NUM = 0 ; 
           for(i = 1 ; i <= n ; ++ i){
                 if(i % 2 == 1 ){
                       for(j = 1 ; j < n+1-i ; ++ j) 
                         a[i][j] = ++ NUM ;
                       for(k = i ; k <= n ; ++ k)
                         a[k][j] = ++ NUM ; 
                 }else{
                       for(k = n ; k > i ; -- k)
                         a[k][n+1-i] = ++ NUM ; 
                       for(j = n+1-i ; j >= 1 ; -- j)
                         a[i][j] = ++ NUM ; 
                 }
           }
           for(i = 1 ; i <= n ; ++i){
                cout << a[i][1] ; 
                for(j = 2 ; j <= n ; ++ j)
                  cout << " " << a[i][j] ; 
                cout << endl ;
           }
    }
    return 0 ;
}
