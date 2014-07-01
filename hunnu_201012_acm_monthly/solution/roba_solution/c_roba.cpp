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

int main() {
	freopen("1.std.in","r",stdin);
	freopen("1.roba.out","w",stdout);
	int T, i, n;
	scanf("%d",&T);
	assert(T >= 1 && T <= 1000);
	while (T--) {
		scanf("%d",&n);
		assert(n >= 1 && n <= 1000000000);
		LL s = 0;
		for (i = 1 ; ; i++)
			if ((i+1) * (i+1) <= n + 1)
				s += (LL)i * (2 * i + 1);
			else break;
		s += (LL)i * (n - i * i + 1);
		printf("%I64d\n",s);
	}
	return 0;
}
