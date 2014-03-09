#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
#define maxn  205 
#define maxint 100000000
using namespace std;

int c[maxn][maxn];
int E,N,st[maxn];

bool Read(){
     int i,j,k,x,y,z;
     if(scanf("%d%d",&E,&N)==EOF) return false;
     for(i=1;i<=N;++i)
       for(j=1;j<=N;++j)
        c[i][j]=0;
     for(i=1;i<=E;++i){
        scanf("%d%d%d",&x,&y,&z);
        c[x][y]+=z;
     }
     return true;
}

int solve(){
     int v,u,ans=0,del;
     while(1){
         queue<int>Q;
         memset(st,-1,sizeof(st));
         Q.push(1); 
         while(!Q.empty()){ 
              v = Q.front(); Q.pop();
              for(u=1;u<=N && st[N]<0 ; ++u)
                  if(c[v][u] && st[u]<0 ) st[u]=v , Q.push(u); 
              if(st[N]!=-1) break;
         }
         if(st[N]==-1) break;
         del = maxint;
         for(u=st[v=N];v!=1;v=u,u=st[u])  del = min(del,c[u][v]);
         for(u=st[v=N];v!=1;v=u,u=st[u]) c[u][v]-=del , c[v][u]+=del;
         ans += del;
     }
     return ans;
}

             
int main(){
    while(Read()) printf("%d\n",solve());
    return 0;
}
     
