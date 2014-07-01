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
int a[MAXN][MAXN], dis[2][MAXN];

int main() {
	freopen("1.std.in","r",stdin);  freopen("1.std.out" ,"w" ,stdout);
	int CA, n, m, A, B;
	scanf("%d",&CA);
	while (CA--) {
		scanf("%d%d",&n,&m);
		assert(n >= 1 && n <= 100);
		assert(m >= 1 && m <= 10000);
		scanf("%d%d",&A,&B);
		assert(1 <= A && A <= B && B <= 1000000);
		CLEAR(a, 0x3f);
		while (m--) {
			int x, y, w;
			scanf("%d%d%d",&x,&y,&w);
			assert(x >= 1 && x <= n);
			assert(y >= 1 && y <= n);
			assert(w >= 1 && w <= 100);
			--x; --y;
			a[x][y] <?= w;
			a[y][x] <?= w;
		}
		CLEAR(dis, 0x3f);
		dis[0][0] = 0;
		int from = 0, to = 1;
		int ans = INF;
		for (int t = 1 ; t <= B ; t++) {
			CLEAR(dis[to], 0x3f);
			for (int i = 0 ; i < n ; i++)
				for (int j = 0 ; j < n ; j++)
					if (a[i][j] < INF && dis[to][j] > dis[from][i] + a[i][j])
						dis[to][j] = dis[from][i] + a[i][j];
			from = 1 - from;
			to = 1 - to;
			if (t >= A) ans <?= dis[from][n-1];
		}
		if (ans >= INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	
	fclose(stdout) ; fclose(stdin);
	
	return 0;
}
