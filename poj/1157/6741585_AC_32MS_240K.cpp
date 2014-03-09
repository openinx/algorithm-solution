#include<stdio.h>
#include<stdio.h>
#define MAX(a,b) ((a) > (b) ? (a):(b))
int main()
{   long i,j,V,F;
    long a[105][105],g[105][105];
    while(scanf("%ld%ld",&V,&F)!=EOF)
    {   for(i=1;i<=V;++i)
           for(j=1;j<=F;++j)
           scanf("%ld",&a[i][j]);
       g[1][1]=a[1][1];
       for(i=2;i<=V;++i) g[i][i]=g[i-1][i-1]+a[i][i];
       for(i=2;i<=F;++i)
         g[1][i]=MAX(a[1][i],g[1][i-1]);
       for(i=2;i<=V;++i)
          for(j=i+1;j<=F;++j)
          g[i][j]=MAX(g[i-1][j-1]+a[i][j],g[i][j-1]);
       printf("%ld\n",g[V][F]);
    }
    return 0;
}                
