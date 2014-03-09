#include<iostream>
using namespace std;


const int maxint = (1<<30);
const int maxn = 105;
int opt[maxn][maxn];
int in[maxn][maxn],out[maxn][maxn];

int main()
{   
    int n,m,i,j,tp,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {   
        if(n==0&&m==0) break;
        for(i=1;i<=n;++i)
           for(j=1;j<=n;++j)
           scanf("%d",&out[i][j]);
        for(i=1;i<=m;++i)
           for(j=1;j<=n;++j)
           scanf("%d",&in[i][j]);
        for(i=1;i<=n;++i) opt[0][i]=-maxint;
        opt[0][1]=0;
        for(i=1;i<=m;++i)
           for(j=1;j<=n;++j)
           {   
               opt[i][j]=-maxint;
               for(k=1;k<=n;++k) 
                if(opt[i-1][k]!= -maxint)
                { 
                  tp=opt[i-1][k]-out[k][j]+in[i][j];
                  if(tp>opt[i][j])  opt[i][j]=tp;                       
                }
           }
       int ans=-maxint;
       for(i=1;i<=n;++i)
         if(opt[m][i]>ans)  ans = opt[m][i];
       printf("%d\n",ans); 
    }
    return 0;
}
                                   
