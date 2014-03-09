#include<iostream>
#include<queue>

using namespace std;

const int maxn = 220;
const int maxint = 100000000;

int cap[maxn][maxn],cost[maxn][maxn];
char mp[maxn][maxn];
int s,t,N ;

inline int _abs(int x) {  return x > 0 ? x : -x ; }

struct node{
       int x,y;
};
node P[maxn],Q[maxn];

int vis[maxn],d[maxn],pre[maxn];
bool spfa()
{
     int i,j,k,u,v;
     queue< int >  q;
     memset(vis,0,sizeof(vis));  memset(pre,-1,sizeof(pre));
     for(i=1; i<= N; ++i)  d[i] = maxint ;
     q.push(s) ; vis[s] = 1  ;  d[s]= 0;
     while(!q.empty())
     {     
            v = q.front() ; q.pop();  vis[v]= 0;
            for(i = 1 ; i<=N ; ++i)
               if( cap[v][i] > 0 && d[i] > d[v] + cost[v][i] )
               {
                    d[i] = d[v] + cost[v][i] ; pre[i] = v ;
                    if( ! vis[i] )  q.push(i) , vis[i] = 1;
               }
     }
     return d[t] < maxint  ;
}

int MinCostFlow()
{   
    int ans = 0 ,v;
    while(spfa())
    {    
         int del = maxint ;
         for(v = t ; v != s; v = pre[v] )  del = min(del,cap[ pre[v] ][ v ] ) ; 
         for(v = t ; v != s ;v = pre[v] ) { cap[ pre[v] ][ v ] -= del , cap[ v ][ pre[v] ] += del; }
         ans += del * d[t];
    } 
    return ans;
}

int main()
{   
    int n,m,i,j,xs,ys;
    //freopen("in02.txt","r",stdin); freopen("MyOut.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF && n  && m )
    {
          for(i=0;i<n;++i)  scanf("%s",mp[i]);
          xs = ys = 0;
          for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            if(mp[i][j]=='H')    P[++xs].x = i, P[xs].y = j; 
            else  if(mp[i][j] == 'm' )  Q[++ys].x = i, Q[ys].y = j; 
          n = xs;
          memset(cost , 0 , sizeof( cost ));
          memset(cap  , 0 , sizeof( cap  ));
          for(i = 1 ; i<=n ; ++i)
            for(j = 1; j<=n; ++j )
            {
                 cost[i][n+j]=_abs(P[i].x - Q[j].x ) + _abs(P[i].y - Q[j].y);
                 cost[ n+j ][ i ] = - cost[ i ][ n+j ];
                 cap[i][n+j]=1;
            }
          s = 2*n+1 , t = 2*n+2;
          for(i = 1;i<=n;++i)  cap[s][i] = 1 ;
          for(j = n + 1 ; j <= 2*n; ++j) cap[j][t] = 1;
          N = 2*n + 2;
          int mincost = MinCostFlow();
          printf("%d\n",mincost);
    }
    //fclose(stdin);  fclose(stdout);
    return 0;
} 
