#include<iostream>
using namespace std;

const int maxn = 12885;
inline int Max(int a,int b) {return a > b ? a:b;}

int f[maxn];
int main()
{    
     int i,j,N,M,w,d;
     scanf("%d%d",&N,&M);
     memset(f,0,sizeof(f));
     for(i=1;i<=N;++i)
     {    
          scanf("%d%d",&w,&d);
          for(j=M; j>=w ; --j) f[j]=Max(f[j],Max(f[j-1],f[j-w]+d));
     }
     printf("%d\n",f[M]);
     return 0;
}
