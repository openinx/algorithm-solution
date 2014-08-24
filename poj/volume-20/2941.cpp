#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std ;

#define MAXN 1001

int n , mtx[MAXN][MAXN], x[MAXN];

void shuffle(){
    int a, b ;
    for(int i = 0 ; i < n; ++ i)
        x[i] = i ; 
    for(int i = 0 ; i < n; ++ i){
        a = rand() % n;
        b = rand() % n;
        swap(x[a], x[b]);
    }
}

bool check(){
    int i, j , sum = 0, temp ;
    for(i = 0 ; i < n ; ++ i) 
        sum += mtx[i][i];
    for(i = 0 ; i < n * 10 ; ++ i){
        shuffle();
        temp = 0 ;
        for(j = 0 ; j < n ; ++ j)
            temp += mtx[j][ x[j] ];
        if(temp != sum ) 
            return 0 ;
    }
    return 1;
}

int main(){
    int i, j ;
    srand(time(NULL));
    while(scanf("%d", &n)!= EOF && n){
        for(i = 0 ; i < n ; ++ i)
            for(j = 0; j < n ; ++ j)
                scanf("%d", &mtx[i][j]);
        if(check()){
            printf("homogeneous\n");
        }else{
            printf("not homogeneous\n");
        }
    }
    return 0 ;
}

