#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define Min(a,b) ((a)<(b) ? (a):(b))
#define Max(a,b) ((a)>(b) ? (a):(b))
#define _abs(a)  ((a)> 0  ? (a):-(a))
#define maxn 205
#define maxint (1<<28)
using namespace std;
int c[maxn][maxn],f[maxn][maxn];
int E,N,wt[maxn],st[maxn];
//int Q[maxn],Qp[maxn],Qs;
/*
void exch(int i,int j){
     int t;
     Qp[Q[i]]=j; Qp[Q[j]]=i;
     t = Q[i] ; Q[i] = Q[j] ; Q[j]=t;
}
int cmp(int i,int j) { return wt[i]<wt[j] ; }
void up(int i){
     for(;i!=1 && cmp(i/2,i); i=i/2) exch(i,i/2);
}
void down(int i){
     for(i=i*2;i<=Qs;i=i*2){
       if(i<Qs && cmp(i,i+1)) ++i;
       if(!cmp(i/2,i))  break;
       exch(i,i/2);
     }
}*/

struct node {
       int id,w;
       node(int _id,int _w) : id(_id),w(_w){}
};

bool operator < ( node cc,node dd){
     return cc.w > dd.w ;
}

int adel(){
    int i,j,v,del;
    priority_queue<node> Q;
    for(i=1;i<=N;++i) { wt[i]=st[i]=0; Q.push(node(i,0)); }
    wt[1]=maxint; st[1] = -1; Q.push(node(1,maxint));
    while(!Q.empty()){
        v = (Q.top()).id ; Q.pop();
        if(v==N || !st[v]) break;
        for(i=1;i<=N;++i){
           if(f[v][i]<c[v][i]) {  //非饱和流 
              printf("pos : %d\n",i); 
              del = Min(c[v][i]-f[v][i],wt[v]);
              printf("del : %d\n",del);
              if(del>wt[i]) { wt[i]=del ; st[i]=v;Q.push(node(i,del));}
           }
           if(f[i][v]>0){         //非零流 
              del = Min(f[i][v] , wt[v]);
              if(del>wt[i]) { wt[i]=del ; st[i]=-v; Q.push(node(i,del));}
           }
        }
    }
    return st[N]==0  ? 0:1 ;
}

void show(){
     int i,j;
     printf("current flow is:\n");
     for(i=1;i<=N;++i)
       for(j=1;j<=N;++j)
        if(f[i][j]>0) printf("%d  --- >  %d  flow is %d\n",i,j,f[i][j]);
}


int maxflow(){
    int v,w,ans=0,del;
    while(adel()){
          del = -maxint;
          for(v=N;v!=1;v=w){
           w = _abs(st[v]);
           if(st[v]<0) del = Max(del,f[v][w]);
           else  del = Max(del,c[w][v]-f[w][v]);
          }
          for(v=N;v!=1;v=w){
           w = _abs(st[v]);
           if(st[v]<0) f[v][w]-=del;
           else f[w][v]+=del;
           }
           show();
           ans += del;
    }
    return ans;
}

int main(){
    int i,j,x,y,cap;
    scanf("%d%d",&E,&N);
    for(i=1;i<=N;++i)
       for(j=1;j<=N;++j)
       c[i][j]=f[i][j]=0;
    for(i=1;i<=E;++i){
      scanf("%d%d%d",&x,&y,&cap);
      c[x][y]=cap;
    }
    printf("%d\n",maxflow());
    system("pause");
    return 0;
}
      
                      
