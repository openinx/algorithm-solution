#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 1001
#define MAXM 100001

int gh[MAXN][MAXN], n , m, p[MAXM][3],psiz, v[MAXM][2], vsiz;
int in[MAXN];

typedef struct _tip{
    int type, start, end, dis;
}tip;

vector<tip> tips;

bool isCircle(){
    int cnt = 0;
    stackM<int> st;
    memset(in, 0 , sizeof(in));
    for(int i = 1; i <= n; ++ i){
        if(in[i] == 0){
            st.push(i);
        }
    }
    while(!st.empty()){
        int x = st.top(); st.pop();
        ++cnt;
        for(int i = 1 ; i <=n ; ++ i)
            if(gh[x][i] != -1){
                if(--in[i] == 0)
                    st.push(i);
            }
    }
    return cnt == n;
}

bool check(){
    int i , j, k;
    memset(gh, -1, sizeof(gh));
    memset(in, 0, sizeof(in));
    for(int i = 0 ; i < psiz; ++ i){
        int x = p[i][0], y = p[i][1] , z = p[i][2];
        gd[x][y] = z;
        in[y] ++ ;
    }
    if(!isCircle())
        return false;
}

int main(){
    int i , j;
    char word[2];
    while(scanf("%d%d", &n, &m) != EOF){
        psiz = vsiz = 0;
        for(i = 0; i < m; ++i){
            scanf("%s", word);
            if(word[0] == 'P'){
                scanf("%d%d%d", &p[psiz][0], &p[psiz][1], &p[psiz][2]);
                psiz ++ ;
            }else if(word[0] == 'V'){
                scanf("%d%d", &v[vsiz][0], &v[vsiz][1]);
                vsiz ++ ;
            }
        }
        if(check()){
            cout << "Reliable" << endl;
        }else{
            cout << "Unreliable" << endl;
        }
    }
    return 0;
}
