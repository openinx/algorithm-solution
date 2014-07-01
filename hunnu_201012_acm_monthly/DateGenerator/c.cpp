#include<iostream>
#include<stdlib.h>
using namespace std ;

int main(){
    
    ///freopen("2.std.in" , "w" , stdout);
    
    int testCase = 10 ;
    printf("%d\n\n" , testCase);
    
    printf("%d\n" , 1);
    printf("%d\n" , 10);
    printf("%d\n" , 1000000000);
    
    srand((unsigned int) time(NULL)); 
    
    for(int i = 4 ; i <= testCase ; ++ i){
          __int64 a = (__int64)rand() , b = (__int64)rand();
          printf("%d\n" , (int)(a*b%1000000000) );
    }
    
    // fclose(stdout);
    
    return 0 ;
}
