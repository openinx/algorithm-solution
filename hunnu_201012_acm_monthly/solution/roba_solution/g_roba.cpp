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

const int MAXN = 512;
const int BASE1 = 31;
const int BASE2 = 7;
const int BASE3 = 37;
const int BASE4 = 991;
char buf[MAXN][MAXN];
int m, n;
set<pair<int,int> > si;

int rv[MAXN][MAXN], rv2[MAXN][MAXN];
int check(int mid) {
	//printf("check:%d\n",mid);
	si.clear();
	int i, j, p1 = 1, p2 = 1, p3 = 1, p4 = 1;
	for (i = 0 ; i < mid - 1 ; i++) {
		p1 *= BASE1;
		p2 *= BASE2;
		p3 *= BASE3;
		p4 *= BASE4;
	}
	for (i = 0 ; i < n ; i++) {
		int tmp = 0, tmp2 = 0;
		for (j = 0 ; j < mid ; j++) {
			tmp *= BASE1;
			tmp += buf[i][j] - 'a' + 1;
			tmp2 *= BASE3;
			tmp2 += buf[i][j] - 'a' + 1;
		}
		rv[i][j-mid] = tmp;
		rv2[i][j-mid] = tmp2;
		for ( ; j < m ; j++) {
			tmp -= p1 * (buf[i][j-mid] - 'a' + 1);
			tmp *= BASE1;
			tmp += buf[i][j] - 'a' + 1;
			rv[i][j-mid+1] = tmp;

			tmp2 -= p3 * (buf[i][j-mid] - 'a' + 1);
			tmp2 *= BASE3;
			tmp2 += buf[i][j] - 'a' + 1;
			rv2[i][j-mid+1] = tmp2;
		}
	}
	for (j = 0 ; j < m - mid + 1 ; j++) {
		int tmp = 0, tmp2 = 0;
		for (i = 0 ; i < mid ; i++) {
			tmp *= BASE2;
			tmp += rv[i][j];

			tmp2 *= BASE4;
			tmp2 += rv2[i][j];
		}
		//printf("tmp:%d\n",tmp);
		if (si.count(MP(tmp,tmp2))) return 1;
		si.insert(MP(tmp,tmp2));
		for ( ; i < n ; i++) {
			tmp -= rv[i-mid][j] * p2;
			tmp *= BASE2;
			tmp += rv[i][j];
			//printf("tmp:%d\n",tmp);

			tmp2 -= rv2[i-mid][j] * p4;
			tmp2 *= BASE4;
			tmp2 += rv2[i][j];
			//printf("tmp:%d\n",tmp);
			if (si.count(MP(tmp,tmp2))) return 1;
			si.insert(MP(tmp,tmp2));
		}
	}
	return 0;
}

int main() {
//	freopen("1.std.in","r",stdin);  freopen("1.std.out" ,"w" ,stdout);  clock_t start = clock(), end ; 
	int T, i;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
//		assert(n >= 1 && n <= 500);
//		assert(m >= 1 && m <= 500);
		for (i = 0 ; i < n ; i++) {
			scanf("%s",buf[i]);
//			assert(strlen(buf[i]) == m);
			for (int j = 0 ; j < m ;j++) {
//				assert(buf[i][j] >= 'a' && buf[i][j] <= 'z');
			}
		}
		int lo = 1, hi = min(m,n), ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (check(mid)) {
				ans >?= mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		printf("%d\n",ans);
	}	
	
//	end = clock() ;  printf("%d" , int(end - start));
//	fclose(stdin);  fclose(stdout); 
	
	return 0;
}
