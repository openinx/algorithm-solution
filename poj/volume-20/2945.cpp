#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

const static int MAXN = (1<<16) - 1;
const static int MAXLEN = 21;
const static int MAXRSIZ = 20001;

char ss[MAXN][MAXLEN];

inline int hash(char *s){
    int val = 0 ;
    while(*s){
        val = (val << 2) + (*s++);
    }
    return val & MAXN;
}

struct _Val{
    char *s;
    int cnt;
}values[MAXRSIZ];

int result[MAXRSIZ], slot[MAXN], next[MAXRSIZ], nsiz ;

void insert(char *s){
    int i, hval = hash(s);
    for(i = slot[hval]; i >= 0 ; i = next[i] ) {
        if(!strcmp(values[i].s, s)){
            values[i].cnt ++ ;
            return ;
        }
    }
    values[nsiz].s = s; 
    values[nsiz].cnt = 1;
    next[nsiz] = slot[hval];
    slot[hval] = nsiz ++ ;
}

void calc(){
    int i , j ;
    memset(result, 0 , sizeof(result));
    for(i = 0 ; i < MAXN ; ++ i){
        for(j = slot[i]; j >= 0 ; j = next[j]){
            result[ values[j].cnt ] ++ ;
        }
    }
}

int main(){
    int n, m ; 
    while(scanf("%d%d", &n, &m) != EOF && (n | m)){
        nsiz = 0;
        memset(slot, -1, sizeof(slot));
        for(int i = 0; i < n ; ++ i){
            scanf("%s", ss[i]);
            insert(ss[i]);
        }
        calc();
        for(int i = 1 ; i <= n; ++ i)
            cout << result[i] << endl;
    }
    return 0 ;
}

