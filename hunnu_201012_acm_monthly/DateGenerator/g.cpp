#include<iostream>
using namespace std ;

const  int MOD  = 100 ;  


// answer = 5
void special_case0(){
     
     printf("\n");
     
     printf("5 4\n");  
     printf("2 4\n");
     printf("1 5 1\n");
     printf("1 3 2\n");
     printf("3 4 1\n");
     printf("4 5 2\n");
     
}

// answer = 10
void special_case1(){
    
    printf("\n");
    
    printf("4 6\n");
    printf("2 2\n");
    printf("1 2 4\n");
    printf("1 3 8\n");
    printf("1 4 11\n");
    printf("2 4 6\n");
    printf("2 3 3\n");
    printf("3 4 2\n");
    
}

// answer = 4 ;
void special_case2(){
   
   printf("\n");
   
   printf("7 7\n");
   printf("4 5\n");
   printf("1 2 1\n"); 
   printf("2 3 1\n"); 
   printf("3 7 1\n"); 
   printf("1 4 1\n"); 
   printf("4 5 1\n"); 
   printf("5 6 1\n");
   printf("6 7 1\n"); 

}

void special_case3(){
  
   printf("\n");
   
   printf("7 7\n");
   printf("1000000 1000000\n");
   printf("1 2 1\n");
   printf("2 3 2\n");
   printf("3 7 3\n");
   printf("1 4 4\n");
   printf("4 5 5\n");
   printf("5 6 6\n");
   printf("6 7 7\n");
     
}

// YES 
void special_case4(){
   
   printf("\n");
   
   printf("20 400\n");
   printf("1 1000000\n");
   for(int i = 1 ; i <= 20 ; ++ i)
      for(int j = 1 ; j<= 20 ; ++j){
              printf("%d %d %d\n" ,i , j , i+j);
      }

}

// YES  answer = -1 
void special_case5(){
   
   printf("\n");
   
   printf("30  1\n");
   printf("1000000 1000000\n");
   printf("1 30 100\n");
   
}

void special_case6(){
   
     printf("\n");
     
     printf("60 120\n");
     printf("1 60\n");
     
     for(int i = 1 ; i <= 60 ; ++ i)  
         printf("%d %d %d\n" , i , i , 60);
     
     for(int i = 1 ; i < 60 ;  ++i) 
         printf("%d %d %d\n" , i , i + 1 , rand()%100+1);
     
     printf("60 1 38\n");


}

void special_case7(){
     
     printf("\n");
     
     printf("10  10000\n");
     printf("1000000 1000000\n");
     
     for(int i = 1 ; i<= 10000 ; ++ i){
          int x = rand()%10 + 1 , y = rand()%10 + 1 , w = rand()%100 + 1 ;
          printf("%d %d %d\n" , x , y , w);
     }

}

void special_case8(){
     
     printf("\n");
     
     printf("80 100\n");
     printf("5000 1000000\n");
     
     for(int i = 1 ; i <= 100 ; ++ i){
          int x = rand()%80 + 1 , y = rand()%80 + 1  , w = rand()%100 + 1 ;
          printf("%d %d %d\n" , x , y ,w);
     }

}

void special_case9(){
     
     printf("\n");
     
     printf("100 10000\n");
     printf("101 1000000\n");
     
     for(int i = 1 ; i<=100 ; ++ i)
         for(int j = 1 ; j<=100 ; ++j)
             printf("%d %d %d\n" , i , j , rand()%100 + 1 );
      
}



int main(){
     
    //freopen("1.std.in" , "w" , stdout);
    
    srand((int)time(NULL));
    int testCase = 10 ;
    
    printf("%d\n" , testCase);
    
    special_case0();
    special_case1();
    special_case2();
    special_case3();
    special_case4();
    special_case5();
    special_case6();
    special_case7();
    special_case8();
    special_case9();
   
    //fclose(stdout);
    
    return 0 ;

}
