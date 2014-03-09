#include<stdio.h>
#define m 1000005
__int64 e[m];
int v[m];
int main(){
    int i,j,n; 
    for(i=1;i<m;++i)e[i]=i,v[i]=1;
    for(i=2;i<m;++i)if(v[i]){
        for(j=i;j<m;j+=i) e[j]=e[j]-e[j]/i,v[j]=0;
    }
    for(i=3;i<m;++i)e[i]+=e[i-1] ;
    while(scanf("%d",&n)!=EOF&&n){
          printf("%I64d\n",e[n]); 
    }
    return 0;
}
