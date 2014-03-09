#include<stdio.h>
#define size 101
#define MAX(a,b)((a)>(b) ?  (a):(b))
int d[size][size];
int main()
{   int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {     for(i=1;i<=n;++i)
             for(j=1;j<=i;++j) scanf("%d",&d[i][j]);
          for(i=n-1;i>=1;i--)
          {   for(j=1;j<=i;++j)
              d[i][j]+=MAX(d[i+1][j],d[i+1][j+1]);
          }
          printf("%d\n",d[1][1]);
    }
    return 0;
}             
              
