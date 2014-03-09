#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 50100;
struct node 
{     int l,r,w; 
};
node tree[3*maxn];
int vis[maxn],ch[ 2*maxn ],chs;
int wl[maxn],wr[maxn],tot[2*maxn],tots;
int n;

inline int Max(int a,int b) {   return a > b ? a: b ; }

int bbs(int len , int x)
{   int left,right,mid;
    left = 0 ; right = len -1 ;
    while(left <= right)
    {     
          mid = (left + right) >> 1;
          if(ch[mid]==x) return mid;
          if(x < ch[mid])  right = mid - 1;
          else   left = mid + 1;
    }
    return -1;
}

void tree_build(int i , int l,int r)
{    
     tree[i].l = l ; tree[i].r =r; tree[i].w = -1;
     if(l+1 == r) return ;
     int mid = (l + r)>>1;
     tree_build(2*i , l , mid);
     tree_build(2*i + 1, mid , r);
}

void tree_insert(int i,int l,int r,int w)
{   
     if(l == tree[i].l  && tree[i].r == r) {    tree[i].w = w ; return ;  }
     if(tree[i].l + 1 == tree[i].r)  return ;
     int mid = ( tree[i].l +  tree[i].r ) >> 1;
     if(r <= mid) tree_insert( 2*i , l , r , w);
     else if(mid <= l) tree_insert(2*i+1, l,  r , w);
     else  
     {
             tree_insert(2*i , l , mid ,w ) ;  tree_insert(2*i+1 , mid , r ,w);
     }
}
     
void tree_visit( int i )
{    
     if(tree[i].l + 1 == tree[i].r) 
     {    
          if(tree[i].w != -1 )   vis[ tree[i].w ] = 1;  return ;
     }
     if(tree[i].w != -1) 
     {  
         tree[2*i].w  =  Max(tree[2*i].w , tree[i].w ); 
         tree[2*i+1].w  =  Max(tree[2*i+1].w ,tree[i].w); 
     }
     tree_visit(2*i);  tree_visit(2*i+1);
}
     
int solve()
{ 
    int ans = 0, i, l , r;
    tree_build(1,1,chs + 4);
    for(i = 0 ;i < n; ++i)
    {    
         l = bbs(chs,wl[i]) + 1 ;  r = bbs(chs, wr[i]) + 2 ;
         tree_insert(1,l,r, i );
    }
    for(i = 0 ; i<n; ++i) vis[i] = -1;
    tree_visit(1);  
    for( i = 0 ;i < n ; ++i)  
       if(vis[i] != -1)  ++ans;
    return ans; 
}

int main()
{     
      int cas , i , ans ;
      scanf("%d",&cas);
      while(cas--)
      {     
            scanf("%d",&n);
            tots = 2*n;
            for(i=0;i<n;++i) 
            { 
                 scanf("%d%d",&wl[i],&wr[i]);
                 tot[2*i] = wl[i];  tot[2*i+1] = wr[i];
            }
            sort(tot,tot + tots);
            ch[0] = tot[0];   chs = 1;
            for(i= 1 ; i<tots; ++i) 
              if(tot[i]!=ch[chs-1])
              {   
                  if(tot[i]-ch[chs-1] > 1)  ch[chs++] = tot[i] - 1;
                  ch[chs++] = tot[i];
              }
            ans = solve();
            printf("%d\n",ans);
      }
      return 0;
}
