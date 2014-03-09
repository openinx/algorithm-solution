#include<stdio.h>
#include<stdlib.h>
#define maxn 1010
#define maxe 30010
#define maxint 100000000
typedef struct {
        int v,w,next;
}node;
node spc[maxe];
int sps,Ml,Md,N;
int g[maxn];

void add(int s,int t,int w){
     spc[sps].v = t , spc[sps].w = w;
     spc[sps].next = g[s]; g[s] = sps++;
}

void Read(){
     int i,a,b,c;
     sps = 0;
     scanf("%d%d%d",&N,&Ml,&Md);
     for(i=1;i<=N;++i) g[i]=-1;
     for(i=0;i<Ml;++i){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
     }
     for(i=0;i<Md;++i){
        scanf("%d%d%d",&a,&b,&c);
        add(b,a,-c);
     }
     for(i=1;i<N;++i)  add(i+1,i,0);
}
     
int Q[maxn],vis[maxn],top,dist[maxn];     
int cnt[maxn];  

int relax(int u,int v,int w){
    if(dist[v] > dist[u] + w){
               dist[v] = dist[u] + w;
               return 1;
    }
    return 0;
}
     
int solve(){
     int i,j,k,v,adr,cv;
     top = 0;
     for(i=1;i<=N;++i) { cnt[i]=vis[i]=0 ; dist[i]=maxint; }
     dist[1]=0 ; vis[1]=1 ; Q[++top]=1 ; cnt[1] = 1;
     while(top){
           v = Q[top--] ; vis[v]=0;
           for(adr = g[v] ; adr!=-1 ; adr = spc[adr].next){
                cv = spc[adr].v;
                if(1==relax(v,cv,spc[adr].w) && !vis[cv]){
                     Q[++top]=cv;
                     vis[cv]=1;
                     if((++cnt[cv])>N) return -1;
                }
           }
     }
     if(dist[N]>=maxint)  return -2;
     return dist[N];
}
 
int main(){
    Read();
    printf("%d\n",solve());
    return 0;
}
         


     
     
     
     
     
     
     
     
     
     
