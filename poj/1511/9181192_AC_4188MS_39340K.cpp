#include<stdio.h>
#include<stdlib.h>
#define maxint 2000000000
#define maxn   1000005

typedef __int64 i64;

typedef struct {
       int x,y;
       i64 w;
}node;

typedef struct{
        int x;
        i64 d;
}hnode;

hnode H[maxn];
node g[maxn];
int N,E,hs;
int idx[maxn],hpos[maxn];

void Read()
{    
     int i;
     scanf("%d%d",&N,&E);
     for(i = 1 ;i<=E;++i){
           scanf("%d%d%I64d",&g[i].x,&g[i].y,&g[i].w);
     }
}

int cmp(node a,node b){   return a.x < b.x ? 1:0 ; }

void Qsort(int l,int r){
     int i,j,prt;
     node t,x;
     if(l>=r) return;
     prt = rand()%(r-l+1)+l;
     t = g[l],g[l]=g[prt],g[prt]=t;
     i = l ,j = r+1,x = g[l];
     while(1){
        while((i<r)&&(cmp(g[++i],x)));
        while(cmp(x,g[--j]));
        if(i>=j) break;
        t=g[i],g[i]=g[j],g[j]=t;
     }
     g[l] = g[j] , g[j] = x;
     Qsort(l,j-1);
     Qsort(j+1,r);
}

void Make(){
     int i,j = 1;
     idx[0]=0;
     for( i = 1;i<=N;++i){
         for(;j<=E&&g[j].x==i;++j);
         idx[i]=j-1;
     }
}

void swap(int a,int b){
     hnode t;
     hpos[H[a].x]=b; hpos[H[b].x]=a;
     t = H[a] ; H[a] = H[b] ; H[b] = t;
}

void up(int i){
     for( ; i!=1 && H[i].d < H[i/2].d ; i=i/2)
     swap(i,i/2);
}

void down(int i){
     for(i=i*2;i<=hs; i=i*2){
        if( i<hs && H[i+1].d< H[i].d) ++i;
        if(H[i].d>=H[i/2].d) break;
        swap(i,i/2);
     }
}

void relax(int u,int v,int w){
     if(H[ hpos[v] ].d > H[ hpos[u] ].d + w ){
           H[hpos[v]].d = H[ hpos[u] ].d + w;
           up(hpos[v]);
     }
}

i64 dijkstra(){
    int i,j,k,v,p;
    i64 ans = 0;
    for(i=1;i<=N;++i){
       hpos[i]=i; H[i].x=i; H[i].d=maxint;
    }
    H[1].d=0; hs=N;
    while(hs){
       v = H[1].x ; swap(1,hs); --hs ; down(1);
       for(p = idx[v-1]+1 ; p<=idx[v] ;++p){
             relax(g[p].x,g[p].y,g[p].w);
       }
    }
    for(i=1;i<=N;++i)  ans += H[i].d; 
    return ans;
}

int main(){
    int cs,i,t;
    i64 ans;
    scanf("%d",&cs);
    while(cs--){
       Read();
       Qsort(1,E); 
       Make();
       ans = 0;
       ans += dijkstra();
       for(i=1;i<=E;++i){
           t = g[i].x ; g[i].x=g[i].y ; g[i].y = t;
       }
       Qsort(1,E);
       Make();
       ans += dijkstra();
       printf("%I64d\n",ans);
    }
    return 0;
}

