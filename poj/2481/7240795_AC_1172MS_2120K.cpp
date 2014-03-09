#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100005;
struct  node {
        int l,r,id;
};

node p[maxn+1];
int vis[maxn+1];
int c[maxn + 1];
int n;

bool cmp(node a,node b)
{    
     if(a.r != b.r) return a.r > b.r;
     return a.l < b.l; 
}

int lowbit(int x) {  return x & (- x) ; }

void add(int i,int del)
{    
     for( ; i<=maxn ; i += lowbit(i)) 
        c[i] += del;
}

int getsum(int i)
{   
    int ret = 0;
    for( ; i ; i -= lowbit(i))  ret += c[i];
    return ret;
}

int main()
{     
      int i;
      while(scanf("%d",&n)!=EOF && n )
      {     
            for(i=1;i<=n;++i)  
            {    
                 scanf("%d%d",&p[i].l , &p[i].r);
                 p[i].l ++ ; p[i].r ++;
                 p[i].id = i;
            }
            sort(p+1,p+n+1,cmp);
            memset(c,0,sizeof(c));
            memset(vis,0,sizeof(vis));
            for(i = 1 ; i<= n; ++i )
            {    
                 int pos = p[i].l;
                 if( i !=1 && (p[i].l == p[i-1].l && p[i].r == p[i-1].r) ) 
                 {    
                      vis[ p[i].id ]= vis[ p[i-1].id ];
                      add(pos, 1);
                      continue;
                 }
                 vis[ p[i].id ] = getsum( pos );
                 add(pos,1);
            }
            printf("%d",vis[ 1 ]);
            for(i = 2; i<=n;++i) printf(" %d",vis[i]);  printf("\n"); 
      }
      //system("pause");
      return 0;
}
