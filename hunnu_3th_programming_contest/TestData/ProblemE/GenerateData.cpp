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

const int MAX_H = 16 ; 
const int MAX_W = 30 ;
const int MINE_NUM = 99 ;

char a[MAX_H][MAX_W+1];

void GetSampleRand(){
     int mine_count = 0 ;
     int i , j , x , y ; 
     for(i = 0 ; i < MAX_H ; ++ i)
        a[i][MAX_W] = '\0' ; 
     for(i = 0 ; i < MAX_H ; ++ i)
        for(j = 0 ; j < MAX_W ; ++ j)
           a[i][j]='.' ; 
     while(1){
        x = rand() % MAX_H , y = rand() % MAX_W ;
        if(a[x][y] == '*')  continue ;
        ++ mine_count ; 
        if(mine_count > MINE_NUM ) break ;
        a[x][y] = '*' ; 
     }
     while(1){
        x = rand() % MAX_H , y = rand() % MAX_W ;
        if(a[x][y] == '*') continue ;
        else break ; 
     }
     printf("%d %d\n" , x+1 ,y+1);
     for(i = 0 ; i < MAX_H ; ++ i)
        puts(a[i]);
}

int main(){
    
    freopen("1.std.in" , "w" ,stdout );
    
    int case_count = 100 ;
    printf("%d\n" , case_count );
    GetSampleRand();
    for(int i = 2 ; i <= case_count ; ++ i){
         printf("\n");
         //printf("Case#:%d\n" , i);
         GetSampleRand();
    } 
    
    fclose(stdout);
    //system("pause");
    return 0 ;
}
