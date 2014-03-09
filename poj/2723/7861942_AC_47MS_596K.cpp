#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define N 4508 /*顶点总数，包括拆点以后的*/
#define M 2050
#define inf 0x7ffffff
struct node {
    int a, b;
    node(int aa = 0, int bb = 0) : a(aa), b(bb) {}
};
node key[M / 2];
node door[M];
vector<int>g[N]; /*邻接表*/
int n, m; /*顶点数，边数*/
int id[N], pre[N], low[N], s[N], stop, cnt, scnt;
void tarjan(int v, int n) { /*求强连通分量，vertex: 0 ~ n-1*/
    int t, minc = low[v] = pre[v] = cnt++;
    s[stop++] = v;
    for (int i = 0; i < g[v].size(); i++) {
        if (-1 == pre[g[v][i]]) tarjan(g[v][i], n);
        if (low[g[v][i]] < minc) minc = low[g[v][i]];
    }
    if (minc < low[v]) { low[v] = minc; return; }
    do { id[t = s[--stop]] = scnt; low[t] = n; } while (t != v);
    ++scnt; /*联通分量个数*/
}
bool _2sat() {
    stop = cnt = scnt = 0;
    memset(pre, -1, sizeof (pre));
    for (int i = 0; i < n; ++i) if (-1 == pre[i]) tarjan(i, n);
    n /= 2;
    for (int i = 0; i < n; i++) if (id[i] == id[i + n]) return 0;
    return 1;
}
void add(int a, int b) {
    g[a].push_back(b);
}
void build(int mid) {
    int a, b;
    int k = n * 2;
    for (int i = 0; i < k; i++) g[i].clear(), g[i + k].clear();
    for (int i = 0; i < n; i++) {
        a = key[i].a,b = key[i].b;
        add(a, b + k);
        add(b, a + k);
    }
    for (int i = 0; i < mid; i++) {
        a = door[i].a, b = door[i].b;
        add(a + k, b);
        add(b + k, a);
    }
    n = k + k;
}
void read() {
    int a, b;
    for (int i = 0; i < n; key[i] = node(a, b), i++)
        scanf("%d%d", &a, &b);
    for (int i = 0; i < m; door[i] = node(a, b), i++)
        scanf("%d%d", &a, &b);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) return 0;
        read();
        int l = 0, r = m,mid,ans;
        while (l <= r) {
            mid = (r + l) / 2;
            build(mid);
            if (_2sat()) 
            {
                ans=mid;
                l = mid + 1;
            }
            else r = mid - 1;
            n /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}