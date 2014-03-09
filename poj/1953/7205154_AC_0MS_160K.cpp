#include<stdio.h>
#define maxn 50
typedef  __int64 i64;
i64 f[maxn];
int main()
{    
     i64 i,cas,x,t=0;
     f[0] = 1;
     f[1] = 2;
     for(i=2;i<=45;++i)  f[i]=f[i-1]+f[i-2];
     scanf("%I64d",&cas);
     while(cas--){
                   scanf("%I64d",&x);
                   printf("Scenario #%I64d:\n%I64d\n\n",++t,f[x]);
     }
     return 0;
}
     
