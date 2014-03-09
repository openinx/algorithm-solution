#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void compute(){
     int i ; 
     for(i = 0 ; i < 100000000 ; ++ i) ; 
}

int main(){
    int a ,b ;
    scanf("%d%d" ,&a , &b);
    compute();
    printf("%d\n" , a + b);
    return  0 ;
}
