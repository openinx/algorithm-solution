#include<iostream>
using namespace std;

typedef __int64 i64;
const i64 maxn = 100010;
struct node {
       i64 l,r,del,sum;
};

node tree[3*maxn];

void build(i64 root,i64 l,i64 r)
{    
     tree[root].l = l, tree[root].r = r;
     tree[root].del =  tree[root].sum = 0;
     if(l + 1 == r) return ;
     i64 mid = ( l + r ) >>1 ;
     build(2*root, l, mid);
     build(2*root+1, mid,r);
}

void ins(i64 root, i64 l,i64 r,i64 del)
{    
     if(tree[root].l ==  l && tree[root].r == r) 
     {    
          tree[root].del += del;
          tree[root].sum += del * (tree[root].r - tree[root].l );
          return ;
     }
     if(tree[root].del != 0 )
     {   
         tree[2*root].del += tree[root].del;
         tree[2*root+1].del += tree[root].del;
         tree[2*root].sum += tree[root].del * (tree[2*root].r - tree[2*root].l);
         tree[2*root+1].sum += tree[root].del * ( tree[2*root+1].r - tree[2*root+1].l );
     }
     i64 mid = ( tree[root].l + tree[root].r ) >> 1;
     if( r <= mid ) ins(2*root, l,r ,del);
     else   if (  mid <= l ) ins(2*root + 1 ,l,r,del);
     else  {  ins(2*root,l,mid,del); ins(2*root+1,mid,r ,del); }
     tree[root].del = 0;
     tree[root].sum = tree[2*root].sum + tree[2*root + 1].sum;
}

i64 query(i64 root, i64 l ,i64 r)
{     
     i64 ret ; 
     if(tree[root].l == l && tree[root].r == r) return tree[root].sum;
    if(tree[root].del != 0)   
     {   
         tree[2*root].del +=  tree[root].del;
         tree[2*root+1].del += tree[root].del;
         tree[2*root].sum += tree[root].del * (tree[2*root].r - tree[2*root].l);
         tree[2*root+1].sum += tree[root].del * ( tree[2*root+1].r - tree[2*root+1].l );
     }
     i64 mid = ( tree[root].l + tree[root].r ) >> 1;
     if( r <= mid ) 
            ret = query(2*root, l,r );
     else   if (  mid <= l ) 
            ret = query(2*root + 1 ,l,r);
     else     
            ret = query(2*root,l,mid)+ query(2*root+1,mid,r);
     tree[root].del = 0;
     tree[root].sum = tree[2*root].sum + tree[2*root+ 1].sum; 
     return ret ;
}  

int main()
{   
    i64 N,Q,a,b,c,i;
    char cmd[3];
    scanf("%I64d%I64d",&N,&Q); 
    build(1,1,N+1);
    for(i = 1 ;i<=N;++i) {   scanf("%I64d",&a); ins(1,i,i+1,a); }
    while(Q--)
    {    
           scanf("%s",cmd);
           if(cmd[0]=='C') 
           {   
                           scanf("%I64d%I64d%I64d",&a,&b,&c);
                           ins(1,a,b+1,c);
           }
           else 
           {
                   scanf("%I64d%I64d",&a,&b);
                   printf("%I64d\n",query(1,a,b+1));
           }
    }
    return 0;
}

