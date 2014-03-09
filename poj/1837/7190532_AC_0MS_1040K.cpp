#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxn = 7505;
int opt[30][7505];

int main()
{   
     int C,G,i,j,k,x[30],w[30],sum;
     while(scanf("%d%d",&C,&G)!=EOF)
     {      
            sum=0;
            for(i=1;i<=C;++i) { scanf("%d",&x[i]); x[i]+=15;}
            for(i=1;i<=G;++i) { scanf("%d",&w[i]); sum+=15*w[i];}
            memset(opt,0,sizeof(opt));
            for(i=1;i<=C;++i)  opt[1][w[1]*x[i]]=1;
            for(i=2;i<=G;++i)
                 for(j=0;j<=sum;++j)
                      for(k=1;k<=C;++k)
                   {   
                       if(j-w[i]*x[k]<0) continue;
                       opt[i][j]+=opt[i-1][j-w[i]*x[k]];
                   }
           printf("%d\n",opt[G][sum]);
     }
     return 0;
}   


