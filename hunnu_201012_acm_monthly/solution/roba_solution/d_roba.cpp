#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define CLEAR(a,v) memset((a), (v), sizeof(a))

const double eps = 1e-9;
const int INF = 1000000000;
const long long LLINF = (long long)INF * INF;
const double PI = 2 * acos(.0);

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int MAXN = 128;
const int dir[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m;
int dis[MAXN][MAXN], q[MAXN*MAXN][2];
char buf[MAXN][MAXN];
int step[1000010];

void bfs(int sx, int sy) {
	int qh, qt, d;
	CLEAR(dis, 0x3f);
	dis[sx][sy] = 0;
	q[0][0] = sx; q[0][1] = sy;
	for (qh = 0, qt = 1 ; qh < qt ; ++qh) {
		for (d = 0 ;d < 4 ; d++) {
			int tx = q[qh][0] + dir[d][0];
			int ty = q[qh][1] + dir[d][1];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			if (buf[tx][ty] == '*' || dis[tx][ty] < INF)
				continue;
			dis[tx][ty] = dis[q[qh][0]][q[qh][1]] + 1;
			q[qt][0] = tx; q[qt++][1] = ty;
		}
	}
}

int main() {
	freopen("1.std.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--) {
		int K,i,j;
		int tx, ty, jx, jy;
		scanf("%d%d%d",&n,&m,&K);
		assert(n >= 1 && n <= 100);
		assert(m >= 1 && m <= 100);
		int ct = 0, cj = 0;
		for (i = 0 ; i < n ; i++) {
			scanf("%s",buf[i]);
			assert(strlen(buf[i]) == m);
			for (j = 0 ; j < m ; j++)
				if (buf[i][j] == 'T') {tx = i; ty = j; ++ct;}
				else if (buf[i][j] == 'J') {jx = i; jy = j; ++cj;}
		}
		assert(ct == 1 && cj == 1);
		bfs(tx, ty);
		int flg = 0;
		for (i = 0 ; i < K ; i++) {
			scanf("%d",&step[i]);
			jx += dir[step[i]][0];
			jy += dir[step[i]][1];
			//printf("jx:%d jy:%d m:%d n:%d\n",jx,jy,m,n);
			assert(jx >= 0 && jx < n && jy >= 0 && jy < m);
			assert(buf[jx][jy] != '*');
			if (dis[jx][jy] <= (i+1) && (i+1-dis[jx][jy]) % 2 == 0) flg = 1;
		}
		if (flg) printf("Yes\n");
		else printf("No\n");
	}
	
	//while(1);
	
	return 0;
}
