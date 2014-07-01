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

char s[9] ; 
int  a[8] ; 

int main(){
    
    //freopen("1.std.in" , "r" , stdin);
    //freopen("1.std.out", "w" , stdout);
    
    int acase , i , flag , t ; 
    cin >> acase ; 
    while(acase -- ){
           cin >> s ; 
           for(i = 0 ; i < 8 ; ++ i) a[i] = s[i] - '0' ;
           if(a[0]==1){
               for(i = 1 ; i < 8 ; ++ i) a[i]^= 1 ;
               flag = 1 ; 
               for(i = 7 ; i > 0 ; -- i) {
                     t = a[i] ;  a[i] = (t + flag)%2 ; flag = (t + flag)/2; 
               }
           }
           for(i = 0 ; i < 8 ; ++ i) cout << a[i] ; 
           cout << endl ;
    }
    //system("pause"); 
    return 0 ;
}
