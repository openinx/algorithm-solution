#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 30000 ;
struct NODE
{
    int l,r,c;
}tree[MAXN*5];
struct L
{
    int li,num;
    bool operator < ( const L& r ) const 
    {
        return li<r.li;
    };
};
L line[MAXN];
int post[MAXN][2];

bool vis[MAXN];
int cnt;
void build ( int v , int l, int r )
{
    int m;
    tree[v].c=0,tree[v].l=l,tree[v].r=r;
    if ( l>=r )
        return;
    m=(l+r)/2;
    build( v*2, l,m );
    build(v*2+1,m+1,r);
}
void ins (int v , int l , int r , int c )
{
    int m;
    if ( tree[v].l==l && tree[v].r==r )
    {
        tree[v].c=c;
        return;
    }
    if ( tree[v].c>0 && tree[v].c!=c )
    {
        tree[v*2].c=tree[v].c;
        tree[v*2+1].c=tree[v].c;
        tree[v].c=0;
    }
    m=(tree[v].l+tree[v].r)>>1;
    if ( r<=m )
        ins(v*2,l,r,c);
    else
        if ( l>m )
            ins( v*2+1,l,r,c);
        else
        {
            ins(v*2,l,m,c);
            ins(v*2+1,m+1,r,c);
        }
}
void sum ( int v )
{
    if ( tree[v].c )
    {
        if ( !vis[tree[v].c] )
        {
            vis[tree[v].c]=true;
            cnt++;
        }
        return;
    }
    sum(v*2);
    sum(v*2+1);
}
int main ( )
{
    int n,N,i;
    scanf("%d",&N);
    while ( N-- )
    {
        cnt=0;
        scanf("%d",&n);
        memset(vis,false,sizeof(vis));
        //记录端点
        for ( i=0 ; i<n ; i++ )
        {
            scanf("%d%d",&post[i][0],&post[i][1]);
            line[i*2].li=post[i][0],line[i*2].num=-(i+1),line[i*2+1].li=post[i][1],line[i*2+1].num=i+1;
        }
        //离散化坐标
        sort(line,line+n*2);
        int tp=1,temp=line[0].li;
        
        for(i=0;i<2*n;i++)
        {
            if(line[i].li!=temp)  
            {
                tp++;
                temp=line[i].li;
            }
            if(line[i].num<0)
                post[-line[i].num-1][0]=tp;
            else
                post[line[i].num-1][1]=tp;
        }
        build(1,1,tp);
        for ( i=0 ; i<n ; i++ )
            ins(1,post[i][0],post[i][1],i+1);
        sum(1);
        printf("%d\n",cnt);
    }
}

