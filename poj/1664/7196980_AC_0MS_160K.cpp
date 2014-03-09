#include<iostream>
using namespace std;

int f[11][11];

int main()
{   
    int i,j,cas,ans,n,m;
    for(i=0;i<11;++i)  f[0][i]=1;
    for(i=1;i<11;++i)  f[i][1]=f[1][i]=1;
    for(i=2;i<11;++i)
    {   
        for(j=2;j<=i;++j)  f[i][j]=f[i][j-1]+f[i-j][j];
        for(j=i+1;j<11;++j) f[i][j]=f[i][j-1];
    }
    scanf("%d",&cas);
    while(cas--)
    {    
          scanf("%d%d",&n,&m);
          printf("%d\n",f[n][m]);
    }
    return 0;
}
          
