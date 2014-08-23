#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

#define MAXN 20005
#define MAXM 22
#define WORDLEN 4

struct node{
    int ch[4];
    int cnt;
}nodes[MAXN * MAXM];

int root, nsiz, n , m, result[MAXN];
map<char, int> idx;

int newNode(){
    ++nsiz;
    for(int t = 0 ; t < WORDLEN; ++ t)
        nodes[nsiz].ch[t] = 0 ;
    nodes[nsiz].cnt = 0 ;
    return nsiz;
}

void insert(char *s){
    int ch,  i = root, k;
    for(int t = 0 ; t < strlen(s); ++ t){
        k = idx[ s[t] ];
        ch = nodes[i].ch[k];
        if(ch == 0){
            nodes[i].ch[k] = newNode();
        }
        i = nodes[i].ch[k];
    }
    nodes[i].cnt ++ ;
}

int main(){
    char s[MAXM];
    char DNA[] = "ACGT";
    for(int i = 0 ; i < 4 ; ++ i){
        idx[ DNA[i] ] = i ;
    }
    while(scanf("%d%d", &n, &m) !=EOF && (n|m)){
        nsiz = 0 ;  
        root = newNode();
        for(int i = 0 ; i < n ; ++ i){
            scanf("%s", s);
            insert(s);
        }
        memset(result, 0 , sizeof(result));
        for(int i = 1; i <= nsiz; ++ i)
           result[ nodes[i].cnt ] ++ ;
        for(int i = 1 ; i <= n ; ++ i)
           printf("%d\n", result[i]);
    }
    return 0;
}

