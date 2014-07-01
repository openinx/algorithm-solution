#include<iostream>
using namespace std ;

typedef __int64 lld ;

void special_case0(){
     
     //printf("\n");
     
     printf("3 1 2 3\n");
}

void special_case1(){
     
    // printf("\n");
     
     printf("5 5 1 2 4 3\n");
}

void special_case2(){
     
     //printf("\n");
     
     printf("10 1 1 1 1 1 1 1 1 1 1\n");
}

void random_case(int n , int K){
     
     //printf("\n");
     
     printf("%d" , n);
     
     for(int i = 0 ; i < n ;++ i){
         lld x = rand() ;
         printf(" %I64d" , x * x % K);
     }
     printf("\n");

}



int main(){
    int testCase = 10 ;
    
    //freopen("1.std.in" , "w" ,stdout );
    
    cout<<testCase <<endl;
    
    srand((int)time(NULL));
    
    special_case0();
    special_case1();
    special_case2();
    
    random_case(10     , 200000);
    random_case(100    , 100);
    random_case(1000   , 5000);
    random_case(10000  , 200000);
    random_case(50000  , 100000);
    random_case(80000  , 100);
    random_case(100000 , 200000);
    
    //fclose(stdout);
    
    return 0 ;
    
}
