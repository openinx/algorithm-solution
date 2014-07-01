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

const char name[][20] = {
	"January",
	"February",
	"March",
	"April", "May", "June", "July", "August", "September", "October", "November", "December"
};

int main() {
	freopen("2.std.in","r",stdin);
	freopen("2.roba.out","w",stdout);
	int i, d;
	char buf[128];
	while (scanf("%s%d",&buf,&d) != EOF) {
		for (i = 0 ; i < 12 ; i++)
			if (strcmp(buf, name[i]) == 0) break;
		assert(i < 12);
		printf("%s\n",name[(i+d)%12]);
	}
	return 0;
}
