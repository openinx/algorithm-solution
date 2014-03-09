#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 40005;

struct node 
{    int l,r,w;  
};

node  tree[6*maxn],box[maxn];
int  pos [2* maxn ], tot[2*maxn],pn,tn;
typedef __int64 i64;


void build(int root ,int l,int r)
{    
     tree[root].l = l, tree[root].r = r , tree[root].w = 0;
     if(l + 1 == r) return ;
     int mid = (l + r)>>1;
     build(2*root,l,mid); 
     build(2*root + 1 , mid, r);
}

void ins(int root, int l,int r,int w)
{    
     if(tree[root].l ==l && tree[root].r ==r)
     {    
         if(tree[root].w < w)  tree[root].w = w;    return ; 
     }
     int mid = (tree[root].l + tree[root].r)>>1;
     if(r<=mid) ins(2*root,l,r,w);
     else if(mid<=l) ins(2*root+1,l,r,w);
     else {
              ins(2*root,l,mid,w); ins(2*root+1,mid,r,w);
     }
}

i64  query(int root , int h)
{     
     if(h > tree[root].w )  tree[root].w = h;
     if(tree[root].l + 1 == tree[root].r)
     {   
        return (i64)tree[root].w * (i64)( pos[ tree[root].r  ] - pos [ tree[root].l ]);
     }
     return query(2*root, tree[root].w) + query(2*root+1 , tree[root].w);
}

int bsf(int  x)
{   
    int l = 1,r = pn , mid;
    while(l <= r)
    {    
         mid  = (l + r) / 2;
         if( pos[ mid ] == x)  return mid;
         if(x < pos[mid])  r =  mid - 1;
         else   l = mid + 1;
    }
    return 0;
}
     
    
int main()
{    
     int n , i , l,r;
     scanf("%d",&n);
     
     tn = 0;
     for(i=1;i<=n;++i) 
     { 
         scanf("%d%d%d",&box[i].l,&box[i].r,&box[i].w);
         tot[ ++ tn ] = box[i].l , tot[ ++ tn ] = box[i].r ;
     }
     sort(tot + 1, tot + tn + 1);
     pos[1] = tot[1] ,  pn = 1 ;
     for( i = 2 ;i<= tn ;++i)
       if(tot[i] != pos[pn]) pos[ ++pn ] = tot[i]; 
    build(1 , 1 , pn );
    
    i64  ret = 0; 
    for(i=1;i<=n;++i) 
    {  
         l = bsf( box[i].l );
         r = bsf( box[i].r );
         ins(1 , l , r , box[i].w);
    }                        
    ret = query( 1 ,0 );
    printf("%I64d\n",ret);
    return 0;
}
     
     
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
   


