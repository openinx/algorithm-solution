#include<iostream>
using namespace std;
const int maxn = 100005;
int f[maxn];

inline int Max(int x,int y) { return x>y ? x:y ; }

int main()
{    
     int i,j,k,t,cash,N,n,v,cn,cv;
     while(scanf("%d%d",&cash,&N)!=EOF)
     {  
           for(i = 0; i <= cash; f[i] = 0, ++i);
           for(i=1;i<=N;++i)
           {     
                 scanf("%d%d",&n,&v);
                 if(v==0) continue;
                 for(k=1 ,t=0 ; (k<<1)<=n ; k<<=1)
                 {   
                     t+=k;  cn = cv = k * v;
                     for(j = cash ; j >= cn ;--j)   f[j]=Max(f[j],Max(f[j-1],f[j-cn]+cv));
                 }
                 cn = cv = (n-t)*v;
                 for(j = cash ; j >=cn ;--j)   f[j]=Max(f[j],Max(f[j-1],f[j-cn]+cv)); 
           }
           printf("%d\n",f[cash]);
     }
     return 0;
}
           
