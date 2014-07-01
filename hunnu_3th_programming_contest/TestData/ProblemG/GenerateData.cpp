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

const int MAXN = 1001  ; 

int rangeInt(int x){ return x % MAXN ;  }

void GetSample_01(){
     const int VEX_NUM = 5 ; 
     const int x[] = {0 , 1 , 4 , 2 , 0 } ; 
     const int y[] = {0 , 0 , 1 , 3 , 2 } ;
     printf("%d\n" , VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i){
          printf("%d %d\n" , x[i] , y[i]);
     }
}

void GetSample_02(){
     const int VEX_NUM = 8 ; 
     const int x[] = {0 , 1 , 6 , 2 , 6 , 2 , 3 , 1} ; 
     const int y[] = {0 , 0 , 1 , 1 , 2 , 3 , 6 , 2} ; 
     printf("%d\n" , VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i){
          printf("%d %d\n" , x[i] , y[i]);
     }
}

void GetSample_03(){
     const int VEX_NUM = 13 ; 
     const int x[] = {0 , 1 , 15 , 15 , 13 , 1 , 12 , 1 , 11 , 1 , 10 ,1 , 2 } ; 
     const int y[] = {0 , 0 , 1  , 6 ,  1  , 5 ,  1 , 4 ,  1 , 3 , 1  ,2 , 1 } ; 
     printf("%d\n" , VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i){
          printf("%d %d\n" , x[i] , y[i]);
     }
}

void GetSample_04(){
     const int VEX_NUM = 5 ; 
     const int x[] = {0 , 1 , 17 , 17 , 0} ; 
     const int y[] = {0 , 0 ,  1 , 1000 , 1000} ; 
     printf("%d\n" , VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i){
          printf("%d %d\n" , x[i] , y[i]);
     }
}

void GetSample_05(){
     const int VEX_NUM = 10 ; 
     const int x[] = {0 , 1 , 13 , 1 , 13 , 1 , 1 , 2 , 2 , 0} ; 
     const int y[] = {0 , 0 ,  1 , 1 ,  2 , 2 , 6 , 7 , 8 , 8} ; 
     printf("%d\n" , VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i){
          printf("%d %d\n" , x[i] , y[i]);
     }
}

void GetSample_06(int vNum , int maxH , int maxW ){
     const int vertexNum = vNum  ; 
     const int MAX_H = maxH ; 
     const int MAX_W = maxW ;
     int cnt = 0 ; 
     printf("%d\n" , vertexNum );
     /*----------------BOTTON EDGE--------------------*/
     for(int i = 0 ; i <= MAX_H ; ++ i){
        if(i % 2 == 0 ){
              printf("%d %d\n" , i , 0 );
        }else{
              printf("%d %d\n" , i , 1 );
        }
        ++ cnt ; 
     }
     /*----------------RIGHT  EDGE--------------------*/
     for(int i = 1 ; i < MAX_H ; ++ i){
        if(i % 2 == 0 ){
              printf("%d %d\n" , MAX_H-1 , i );
        }else{
              printf("%d %d\n" , MAX_H , i );
        }
        ++ cnt ; 
     }
     /*----------------UP     EDGE--------------------*/
     for(int i = MAX_H ; i >= 0; -- i){
        if(i % 2 == 0 ){
              printf("%d %d\n" , i , MAX_H);
        }else{
              printf("%d %d\n" , i , MAX_H-1 );
        }
        ++ cnt ;
     }
     /*----------------LEFT   EDGE--------------------*/
     for(int i = MAX_H-1 ; i > 0 ; --i){
        if(i % 2 == 0 ){
              printf("%d %d\n" , 1 , i );
        }else{
              printf("%d %d\n" , 0 , i );
        }
        ++ cnt ;
     }
     //cout << "---------------------------------- Vertex Count:" << cnt <<endl ; 
}

void GetSample_07(){
     GetSample_06(1000 , 250 , 250 ) ; 
}

void GetSample_08(){
     printf("4\n");
     printf("0 0\n");
     printf("1000 0\n");
     printf("1000 1000\n");
     printf("0 1000\n");
}

void GetSample_09(){
     const int MAX_LEFT = 998 ; 
     const int VEX_NUM = 999  ; 
     printf("%d\n" , VEX_NUM);
     for(int i = 1 ; i < MAX_LEFT ; ++ i){
          if(i % 2 == 0 )
              printf("%d %d\n" , i , 1 );
          else 
              printf("%d %d\n" , i , MAX_LEFT );
     }
     printf("%d %d\n" , MAX_LEFT , 0);
     printf("%d %d\n" , 0 , 0 );
}

void GetSample_10(){
     const int VEX_NUM = 16 ; 
     const int x[] = {0 , 10 , 10 , 8 ,8 ,7 ,7 ,6 , 6, 4 , 4 ,3 , 3 , 2 , 2 , 0 } ;
     const int y[] = {0 , 0  , 10 , 10,1 ,1 ,8 ,8 , 1, 1 , 8 ,8 , 1 , 1 , 10 , 10} ;
     printf("%d\n" ,VEX_NUM);
     for(int i = 0 ; i < VEX_NUM ; ++ i)
        printf("%d %d\n" , x[i] , y[i]);
}

int main(){
    const int CaseNumber = 10 ;     
    
    freopen("1.std.in" , "w" , stdout);
    
    cout << CaseNumber << endl ;
    
    GetSample_01() ;
    GetSample_02() ; 
    GetSample_03() ; 
    GetSample_04() ; 
    GetSample_05() ; 
    GetSample_06(40 , 10 , 10 ) ; 
    GetSample_07() ; 
    GetSample_08() ; 
    GetSample_09() ;
    GetSample_10() ;
    
    fclose(stdin);
    return 0 ;
}
