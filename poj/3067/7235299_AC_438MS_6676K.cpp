#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1001;

struct node {
       int l,r;
};
node p[maxn*maxn];
int c[maxn*maxn];
int N,M,K;

bool cmp(node a,node b)
{    
     if(a.l !=  b.l) return a.l < b.l ;
     return a.r < b.r ; 
}

int lowbit(int x) {  return x & (x ^ (x - 1)) ; }

void add(int i,int del)
{    
     for( ; i<= M ;  i +=lowbit(i)) c[i] += del;
}

int sum(int i)
{   
    int ret = 0;
    for(  ; i ; i-=lowbit(i) ) ret += c[i];
    return ret;
}  

int main()
{   
     int cas,i ;
     int Test = 0;
     scanf("%d",&cas);
     while(cas--)
     {     
           scanf("%d%d%d",&N,&M,&K);
           for(i=0;i<K;++i)  scanf("%d%d",&p[i].l,&p[i].r);
           memset(c,0,sizeof(c));
           __int64 ans = 0;
           sort(p,p+K,cmp);
           for(i = 0 ;i < K ;++i)
           {    
                int pos = M - p[i].r + 1;
                ans += (__int64)sum(pos - 1);
                add( pos ,1); 
           }
           printf("Test case %d: %I64d\n",++Test,ans);
     }
     return 0;
}
                
     
