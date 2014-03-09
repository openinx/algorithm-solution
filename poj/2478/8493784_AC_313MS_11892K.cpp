#include<stdio.h>
#define maxn 1000005
int n , vis[maxn] ;
__int64 euler[maxn];

int main(){
    int i , j; 
    for(i=1;i<maxn;++i)euler[i]=i,vis[i]=1;
    for(i=2;i<maxn;++i)if(vis[i]){
        for(j=i;j<maxn;j+=i) euler[j]=euler[j]-euler[j]/i,vis[j]=0;
    }
    for(i=3;i<maxn;++i)euler[i]+=euler[i-1] ;
    while(scanf("%d",&n)!=EOF&&n){
          printf("%I64d\n",euler[n]); 
    }
    return 0;
}
