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

void GetSample_01(){

    char data[][100] = {
    "4 2 6 9 1" , 
    "4 6 1"     , 
    "5 6 10"    , 
    "4 5 5"     , 
    "3 5 4"     , 
    "2 3 4"     , 
    "1 2 3"             } ;
    
    cout << endl ;
    for(int i = 0 ; i < 7 ; ++ i )  puts(data[i]);
}

void GetSample_02(){
     const int A = 10 ; 
     const int B = 10 ; 
     const int N = A + B ; 
     const int M = N*(N-1)/2 ;
     const int L = 2 ; 
     const int K = 1 ; 
     
     int matrix[20][20] , EdgeNum = 0  ; 
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     for(int i = 0 ; i < N ; ++ i ) 
       for(int j = 0 ; j < i ; ++ j){
           printf("%d %d %d\n" , i+1 , j+1 , 1);
           EdgeNum ++ ;
       }
     //assert(EdgeNum == M);
}


void GetSample_03(){
     const int A = 10 ; 
     const int B = 10 ; 
     const int N = A + B ; 
     const int M = N*(N-1)/2 ;
     const int L = 2 ; 
     const int K = 0 ; 
     
     int matrix[20][20] , EdgeNum = 0  ; 
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     for(int i = 0 ; i < N ; ++ i ) 
       for(int j = 0 ; j < i ; ++ j){
           printf("%d %d %d\n" , i+1 , j+1 , 1);
           EdgeNum ++ ;
       }
     //assert(EdgeNum == M);
}

/*
1-[3]-2-[4]-3-[2]-4-[1]-5-[5]-6-[6]-7-[4]-8-[5]-9-[6]-10-[4]-11-[3]-12-[4]-13-[3]-14-[1]-15-[3]-16-[3]-17-[4]-18-[5]-19-[6]-20
*/
void GetSample_04(){
     const int A = 10 ; 
     const int B = 10 ; 
     const int N = A + B ; 
     const int M = N-1 ;
     const int L = 6 ; 
     const int K = 3 ; 
     const int WeightArray[] = 
     {3 , 4 , 2 , 1 , 5 , 6 , 4 , 5 , 6 , 4 , 3 , 4 , 3 , 1 , 3 , 3 , 4 , 5 , 6 } ;
     
     int matrix[20][20] , EdgeNum = 0  ; 
     
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     
     for(int i = 0 ; i < M ; ++ i)
        printf("%d %d %d\n" , i+1 , i+2 , WeightArray[i]);

     //assert(EdgeNum == M);     
}
void GetSample_05(){
     const int A = 10 ; 
     const int B = 10 ; 
     const int N = A + B ; 
     const int M = N-1 ;
     const int L = 10 ; 
     const int K = 1 ; 
     const int WeightArray[] = 
     {3 , 4 , 2 , 1 , 5 , 6 , 4 , 5 , 6 , 4 , 3 , 4 , 3 , 1 , 3 , 3 , 4 , 5 , 6 } ;
     
     int matrix[20][20] , EdgeNum = 0  ; 
     
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     
     for(int i = 0 ; i < M ; ++ i)
        printf("%d %d %d\n" , i+1 , i+2 , WeightArray[i]);
     //assert(EdgeNum == M);     
}
void GetSample_06(){
     const int A = 10 ; 
     const int B = 10 ; 
     const int N = A + B ; 
     const int M = N-1 ;
     const int L = 3 ; 
     const int K = 10 ; 
     const int WeightArray[] = 
     {3 , 4 , 2 , 1 , 5 , 6 , 4 , 5 , 6 , 4 , 3 , 4 , 3 , 1 , 3 , 3 , 4 , 5 , 6 } ;
     
     int matrix[20][20] , EdgeNum = 0  ; 
     
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     
     for(int i = 0 ; i < M ; ++ i)
        printf("%d %d %d\n" , i+1 , i+2 , WeightArray[i]);
     //assert(EdgeNum == M);     
}

void GetSample_Rand(int RandCount , int Length  , int UseCount){
     const int INT_INF = 100000000  ; 
     int A = 50 ; 
     int B = 50 ; 
     int N = A + B ; 
     int M = 0 ;  // ---- EdgeNum ;
     int L = Length ; 
     int K = UseCount ;
     
     int matrix[100][100] , i , j  ; 
     
     for(i = 0 ; i < N ; ++ i) for(j = 0 ; j < N ; ++ j) matrix[i][j] = INT_INF ;
     for(i = 0 ; i < N-1 ; ++ i){ 
        matrix[i+1][i] = matrix[i][i+1] = rand() % 100 + 1 ;
        ++ M ; 
     }
     for(i = 0 ; i < RandCount ; ++ i){
            int x = rand() % N  , y = rand() % N ; 
            if(matrix[x][y] == INT_INF   && x != y  && !(x==0&&y==N-1) && !(x==N-1&&y==0)){
                 matrix[x][y] = matrix[y][x] = rand()%100 + 1;
                 ++ M ;
            }
     }
     
     cout << endl ;
     printf("%d %d %d %d %d\n" , A , B ,M , L , K );
     
     for(i = 0 ; i < N ; ++ i)
       for(j = 0 ; j < i ; ++ j)
           if(matrix[i][j] < INT_INF ){
                printf("%d %d %d\n" , i+1 , j+1 , matrix[i][j]);
           }   
}

void GetSample_07(){
     GetSample_Rand(1000 , 3 , 10 );
}

void GetSample_08(){
     GetSample_Rand(20 , 86 , 9);
}
void GetSample_09(){
     GetSample_Rand(1000 , 9 ,  5 );
}
void GetSample_10(){
     GetSample_Rand(60000  , 1 , 2);
}

void GenerateData(){
     int CaseNumber = 10 ; 
     cout << CaseNumber << endl ;
     
     GetSample_01() ;
     GetSample_02() ;
     GetSample_03() ;
     GetSample_04() ;
     GetSample_05() ;
     GetSample_06() ;
     GetSample_07() ;
     GetSample_08() ;
     GetSample_09() ;
     GetSample_10() ;

}

int main(){
    freopen("1.std.in" , "w" , stdout);
    GenerateData();
    fclose(stdout);
    return 0 ;
}
