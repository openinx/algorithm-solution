#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxn = 50010;
const int maxint = 1<<30;
struct node {
       int l,r,st,ed;
};
node tree[3*maxn];
int data[maxn];

inline int Max(int a,int b) { return a>b ? a:b ; }
inline int Min(int a,int b) { return a<b ? a:b ; }
inline int _abs(int a){ return a>0 ? a:-a; }

void build(int root,int l,int r)
{    
     tree[root].l = l, tree[root].r = r;
     if(l+1 == r)
     {    
          tree[root].st = tree[root].ed = data[l];
          return ;
     }
     int mid = ( l+ r) >>1;
     build(2*root,l,mid);
     build(2*root+1,mid,r);
     tree[root].st = Min(tree[2*root].st , tree[2*root+1].st);
     tree[root].ed = Max(tree[2*root].ed , tree[2*root+1].ed);
}

void query(int root, int l ,int r ,int &low,int &up)
{    
     if(l==tree[root].l && r == tree[root].r )
     {  
        low = Min( low, tree[root].st ) ; up = Max( up , tree[root].ed ); 
        return ;
     }
     int mid = ( tree[root].l + tree[root].r ) >>1;
     if( r<=mid ) query(2*root,l,r,low,up);
     else  if(mid<=l) query(2*root+1,l,r,low,up);
     else {
              query(2*root,l,mid,low,up);
              query(2*root+1,mid,r,low,up);
     }
}

int main()
{     
      int N,Q,low,up,ans,l,r,i;
      scanf("%d%d",&N,&Q);
      for(i = 1;i<=N;++i) scanf("%d",&data[i]);
      build(1,1,N+1);
      for(i= 1;i<=Q;++i)
      {    
            scanf("%d%d",&l,&r);
            low = maxint , up = - maxint;
            query(1,l,r+1,low,up);
            printf("%d\n",_abs(low-up));
      }
      return 0;
}
     
     
     
     
     
     
     
     
     
     
     
     
