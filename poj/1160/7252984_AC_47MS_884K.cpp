#include<stdio.h>
#define _size 305
#define maxint 100000000

int dist[_size];
int opt[_size][_size],cost[_size][_size];
int n,k;

inline int MAX(int a,int b) { return a>b ? a:b;}
inline int MIN(int a,int b) { return a<b ? a:b;}

void init()
{    int i,j,t;
     for(i=1;i<=n+1;++i)
       for(j=i+1;j<=n+1;++j)
       {    cost[i][j]=0;
            for(t=i+1;t<j;++t)
             cost[i][j]+=MIN(dist[t]-dist[i],dist[j]-dist[t]);
       }
}


void dp()
{    int i,j,t,ans=maxint;
     opt[0][1]=dist[0]=0;
     for(i=1;i<=n;++i)  opt[i][1]=opt[i-1][1]+(i-1)*(dist[i]-dist[i-1]);
     for(i=1;i<=k;++i) opt[i][i]=0;
     for(i=3;i<=n;++i)
        for(j=2;j<=MIN(i,k);++j)
        {    opt[i][j]=maxint;
             for(t=j-1;t<i;++t)
               opt[i][j]=MIN(opt[i][j],opt[t][j-1]+cost[t][i]);
        }
     for(i=k;i<=n;++i)
       ans=MIN(ans,opt[i][k]+cost[i][n+1]);
     printf("%d\n",ans);
}
int main()
{       int i,tc=0;
        while(scanf("%d%d",&n,&k)!=EOF&&n&&k)
        {      for(i=1;i<=n;++i)
                    scanf("%d",&dist[i]);
               dist[0]=0;
               dist[n+1]=2*maxint;
               init();
               dp();
        }
        return 0;
}

