#include<iostream>
#include<queue>
#define maxn 205
#define maxint 200000000
using namespace std;
int c[maxn][maxn];
int E,N,st[maxn];

int maxflow(){
    int i,v,u,ans=0,del;
    while(1){ 
        memset(st,-1,sizeof(st));
        queue<int>q ;  q.push(1); 
        while(!q.empty()){
          v = q.front(); q.pop();
          for(i=1;i<=N && st[N]==-1 ;++i)
          if(c[v][i] && st[i]<0 ) st[i]=v,q.push(i);
          if(st[N]!=-1) break;
        }
        if(st[N]==-1) break;
        del = maxint;
        for(u=st[v=N];v!=1 ; v=u,u=st[u]) del = min(del,c[u][v]);
        for(u=st[v=N];v!=1 ; v=u,u=st[u]) c[u][v]-=del,c[v][u]+=del;
        ans+=del;
    }
    return ans;
}
       
int main(){
    int i,j,x,y,z;
    while(scanf("%d%d",&E,&N)!=EOF){
      memset(c,0,sizeof(c));
      for(i=1;i<=E;++i){
        scanf("%d%d%d",&x,&y,&z);
        c[x][y]+=z;
      }
      printf("%d\n",maxflow());
    }
    return 0;
}
                          
