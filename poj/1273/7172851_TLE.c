#include<stdio.h>
#define   maxq  100000
#define   maxn  201
#define   maxint  1<<15 
typedef struct {
        int  front,rear;
        int  elem[maxq];
}Queue;

Queue Q;
void InitQ()    { Q.front=Q.rear=0;                                        }
int  EmptyQ()   { return Q.front==Q.rear  ;                                }
void EnQ(int e) { Q.elem[Q.rear]=e;  Q.rear=(Q.rear+1)%maxq;               }
int  DeQ()      { int e=Q.elem[Q.front]; Q.front=(Q.front+1)%maxq;return e;}

int edge[maxn][maxn];
int p[maxn],vis[maxn];
int N,E;

int check()
{   
    int i,v;
    InitQ();
    for(i=2;i<=N;++i)   vis[i]=0;
    vis[1]=1;
    p[1]=0;
    EnQ(1);
    while(!EmptyQ())
    {        
            v = DeQ(); 
            if(v == N) return 1;
            for(i=1;i<=N;++i)
                if(edge[v][i] && !vis[i] )
                {    
                     vis[i] = 1;
                     p[i] =v;
                     EnQ(i);
                }  
    }
    return 0 ;
}   

int solve()
{    
      int v,del,ans=0;
      del = maxint;
      while(check())
      {
             for(v = N ; v > 1 ; v = p[v]) 
                  if(edge[p[v]][v] < del)  
                          del = edge[p[v]][v];
             for(v = N; v > 1 ; v = p[v])
             {    
                  edge[p[v]][v] -= del;
                  edge[v][p[v]] += del;
             }
             ans += del;                     
      }
      return ans;
}

int main()
{     int i,j,f,t,w;
      while(scanf("%d%d",&E,&N)!=EOF)
      {       
              for(i=1;i<=N;++i)
                 for(j=1;j<=N;++j)  edge[i][j]=0;
              
              for(i=1;i<=E;++i)
              {   
                  scanf("%d%d%d",&f,&t,&w);
                  edge[f][t]+=w;
              }
              printf("%d\n",solve());
      }
      return 0;
}     
