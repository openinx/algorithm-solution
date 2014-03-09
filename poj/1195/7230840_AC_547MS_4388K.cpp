#include<iostream>
using namespace std;

const int maxn = 1050;
int c[maxn][maxn];
int n;

inline int lowbit(int x) {  return x & (x ^ ( x-1 )); }

void modify(int x,int y,int del)
{      
       int i,j;
       for (i = x ; i <= n; i += lowbit(i))
          for(j = y; j<=n; j += lowbit(j))
            c[i][j] += del;
}

int get_sum(int x,int y)
{    
      int ret = 0,i,j;
      for(i = x ; i ; i -= lowbit(i))
        for(j= y ; j; j -= lowbit(j))
          ret += c[i][j];
      return ret;
}

int main()
{      
       int cmd,x,y,dx,dy,ux,uy,i,j,del;
       
       while(scanf("%d",&cmd)!=EOF)
       {     
             if(cmd == 0 ) 
             {     
                   scanf("%d",&n);
                   for(i=0;i<=n+1;++i)
                      for(j=0;j<=n+1;++j)  
                      c[i][j] = 0;
             }
             else if(cmd == 1){
                  scanf("%d%d%d",&x,&y,&del); ++x; ++y;
                  modify(x,y,del);
             }
             else if(cmd == 2){
                  scanf("%d%d%d%d",&dx,&dy,&ux,&uy);  ++ux ;++uy ;
                  int ret = get_sum(ux,uy) - get_sum(dx,uy) - get_sum(ux,dy) + get_sum(dx,dy);
                  printf("%d\n",ret);
             }
             else  if(cmd == 3)  continue;
       }
       return 0;
}








