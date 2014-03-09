#include<stdio.h>
#include<stdlib.h>
#define maxn 1000005
#define maxint 2000000000
typedef __int64 i64;
typedef struct node{
       int x,y;
       i64 w;
};
node g[maxn];
int N,E;
int idx[maxn];
i64 dist[maxn];
int vis[maxn];
int Q[maxn],qt,qf;

void Read(){
     int i;
     scanf("%d%d",&N,&E);
     for(i=1;i<=E;++i){
         scanf("%d%d%I64d",&g[i].x,&g[i].y,&g[i].w);
     }
}

int cmp(node a,node b){ return a.x < b.x ; }

void Qsort(int l,int r){
     int i,j,mid;
     if(l>=r) return;
     node x,t;
     mid = rand()%(r-l+1)+l; 
     t = g[l], g[l]=g[mid], g[mid]=t;
     i = l ,j = r+1, x= g[l];
     while(1){
         while(i<r && cmp(g[++i],x));
         while(cmp(x,g[--j]));
         if(i>=j) break;
         t = g[i], g[i]=g[j],g[j]=t;
     }
     g[l]=g[j],g[j]=x;
     Qsort(l,j-1);
     Qsort(j+1,r);
}

void Make(){
     int i,j;
     idx[0]=0;
     for(i=1,j=1;i<=N;++i){
        for(;j<=E&&g[i].x==i;++j);
        idx[i]=j-1;
     }
}

void InitQ() {  qf = qt = 0;     }
int  EmpQ()  {  return qf == qt ? 1:0 ; }
void EnQ(int v){  
     Q[qt]= v ; qt = (qt+1)%maxn;
}
int DeQ(){
    int v=Q[qf]; qf = (qf+1)%maxn;
    return v;
}


i64 spfa(){
    int i,x,p,v;
    i64 ans ;
    for(i=1;i<=N;++i){
       dist[i]=maxint , vis[i]=0;
    }
    InitQ();  EnQ(1);
    dist[1]=0, vis[1]=1;
    while(!EmpQ()){
       x = DeQ() , vis[x]=0;
       printf("queue:%d\n",x);  system("pause");
       for(p = idx[x-1]+1 ; p <=idx[x] ; p++){
           v = g[p].y; 
           if(dist[v] > dist[x] + g[p].w){
               dist[v] = dist[x]+g[p].w;
               printf("dist:%d\n",dist[v]);
                 if(vis[v]==0){
                        EnQ(v); vis[v]=1;
                 }
           }
       }
    }
    ans = 0;
    printf("answer:\n");
    for(i=1;i<=N;++i){ ans += dist[i]; printf("dist:%d\n",dist[i]); }
    return ans;
}

void Qsort_show(){
     int i;
     printf("Qsort :\n");
     for(i=1;i<=E;++i) printf("%d ----> %d\n",g[i].x,g[i].y);
}

int main(){
    int cs,t,i;
    i64 ans;
    scanf("%d",&cs);
    while(cs--){
        Read();
        Qsort(1,E); 
        Qsort_show();
        Make();
        ans = 0;
        ans += spfa();
        for(i=1;i<=E;++i){
          t = g[i].x, g[i].x=g[i].y, g[i].y=t;
        }
        Qsort(1,E);
        Qsort_show();
        Make();
        ans +=spfa();
        printf("%I64d\n",ans);
    }
    return 0;
}
    
