#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char c;
    int cnt[100];
    while((c=getchar())!='{'); 
    memset(cnt, 0 ,sizeof(cnt));
    while((c=getchar())!='}'){
        if(c >= 'a' && c <= 'z' )
            cnt[c - 'a'] ++ ; 
    }
    int size = 0;
    for(int i = 0 ; i < 100; ++ i)
        size += (cnt[i] > 0 ? 1: 0);
    printf("%d\n", size);
    return 0;
}
 
