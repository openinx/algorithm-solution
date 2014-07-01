#include<iostream>
using namespace std; 

//  answer = 50.000
void special_case1(){
     
     printf("\n");
     
     printf("3 3\n");
     printf("1 1 100\n");
     printf("1 2 100\n");
     printf("2 3 5\n");
     printf("1 3 2\n");
}

// answer = 1.250
void special_case2(){
     
     printf("\n");
     
     printf("5 6\n");
     printf("1 1 1 1 1\n");
     printf("1 5 1\n");
     printf("5 4 1\n");
     printf("4 2 1\n");
     printf("2 5 1\n");
     printf("1 2 1\n");
     printf("3 1 1\n");
     
}

// answer = 
void special_case3(){
     
     printf("\n");
     
     printf("5 10\n");
     printf("1 1 1 1 1\n");
     for(int i = 1 ; i <= 5 ; ++i)
        for(int j = 1 ; j<i ; ++ j)
        printf("%d %d 1\n" , j , i);
}

// answer = 
void special_case4(){
     
     printf("\n");
     
     int Vcnt = 6 , Ecnt = 6 ;
     printf("%d %d\n" , Vcnt , Ecnt);
     for(int i = 1 ; i <= Vcnt ; ++i)  printf("%d " , i);  printf("\n");
     for(int i = 1 ; i < Vcnt  ; ++i)  printf("%d %d %d\n" , i , i+1 , i);  
     printf("6 1 6\n");

}

//   answer = 0.333
void special_case5(){
     
     printf("\n");
     
     printf("3 1\n");
     printf("100 50 100\n");
     printf("1 2 50\n");
     
}

void special_case6(){
     
     printf("\n");
     
     int Vcnt = 20 , Ecnt = 19 ;
     
     printf("%d %d\n" , Vcnt , Ecnt);
     for(int i = 1 ; i <= Vcnt ; ++ i)  printf("%d " , rand()%100 + 1);  printf("\n");
     
     for(int i = 1 ; i < Vcnt ; ++ i)  printf("%d %d %d\n" ,i , i + 1 , rand()%100 + 1); 
     
     
}

void special_case7(){
     
     printf("\n");
     
     int Vcnt = 50 , Ecnt = 50 * 49 / 2 ;
     
     printf("%d %d\n" , Vcnt , Ecnt);
     
     for(int i = 1 ; i<= Vcnt ; ++ i)  printf("%d " , rand()%97 + 1);  printf("\n");
     
     for(int i = 1 ; i <= Vcnt ; ++ i)
           for(int j = 1 ; j < i ; ++ j) {
              printf("%d %d %d\n" ,j , i , rand()%100+1);
              --Ecnt ;
           }
     if(Ecnt)  printf("Wrong\n");
     
}

// YES
void special_case8(){
     
     printf("\n");
     
     int Vcnt = 80 , Ecnt = 1000 , edge[81][81] , i , j;
     
     printf("%d %d\n" , Vcnt , Ecnt);
     
     for(i = 1 ; i <= Vcnt ; ++ i)  printf("%d " , rand()%100 + 1);  printf("\n");
     
     memset(edge , -1 ,sizeof(edge)); 
     
     for(i = 1 ; i <= Ecnt ; ++ i){
         int x , y ;
         while(1){
              x = rand()%80 + 1 ;  y = rand()%80 + 1 ;
              if(x > y)  swap(x , y);
              if(x != y && edge[x][y] == -1)  break ;
         }
         edge[x][y] = rand() % 100 + 1 ; 
         //printf("%d %d %d\n" , x ,y , edge[x][y]);
     }
     
     
     for(i = 1 ; i <= Vcnt ; ++ i)
           for(j = 1; j < i ; ++ j)
               if(edge[j][i]!=-1){  
                   printf("%d %d %d\n" , j , i , edge[j][i]);
                   -- Ecnt ;
               }
     
     if(Ecnt)  puts("Wrong");
     
}

// YES
void special_case9(){
     
     printf("\n");
     
     int i , j , Vcnt = 100 , Ecnt = 100 ; 
     
     printf("%d %d\n" , Vcnt , Ecnt);
     
     for(i = 1 ; i<= Vcnt ; ++i )  printf("%d " , rand()%100 + 1);  printf("\n");
     
     for(i = 1 ; i < Vcnt ; ++i )  printf("%d %d %d\n" , i , i + 1 , 1);
     
     printf("%d %d %d\n" , Vcnt , 1 , 1);
     
}


// YES
void special_case10(){
     
     printf("\n");
     
     int i , j , cnt = 0 ,  Vcnt = 100 , Ecnt = 2000 ;
     
     printf("%d %d\n" , Vcnt , Ecnt);
     
     for(i = 1 ; i <= Vcnt ; ++ i)  printf("%d " , 100);  printf("\n");
     
     for(i = 1 ; i <= Vcnt ; ++ i){ 
         for(j = 1 ; j < i ; ++ j){
             -- Ecnt ;
             ++ cnt ;
             printf("%d %d %d\n", j , i , 100);
             if(cnt == 2000 )  break ;
         }
         if(cnt == 2000) break ;
     }
         
     if(Ecnt) puts("Wrong");

}


int main(){
    int testCase = 10 ;
    
    //freopen("1.std.in" ,"w" , stdout);
    
    cout<<testCase<<endl;
    
    special_case1();
    special_case2();
    special_case3();
    special_case4();
    special_case5();
    special_case6();
    special_case7();
    special_case8();
    special_case9();
    special_case10();
    
    //fclose(stdout);
    
    return 0;
    
}
