#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


bool eq(char a, char wildchar){
    return a == wildchar || wildchar == '?' || a == '?';
}

bool streq(const char *a, const char *b){
    while(*a != '\0' && *b != '\0'){ 
        if(!eq(*a, *b)) return 0;
        ++a ; ++b;
    }
    if(*a == '\0' && *b == '\0') return 1; 
    return 0;
}

void init(const char *t, int *p, int m){
    int i , j ;
    p[0] = -1;
    for(i = 1 ; i < m ; ++ i){
        j = p[i-1] + 1;
        while(j > 0 && !eq(t[i], t[j])) j = p[j-1] + 1;
        p[i] = (eq(t[i], t[j]) ? j: -1);
    }
}

int kmpMatch(const char *s, int n, const char *t, int m, int *p){
    int i , j ; 
    if(m == 0) return 0;
    init(t, p , m);
    j = 0 ;
    for(i = 0; i < n ; ++ i){
        while(j > 0 && !eq(s[i], t[j])) j = p[j-1] + 1;
        if(eq(s[i],t[j])) ++ j;
        if(j == m )
            return i - m + 1 ;
    }
    return -1;
}

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s), m = strlen(p), i, j, k, index; 
        int *next = new int[m+1];
        if(n == 0) {
            while(*p != '\0' && *p == '*') ++public;
            return *p == '\0';
        }
        i = j = 0 ; 
        while( i < n && j < m){
            if(eq(s[i], p[j])) {
                ++i;  ++j;
            }else if(p[j] == '*'){
                while(j < m && p[j] == '*') ++j;
                if(j == m ) break;
                for(k = j; k < m && p[k] != '*'; ++k);
                if(k == m){ 
                    delete next;
                    if( n - m + j >= i){
                        if(streq(s + n - m + j, p + j) == 1) 
                            return true;
                    }
                    return false;
                }

                index = kmpMatch(s + i , n - i, p + j, k - j, next);
                if(index == -1) {delete next ; return false; }
                i = i + index + k - j;
                j = k ;
            }else {delete next; return false; }
        }
        delete next;
        while(j < m && p[j] == '*') ++j;
        if(i < n ) return p[m-1] == '*';
        return j == m ;
    }
};

int main(){
   Solution sol ; 
   string a , b ;
   while(cin >> a >> b){
        cout << sol.isMatch(a.c_str(), b.c_str()) << endl;
   }
   return 0;
}