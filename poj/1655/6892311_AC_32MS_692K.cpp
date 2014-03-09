#include<stdio.h>
#include<stdlib.h>
#define _max_n_size  20005
#define maxint 30000
#define MAX(a,b) ((a)>(b) ? (a):(b))
#define MIN(a,b) ((a)<(b) ? (a):(b))

struct
{      long id;
       long next;
}space[2*_max_n_size];

typedef struct
{      long ans;
       long sum;
       long next;
}node;

node tree[_max_n_size];
long space_n;
long n;

void  init_main()
{     long i;
      space_n=0;
      for(i=0;i<2*_max_n_size;++i)
          space[i].next=-1;
      for(i=0;i<=n;++i)
          tree[i].next=-1;
}

void add_tree(long a,long b)
{    long pos=space_n++;
     space[pos].id=b;
     space[pos].next=tree[a].next;
     tree[a].next=pos;
}

bool visit[_max_n_size];
void dfs_tree(long id)
{    long son_pos,i;
     visit[id]=true;
     tree[id].ans=0;
     tree[id].sum=1;
     for(son_pos=tree[id].next;  son_pos!=-1 ;  son_pos=space[son_pos].next  )
     {    i=space[son_pos].id;
          if(visit[i]==1) continue;
          dfs_tree(i);
          tree[id].sum+=tree[i].sum;
          tree[id].ans=MAX(tree[id].ans,tree[i].sum);
     }
     tree[id].ans=MAX(n-tree[id].sum,tree[id].ans);
}     
     
int main()
{         long T,m,i,j,a,b,ans;
          scanf("%ld",&T);
          while(T--)
          {         scanf("%ld",&n);
                    init_main();
                    for(i=0;i<n-1;++i)
                    {           scanf("%ld%ld",&a,&b);
                                add_tree(a,b);
                                add_tree(b,a);
                    }
                    for(i=0;i<_max_n_size;++i)
                        visit[i]=false;
                    dfs_tree(1);
                    ans=maxint;
                    for(i=1;i<=n;++i)  
                        ans=MIN(ans,tree[i].ans);
                    for(i=1;(i<=n)&&(ans!=tree[i].ans);++i);
                    
                    //printf("I LOVE YOU!\n");
                    printf("%ld %ld\n",i,ans);
          }
          //while(1);
          //system("pause");
          return 0;
}