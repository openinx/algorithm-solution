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


int a[1001] ;

void getPerm(int n ){
     cout << n << endl ; 
     for(int i = 1 ; i <= n ; ++ i)  
        a[i] = i ; 
     int cntRandom = rand() ; 
     while(cntRandom -- ){
         int x = (rand()-1) % n + 1 , y = (rand()-1) % n + 1; 
         swap( a[x] , a[y]);
     }
     cout << a[1] ; 
     for(int i = 2 ; i <= n ; ++ i) cout << " " << a[i] ; 
     cout << endl ;
}


int main(){
    
    srand(unsigned(time(0)));
    
    freopen("1.std.in" , "w" , stdout);
    
    cout << 7 << endl ; 
    
    getPerm(3);
    getPerm(10);
    getPerm(100);
    getPerm(500);
    getPerm(800);
    getPerm(1000);
    getPerm(1000);
    
    return 0 ;
}
