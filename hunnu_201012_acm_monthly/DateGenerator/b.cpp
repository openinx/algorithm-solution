#include<iostream>
using namespace std ;

const  int MOD = 1000000 ;

void random_case(){
     int M = rand() % 100 + 1 , N = rand() % 100 + 1 ;
     
     printf("%d %d\n" , M , N);
     
     for(int i = 0 ; i < N + M ; ++ i){
           printf("%d\n" , rand()%MOD);
     }
}


int main(){
    
    //freopen("2.std.in" , "w" , stdout);
    
    srand((unsigned int) time(NULL));
    int testCase = 98 ; 
    printf("%d\n" , testCase);
    while(testCase--){
          random_case();
    }
    
    //fclose(stdout);
    
    return 0 ;
}
