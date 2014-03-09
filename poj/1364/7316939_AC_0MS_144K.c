#include<stdio.h>
#include<string.h>
#define maxn 110
#define maxm 310
#define maxint 10000000
#define NIL -1
typedef struct{
        int v,w,next;
}node;
node spc[maxm];
int sps,N,M;
int g[maxn];

void add(int u,int v,int w){
     spc[sps].v = v; spc[sps].w = w;
     spc[sps].next = g[u]; g[u]=sps++;
}

int Read(){
     int i,j,k,a,b;
     char cmd[5];
     sps = 0;
     scanf("%d",&N);
     if(N==0) return 0;
     scanf("%d",&M);
     for(i=0;i<=N+1;i++) g[i]=NIL;
     for(i=0;i<M;++i){
        scanf("%d%d%s%d",&a,&b,cmd,&k);
        if(!strcmp(cmd,"gt"))
             add(a+b,a-1,-k-1);
        else 
             add(a-1,a+b,k-1);
     }
     for(i=0;i<=N;++i)  add(N+1,i,0);
     return 1;
}

int Q[maxn],top;
int vis[maxn],cnt[maxn],dist[maxn];

int relax(int u,int  v , int w){
    if(dist[v] > dist[u] + w){
               dist[v] = dist[u] + w;
               return 1;
    }
    return 0;
}


int IsCircle(){
    int i,j,cv,addr,nv;
    top = 0;
    for(i=0;i<=N+1;++i){
      vis[i]= cnt[i] =0;
      dist[i] = maxint ;
    }
    Q[++top]=N+1 , dist[N+1]=0 , vis[N+1]=cnt[N+1] = 1;
    while(top){
        cv = Q[top--] ;  vis[cv] = 0;
        for(addr = g[cv] ; addr!=NIL ; addr = spc[addr].next){
                 nv = spc[addr].v;
                 if(1==relax(cv,nv,spc[addr].w) && !vis[nv]){
                     if(cnt[nv] > N) return 1;
                     Q[++top]=nv ; vis[nv] = 1;
                     cnt[nv] ++ ;
                 }
        }
    }
   return 0;
}
        
int main(){
    while(Read()){
                   if(IsCircle())
                         printf("successful conspiracy\n");
                   else 
                         printf("lamentable kingdom\n");
    }
    return 0;
}
           
    












