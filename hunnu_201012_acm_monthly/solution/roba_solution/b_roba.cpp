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

int a[128], b[128];

int calc(int a, int b) {
	int s = 0;
	while (a || b) {
		if ((a & 1) != (b & 1)) ++s;
		a >>= 1; b >>= 1;
	}
	return s;
}

int main() {
	freopen("2.std.in","r",stdin);
	freopen("2.roba.out","w",stdout);
	int T, m, n, i;
	scanf("%d",&T);
	assert(T <= 100);
	while (T--) {
		scanf("%d%d",&m,&n);
		assert(m > 0 && m <= 100);
		assert(n > 0 && n <= 100);
		for (i = 0 ;i < m ; i++) {
			scanf("%d",&a[i]);
			assert(a[i] <= 1000000);
		}
		for (i = 0 ;i < n ; i++) {
			scanf("%d",&b[i]);
			assert(b[i] <= 1000000);
		}
		for (int j = 0 ; j < n ; j++) {
			int mi = INF, ans;
			for (int i = 0 ; i < m ; i++) {
				int tmp = calc(a[i], b[j]);
				if (tmp < mi || (tmp == mi && a[i] < ans)) {
					mi = tmp;
					ans = a[i];
				}
			}
			printf("%d\n",ans);
		}

	}
	return 0;
}
