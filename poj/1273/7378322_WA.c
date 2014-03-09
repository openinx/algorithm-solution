#include<stdio.h>
#include<stdlib.h>
#define Min(a,b) ((a)<(b) ? (a):(b))
#define Max(a,b) ((a)>(b) ? (a):(b))
#define _abs(a)  ((a)> 0  ? (a):-(a))
#define maxn 205
#define maxint (1<<28)
int c[maxn][maxn],f[maxn][maxn];
int E,N,wt[maxn],st[maxn];
int Q[maxn],Qp[maxn],Qs;

void exch(int i,int j){
     int t;
     Qp[Q[i]]=j; Qp[Q[j]]=i;
     t = Q[i] ; Q[i] = Q[j] ; Q[j]=t;
}
int cmp(int i,int j) { return wt[i]<wt[j] ? 1:0 ; }
void up(int i){
     for(;i!=1 && cmp(i/2,i); i=i/2) exch(i,i/2);
}
void down(int i){
     for(i=i*2;i<=Qs;i=i*2){
       if(i<Qs && cmp(i,i+1)) ++i;
       if(!cmp(i/2,i))  break;
       exch(i,i/2);
     }
}

int adel(){
    int i,j,v,del;
    for(i=1,Qs=0;i<=N;++i) { wt[i]=st[i]=0; Q[++Qs]=i; Qp[i]=i;} 
    wt[1]=maxint; st[1] = -1;
    while(Qs){
        v = Q[1] ; exch(1,Qs); --Qs ; down(1);
        if(v==N || !st[v]) break;
        for(i=1;i<=N;++i){
           if(f[v][i]<c[v][i]) { 
              del = Min(c[v][i]-f[v][i],wt[v]);
              if(del>wt[i]) { wt[i]=del ; st[i]=v; up(Qp[i]);}
           }
           if(f[i][v]>0){
              del = Min(f[i][v] , wt[v]);
              if(del>wt[i]) { wt[i]=del ; st[i]=-v; up(Qp[i]);}
           }
        }
    }
    return st[N]==0  ? 0:1 ;
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
    return 0;
}
      
                      
