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

inline int bit(int i , int n){
       return (1<<i)&n ? 1 : 0 ; 
}

int main(){
    int i , ii , total = (1<<8) ;
    
    freopen("1.std.in" , "w" , stdout);
    cout << total << endl ; 
    for(i = 0 ; i < total ; ++ i){
       for(ii = 0 ; ii < 8 ; ++ ii )
          cout << bit(ii , i)  ; 
       cout << endl ; 
    } 
    fclose(stdin);
    
    return 0 ;
}
