#include<stdio.h>
#include<stdlib.h>
#define size 103
int n,area;
bool g[size][size];
bool visit[size];        
bool read()
{    char c;
     int v,u,i,j;
     scanf("%d",&n);
     if(n==0) return false;
     for(i=1;i<=n;++i)
       for(j=1;j<=n;++j) g[i][j]=false;
     scanf("%d%c",&v,&c);
     while(v)
     {    u=v;
          do
          { scanf("%d%c",&v,&c);
            g[u][v]=g[v][u]=true;
          }while(c!='\n');
          scanf("%d%c",&v,&c);   
     }
     return true;
}
void dfs(int s)
{    visit[s]=true;
     int i;
     for(i=1;i<=n;++i)
      if(!visit[i]&&g[s][i])  dfs(i);
}      
void solve()
{   int i,j,count=0;
    for(i=1;i<=n;++i)
    {   for(j=1;j<=n;++j) visit[j]=false;
        visit[i]=true;
        area=0;
        for(j=1;j<=n;++j)
        if(!visit[j])
          { dfs(j);
            ++area;
            if(area>1) break;
          }
        if(area>1) count++;
    }
    printf("%d\n",count);    
}        
int main()
{    while(read()) solve();
     //system("pause");
     return 0;
}       
