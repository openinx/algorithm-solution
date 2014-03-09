#include<stdio.h>
#include<stdlib.h>
#define maxn 80010

typedef struct{
        int l,r,c,tot;
}node;

typedef struct{
        int x,y;
}pnode;
        
pnode  wall[maxn];
node tree[3*maxn];
int pos[2*maxn],pn,OK[2*maxn],okn;
int N;

void Qsort(int l,int r){
     int x,i,j,t,prt;
     if(l>=r)  return;
     prt = rand()%(r-l+1)+l;
     t = pos[l],pos[l]=pos[prt],pos[prt]=t;
     x = pos[l],i=l,j=r+1;
     while(1){
       while((i<r)&&(pos[++i]<x));
       while(pos[--j]>x);
       if(i>=j) break;
       t = pos[i],pos[i]=pos[j],pos[j]=t;
     }
     pos[l]=pos[j],pos[j]=x;
     Qsort(l,j-1);
     Qsort(j+1,r);
}
     
void Read(){
     int i;
     scanf("%d",&N);
     pn = 0;
     for(i=1;i<=N;++i){  
          scanf("%d%d",&wall[i].x,&wall[i].y);
          pos[++pn]= wall[i].x , pos[++pn]=wall[i].y;
       }
     Qsort(1,pn);
     okn = 1 , OK[okn]=pos[1];
     for(i=2;i<=pn;++i)
        if(OK[okn]!=pos[i]) OK[++okn]=pos[i];
}
int bbs(int x){
    int l,r,mid;
    l = 1,r = okn;
    while(l<=r){
       mid = (l+r)>>1;
       if(OK[mid]==x) return mid;
       else  if(x<OK[mid]) r = mid -1;
       else  l = mid + 1;
    }
    return 0;
}

void build(int i,int l,int r){
     int mid;
     tree[i].l = l , tree[i].r = r , tree[i].c = 0 ,tree[i].tot = 1;
     if(l+1==r) return;
     mid =(l+r)>>1;
     build(2*i,l,mid);  
     build(2*i+1,mid,r);
}


void ins(int i,int l,int r,int c){
     int mid ;
     if(tree[i].l == l && tree[i].r == r){
           tree[i].c = c , tree[i].tot = 1;
           return ;
     }
     if(tree[i].l +1 == tree[i].r) return;
     if(tree[i].tot == 1){
                    tree[2*i].c = tree[2*i+1].c = tree[i].c;
                    tree[2*i].tot = tree[2*i+1].tot = 1;
                    tree[i].tot = 0;
     }
     mid = ( tree[i].l + tree[i].r ) / 2;
     if(r<=mid) ins(2*i, l , r , c);
     else if(mid<=l) ins(2*i+1 , l , r , c );
     else {
             ins(2*i , l , mid , c ); ins( 2*i+1 , mid , r , c );
     }
     if(tree[2*i].tot ==1 && tree[2*i+1].tot == 1 && tree[2*i].c == tree[2*i+1].c){
         tree[i].tot =1 , tree[i].c = tree[2*i].c;
     }
}

int vis[maxn];

void Query(int i){
     if(tree[i].l + 1 == tree[i].r){
                 vis[tree[i].c]=1; return;
     }
     if(tree[i].tot == 1){
                    tree[2*i].c = tree[2*i+1].c = tree[i].c;
                    tree[2*i].tot = tree[2*i+1].tot = 1;
     }
     Query(2*i); Query(2*i+1);
} 
     
void Solve(){
     int i,j,ans,l,r;
     build(1,1,okn+1);
     for(i=1;i<=N;++i)
     {  
         l = bbs(wall[i].x);
         r = bbs(wall[i].y);
         ins(1,l,r+1,i);
     }
     for(i=1;i<=N;++i) vis[i]=0;
     Query(1);
     ans = 0;
     for(i=1;i<=N;++i)
       if(vis[i]==1)  ++ans;
     printf("%d\n",ans);
}
     
int main(){
    int cs;
    scanf("%d",&cs);
    while(cs--){
         Read();
         Solve();
    }
    return 0;
}

