#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

const static int MAXN = (1<<16) - 1;
const static int MAXLEN = 21;

char ss[MAXN][MAXLEN];

int hash(char *s){
    int val = 0 ;
    while(*s){
        val = (val << 5) + val + (*s++);
        val &= MAXN;
    }
    return val & MAXN;
}

typedef struct _Val{
    char *s;
    int cnt;
    _Val(char *_s, int _cnt):
        s(_s),cnt(_cnt){}
}Val;


class HashMap{
    typedef list<Val> chain;
public:
    void insert(char *s){
        int t = hash(s);
        int cnt = 1;
        for(chain::iterator it = slot[t].begin(); it != slot[t].end(); ++it){
            if(!strcmp(it->s, s)){
                cnt = it->cnt + 1;
                slot[t].erase(it);
                break;
            }
        }
        slot[t].push_front(Val(s, cnt));
    }

    void calc(int n, vector<int> &ans){
        ans.resize(n);
        fill(ans.begin(), ans.end(), 0);
        for(int i = 0 ; i < MAXN; ++ i){
            for(chain::iterator it = slot[i].begin();
                    it!=slot[i].end(); ++ it){
                ans[it->cnt] ++ ;
            }
        }
    }

    void clear(){
        for(int i = 0 ; i < MAXN; ++ i)
            slot[i].clear();
    }
private:
    chain slot[MAXN];
};

int main(){
    int n, m ; 
    HashMap map;
    vector<int> ans;
    while(scanf("%d%d", &n, &m) != EOF && (n | m)){
        map.clear();
        for(int i = 0; i < n ; ++ i){
            scanf("%s", ss[i]);
            map.insert(ss[i]);
        }
        map.calc(n+1, ans);
        for(int i = 1 ; i <= n; ++ i)
            cout << ans[i] << endl;
    }
    return 0 ;
}
