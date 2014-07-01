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

const int MAXN = 200010;
int a[MAXN], cc[MAXN], L[MAXN], R[MAXN];

#define LOWBIT(x) ((x)&(-(x)))

int query(int k) {
	int s = 0;
	while (k) {
		s += cc[k];
		k -= LOWBIT(k);
	}
	return s;
}

void myadd(int k) {
	while (k < MAXN) {
		++cc[k];
		k += LOWBIT(k);
	}
}

int query2(int k) {
	int s = 0;
	while (k < MAXN) {
		s += cc[k];
		k += LOWBIT(k);
	}
	return s;
}

void myadd2(int k) {
	while (k) {
		++cc[k];
		k -= LOWBIT(k);
	}
}

int main() {
	freopen("1.std.in","r",stdin);
	int T, n, i;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		assert(n >= 1 && n <= 100000);
		for (i = 0 ; i < n ; i++) {
			scanf("%d",&a[i]);
			assert(a[i] >= 0 && a[i] <= 200000);
			++a[i];
		}
		CLEAR(cc, 0);
		for (i = 0 ; i < n ; i++) {
			L[i] = query(a[i]-1);

			myadd(a[i]);
		}
		CLEAR(cc, 0);
		LL ans = 0;
		for (i = n - 1 ; i >= 0 ; i--) {
			R[i] = query2(a[i]+1);
			myadd2(a[i]);
			/*
			R[i] = 0;
			for (int j = i + 1 ; j < n ; j++)
				if (a[i] < a[j]) ++R[i];
			*/
			ans += (LL)L[i] * R[i];
		}
		printf("%I64d\n",ans);
	}
	
	while(1);
	
	return 0;
}
