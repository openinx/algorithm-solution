#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define _max_size 1005
using namespace std;

typedef struct 
{     int l,r,cnt;
}node;
typedef struct
{     int a,b;
}edge;

edge p[_max_size*_max_size];
node tree[3*_max_size];
int N,M,K;

bool cmp(edge x,edge y)
{    if(x.a!=y.a)
      return x.a<y.a;
     else return x.b<y.b;
}

void build_tree(int root,int st,int ed)
{    int mid;
     tree[root].l=st;
     tree[root].r=ed;
     tree[root].cnt=0;
     if(st+1==ed) return ;
     mid=(st+ed)/2;
     build_tree(2*root,st,mid);
     build_tree(2*root+1,mid,ed);
}      

void insert_tree(int root,int y)
{    int mid;
     if(tree[root].l<=y&&y<tree[root].r)  tree[root].cnt++;
     if(tree[root].l+1==tree[root].r) return;
     mid=(tree[root].l+tree[root].r)/2;
     if(y<mid) insert_tree(2*root,y);
     else insert_tree(2*root+1,y);
}

int updata(int root,int st,int ed)
{   int mid;
    //if(st>ed) return 0;
    if(st<=tree[root].l&&tree[root].r<=ed) return tree[root].cnt;
    if(tree[root].l+1==tree[root].r)  return 0;
    mid=(tree[root].l+tree[root].r)/2;
    if(ed<=mid) return updata(2*root,st,ed);
    else if(mid<=st)  return updata(2*root+1,st,ed);
    else return updata(2*root,st,ed)+updata(2*root+1,st,ed); 
}    
int main()
{        int test,i,j,tc=0;
         __int64 cross_num = 0;
         scanf("%d",&test);
         while(test--)
         {     scanf("%d%d%d",&N,&M,&K);
               for(i=0;i<K;++i)
                   scanf("%d%d",&p[i].a,&p[i].b);
               sort(p,p+K,cmp);
               cross_num=0;
               build_tree(1,1,M+1);
               for(i=0;i<K;++i)
               {    
                    cross_num+=(__int64)updata(1,p[i].b+1,M+10);
                    insert_tree(1,p[i].b);
               }
               printf("Test case %d: %I64d\n",++tc,cross_num);
         }
         //system("pause");
         return 0;
}                    

