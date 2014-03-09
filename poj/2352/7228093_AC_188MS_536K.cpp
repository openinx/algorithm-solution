#include<iostream>
using namespace std;
const int maxn = 32005;

int n;
int out[maxn],f[maxn],c[maxn];

int lowbit(int x)  {   return x & (x ^ (x-1)) ;  }

void add(int i,int del)
{    
     for( ; i<=maxn-1;  c[i] += del , i += lowbit(i));
}

int sum(int i)
{    
     int res = 0;
     for( ; i ; res += c[i], i -= lowbit(i));
     return res;
}

int main()
{     
     int i,x,y;
     scanf("%d",&n);
     memset(c,0,sizeof(c));
     memset(f,0,sizeof(f));
     memset(out,0,sizeof(out));
     for(i=0;i<n;++i)
     {   
           scanf("%d%d",&x,&y);  x ++;
           add(x,1);
           out[sum(x-1)+f[x]] ++;
           ++f[x];
     }
     for(i= 0;i<n;++i)  printf("%d\n",out[i]);
     return 0;
}
           
     
     
     
