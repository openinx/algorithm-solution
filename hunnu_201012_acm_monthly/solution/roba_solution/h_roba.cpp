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
const double DINF = 1e100;
const long long LLINF = (long long)INF * INF;
const double PI = 2 * acos(.0);

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXE = 101000;
const int MAXM = 2200;
const int MAXN = 2200;
struct Enode {int u, v, next, dup; double c;};

class Graph {
public:
	void init(int V, int S, int T);
	void add_edge(int u, int v, double cap);
	double dinic();
	Enode e[MAXE];
	int V, S, T, pe, head[MAXN];
	vector<int> get_cut();
private:
	int lay[MAXN], q[MAXN], cur[MAXN];
	int build();
	double argument();
};

void Graph::init(int pV, int pS, int pT) {
	memset(head, -1, sizeof(head)); pe = 0;
	V = pV; S = pS; T = pT;
}

void Graph::add_edge(int u, int v, double c) {
	e[pe].dup = pe+1; e[pe+1].dup = pe;
	e[pe].u = u; e[pe].v = v; e[pe].c = c;
	e[pe].next = head[u]; head[u] = pe++;
	e[pe].u = v; e[pe].v = u; e[pe].c = 0;
	e[pe].next = head[v]; head[v] = pe++;
};

int Graph::build() {
	int qh, qt, pe;
	memset(lay, -1, sizeof(lay));
	for (qh = 0, qt = 1, q[0] = S, lay[S] = 0 ; qh < qt ; ++qh)
		for (pe = head[q[qh]] ; pe != -1 ; pe = e[pe].next)
			if (fabs(e[pe].c) > eps && lay[e[pe].v] == -1) {
				lay[e[pe].v] = lay[q[qh]] + 1;
				if ((q[qt++] = e[pe].v) == T) return 1;
			}
	return 0;
}

double Graph::argument() {
	int i, len = 0, u = S;
	double flow = .0;
	for (i = 0 ; i < V ; i++) cur[i] = head[i];
	while (len >= 0) {
		if (u != T) {
			int t;
			for (t = cur[u] ; t != -1 ; t = e[t].next)
				if (fabs(e[t].c) > eps && lay[e[t].v] == lay[u] + 1)
					break;
			if ((cur[u] = t) == -1) {
				if (len == 0) break;
				lay[u] = -1; u = e[q[--len]].u;
			} else u = e[q[len++] = t].v;
		} else {
			double delta = DINF;
			int pos;
			for (i = 0 ; i < len ; i++)
				if (e[q[i]].c < delta)
					delta = e[q[pos = i]].c;
			flow += delta;
			for (i = 0 ; i < len ; i++) {
				e[q[i]].c -= delta;
				e[e[q[i]].dup].c += delta;
			}
			u = e[q[len = pos]].u;
		}
	}
	return flow;
}

double Graph::dinic() {
	double ans;
	for (ans = 0 ; build() ; ans += argument()) ;
	return ans;
}

vector<int> Graph::get_cut() {
	vector<int> res;
	int p, qh = 0, qt = 1;
	memset(lay, -1, sizeof(lay));
	lay[S] = 1; res.push_back(S);
	for ( ; qh < qt ; ++qh) {
		for (p = head[q[qh]] ; p != -1 ; p = e[p].next) {
			if (e[p].c && lay[e[p].v] == -1) {
				lay[e[p].v] = 1;
				res.push_back(e[p].v);
				q[qt++] = e[p].v;
			}
		}
	}
	return res;
}

Graph G;
struct EDGE {int u, v, c;} ee[MAXM];
int m, n;
int p[MAXN];

int check(double g) {
	//printf("g:%lf\n",g);
	int S = n + m, T = S+1, V = T+1, i;
	double tc = .0;
	G.init(V, S, T);
	for (i = 0 ; i < m ; i++) {
		G.add_edge(S, i, ee[i].c);
		G.add_edge(i, ee[i].u + m, DINF);
		G.add_edge(i, ee[i].v + m, DINF);
		tc += ee[i].c;
	}
	for (i = 0 ; i < n ; i++)
		G.add_edge(i + m, T, g * p[i]);
	double f = G.dinic();
	double ans = tc - f;
	return ans > eps;
}

int main() {
	//freopen("1.std.in","r",stdin); freopen("1.std.out" ,"w" ,stdout);  clock_t start = clock();
	int CA, i;
	scanf("%d",&CA);
	while (CA--) {
		scanf("%d%d",&n,&m);
		assert(n >= 1 && n <= 100);
		assert(m >= 1 && m <= 2000);
		for (i = 0 ; i < n ; i++) {
			scanf("%d",&p[i]);
			assert(p[i] >= 1 && p[i] <= 100);
		}
		for (i = 0 ; i < m ; i++) {
			scanf("%d%d%d",&ee[i].u,&ee[i].v,&ee[i].c);
			assert(ee[i].u >= 1 && ee[i].u <= n);
			assert(ee[i].v >= 1 && ee[i].v <= n);
			assert(ee[i].c >= 1 && ee[i].c <= 100);
			--ee[i].u; --ee[i].v;
		}
		double lo = 0, hi = 1e10;
		while (hi - lo > eps) {
			double mid = (hi + lo) / 2;
			if (check(mid)) lo = mid;
			else hi = mid;
		}
		printf("%.3lf\n",(hi+lo)/2);
	}
	
	//clock_t end = clock() ;  printf("Time : %d ms \n" , int(end - start)) ; fclose(stdin) ; fclose(stdout);
	
	return 0;
}
/*
int main() {
	int n;
	while (scanf("%d",&n),n) {
		int V, S, T, i, tmp, tot = 0;
		S = n; T = n+1; V = T+1;
		g.init(V, S, T);
		for (i = 0 ; i < n ; i++) {
			scanf("%d",&tmp);
			if (tmp > 0) {g.add_edge(S, i, tmp); tot += tmp;}
			else if (tmp < 0) g.add_edge(i, T, -tmp);
			int len, t2;
			scanf("%d",&len);
			while (len--) {
				scanf("%d",&t2);
				g.add_edge(i, t2-1, INF);
			}
		}
		int ans = tot - g.dinic();
		if (ans <= 0) printf("Refused\n");
		else {
			vector<int> pts = g.get_cut();
			printf("%d %d\n",ans,pts.size()-1);
			for (i = 0 ; i < pts.size() ; i++)
				if (pts[i] != S) printf("%d ",pts[i]+1);
			printf("\n");
		}
	}
}
*/
