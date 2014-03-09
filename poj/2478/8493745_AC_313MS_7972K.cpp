#include<stdio.h>
#define maxn 1000005
typedef __int64 lld ;
int n , euler[maxn] ,vis[maxn];

int main(){
    int i,j ;
    lld ans ; 
    for(i=1;i<maxn;++i)euler[i]=i,vis[i]=1;
    for(i=2;i<maxn;++i)if(vis[i]){
        for(j=i;j<maxn;j+=i) euler[j]=euler[j]-euler[j]/i,vis[j]=0;
    }
    while(scanf("%d",&n)!=EOF&&n){
          ans = 0 ;
          for(i=2;i<=n;++i) ans +=euler[i];
          printf("%I64d\n",ans); 
    }
    return 0;
}
