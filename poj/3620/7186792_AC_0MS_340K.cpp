#include<iostream>
using  namespace std;

const int maxn= 105;
int N,M,K;
int g[maxn][maxn];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int out(int x,int y)  {  return x<1||y<1||x>N||y>M; }
inline int Max(int x,int y) { return x>y ? x:y ; }

int dfs(int x,int y)
{   
    int i,tp,cx,cy,ans=1;
    g[x][y]=0;
    for(i=0;i<4;++i)
    {   
        cx=x+dx[i]; cy=y+dy[i];
        if(out(cx,cy)||g[cx][cy]==0) continue;
        ans+=dfs(cx,cy);
    }
    return ans;
}

int main()
{   
    int i,j,x,y,ans=0;
    memset(g,0,sizeof(g));
    scanf("%d%d%d",&N,&M,&K);
    for(i=1;i<=K;++i)
    {      
           scanf("%d%d",&x,&y);
           g[x][y]=1;
    }
    for(i=1;i<=N;++i)
      for(j=1;j<=M;++j)
      if(g[i][j]==1) 
         ans=Max(ans,dfs(i,j));
    printf("%d\n",ans);
    return 0;
}
    
    
    
