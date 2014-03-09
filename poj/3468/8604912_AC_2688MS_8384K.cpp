#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn  100005 

typedef __int64 lld ; 
struct node{
    lld l , r , sum , d  ; 
};
node t[3*maxn] ;

void build(lld x , lld l , lld r ){
     t[x].l = l , t[x].r = r , t[x].sum = t[x].d = 0 ; 
     if(l == r)  return ;
     lld mid = (l + r) >> 1 ;
     build(x<<1  , l  ,  mid );
     build((x<<1)+1 , mid+1 , r); 
}

void update(int x){
     t[x<<1].sum += t[x].d * (t[x<<1].r - t[x<<1].l + 1)  ; 
     t[(x<<1)+1].sum += t[x].d * (t[(x<<1)+1].r - t[(x<<1)+1].l + 1) ; 
     t[x<<1].d += t[x].d ; 
     t[(x<<1)+1].d +=t[x].d ;
     t[x].d = 0 ;
}

void ins(int x ,int l , int r , int d){
     lld mid = (t[x].l + t[x].r)>>1 ;
     if(t[x].l == l && t[x].r == r){
          t[x].d += d  , t[x].sum += d * (t[x].r - t[x].l + 1);
          return ; 
     }
     update(x);
     if(r <= mid ){
         ins(x<<1 , l , r , d);
     }else if(mid+1<=l){
         ins((x<<1)+1 , l , r , d);
     }else{
         ins(x<<1 , l , mid , d );  ins((x<<1)+1 , mid+1 , r , d );
     }
     t[x].sum = t[x<<1].sum + t[(x<<1)+1].sum ; 
}

lld query(int x , int l , int r){
    lld mid = (t[x].l + t[x].r )>> 1 , ans ; 
    if(t[x].l == l && t[x].r == r)  return t[x].sum ; 
    update(x) ;
    if(r <= mid ){
         ans = query(x<<1 , l , r );
    }else if(mid+1<=l ){
         ans = query((x<<1)+1 , l , r );
    }else{
         ans = query(x<<1 , l , mid ) + query((x<<1)+1 , mid+1 , r );
    }
    t[x].sum = t[x<<1].sum + t[(x<<1)+1].sum ;
    return ans ;
}

int main(){
    int i , N , Q , x , y , d ;
    char cmd[10] ;
    scanf("%d%d" , &N , &Q);
    build(1 , 1 , N);
    for(i = 1 ; i<=N ; ++ i){
          scanf("%d" , &x);  
          ins(1 , i , i , x);
    }
    while(Q--){
          scanf("%s" , cmd);
          if(cmd[0]=='Q'){
              scanf("%d%d" , &x , &y);
              printf("%I64d\n" , query(1 , x , y));
          }else if(cmd[0]=='C'){
              scanf("%d%d%d" , &x , &y , &d);
              ins(1 , x , y , d );
          }
    }
    //system("pause");
    return 0 ;
}
