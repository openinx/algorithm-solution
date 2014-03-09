#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 500005;

int lx[maxn],ch[maxn],chs,ly[maxn];
int c[maxn],N;
int lowbit(int x) {   return x & (x ^ (x-1)); }

void add(int i,int del)
{   
     for( ; i <= chs ; c[i] += del, i += lowbit(i));
}

int  sum(int i)
{    
     int res = 0;
     for( ; i ; res += c[i] , i -= lowbit(i) );
     return res;
}

int bbs(int x)
{    
    int l,r,mid;    
    l = 1 ; r = chs ; 
    while(l <= r)
    {     
          mid = (l+r)/2;
          if(ch[mid] == x) return mid;
          if(x < ch[mid])  r = mid - 1;
          else  l =  mid + 1;
    }
    return -1;
}  

int main()
{    
     int i,j,pos  ;
     while(scanf("%d",&N)!=EOF  && N ) 
     {  
         for(i = 0; i< N; ++ i) {  scanf("%d",&lx[i]); ly[i] = lx[i]; }
         sort(lx,lx+N);
         ch[1] = lx[0] , chs = 1;
         for(i = 1 ; i < N; ++i) 
           if(lx[i] != ch[chs])  ch[++chs] = lx[i];
         
         memset(c,0,sizeof(c));
         __int64 res = 0; 
         for(i=0 ; i< N;++i)
         {   
                pos =chs - bbs(ly[i]) + 1; 
                res += (__int64)sum( pos - 1 );
                add(pos,1);
         }
         printf("%I64d\n",res);
     }
     return 0;
}
         
     
