#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 20005;
struct node {
       int x,v;
};

node data[maxn]; 
int bfr[maxn],tot[maxn],n;

bool cmp(node a,node b)
{    
    return a.v < b.v;
}

int lowbit(int x) {   return x & (- x) ; }

void modify(int *c,int i,int del)
{    
     for( ; i<=maxn ; i += lowbit(i))  c[i] += del;
}

int getsum(int *c,int i)
{    
    int ret = 0;
    for( ; i ; i -= lowbit(i))  ret += c[i];
    return ret;
}

int main()
{    
     int cnt,dist,i,sum = 0;
     __int64 ans = 0;
     scanf("%d",&n);
     for( i = 1 ;i<=n;++i)  scanf("%d%d",&data[i].v, &data[i].x);
     sort(data+1, data+n+1,cmp);
     memset(bfr,0,sizeof(bfr));
     memset(tot,0,sizeof(tot));
     sum = 0;
     for(i = 1; i<=n;++i)
     {   
         cnt =  getsum(bfr,data[i].x);  // 包括了x 
         dist = getsum(tot,data[i].x);
         ans += (__int64) data[i].v * (__int64) (cnt*data[i].x - dist + sum -dist - (i-cnt-1)*data[i].x );
         sum += data[i].x;
         modify(bfr,data[i].x,1);
         modify(tot,data[i].x,data[i].x);
     }
     printf("%I64d\n",ans);
     return 0;
}
           
            
            
            
                
          
            



    
