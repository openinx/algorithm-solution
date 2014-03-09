#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxn = 10005;
struct node {
       int l,r,cnt;
};

node tree[3*maxn];

void build(int root,int l,int r)
{    
     tree[root].l= l, tree[root].r = r, tree[root].cnt = r - l;
     if(l +  1 == r) return ;
     int mid = ( l + r ) >> 1;
     build(2*root , l ,mid);
     build(2*root+1,mid, r);
}

int find(int root,int k)
{   
    if(tree[root].l + 1 == tree[root].r)  
    {    
           tree[root].cnt = 0;
           return tree[root].l;
    }
    int ret ;
    if(k<=tree[2*root].cnt) ret = find(2*root,k);
    else  ret = find(2*root + 1, k - tree[2*root].cnt);
    tree[root].cnt = tree[2*root].cnt + tree[2*root+1].cnt;
    return ret;
}

int main()
{   
    int i,N,t[maxn],ans[maxn];
    scanf("%d",&N);
    build(1,1,N+1);
    for(i=2,t[1]=0;i<=N;++i)  scanf("%d",&t[i]);
    for(i=N;i>=1;--i)
    {     
           ans[i] = find(1,t[i]+1);
    }
    for(i=1;i<=N;++i)  printf("%d\n",ans[i]);
    return 0;
}
     
    
