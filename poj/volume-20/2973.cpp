#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 1005

int n, hit[MAXN]; 
char s[MAXN][8], t[8], cur[8];


bool streq(char *pattern, char *target){
    while(*pattern && *target){
        if(*pattern == '_' || *pattern == *target){
            pattern ++ ; 
            target ++ ;
        }else{
            return false;
        }
    }
    if(*target == '\0') return true;
    return false;
}


void calc(){
    for(int i = 0 ; i < n ; ++ i)
        if( 0 == hit[i] && streq(cur, s[i]) ){
            hit[i] = 1;
        }
}

void dfs(int i){
    if(i >= strlen(cur)){
        calc();
    }
    for(int k = i ; k < strlen(cur); ++ k){
        swap(cur[i], cur[k]);
        dfs(i+1);
        swap(cur[i], cur[k]);
    }
}


int main(){
    int ans = 0 ;
    while(scanf("%d", &n)!= EOF && n){
        for(int i = 0 ; i < n ; ++ i){
            scanf("%s", s[i]);
        }
        scanf("%s", t);
        memset(hit, 0, sizeof(hit));
        strcpy(cur, t);
        dfs(0);
        ans = 0 ; 
        for(int i = 0 ;i < n ; ++ i)
            ans += hit[i];
        printf("%d\n", ans);
    }
    return 0 ;
}
