#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std ;
const int maxn = 100001  ; 
const int maxq = 50001   ; 

struct tq{
      int x0 , x1 ,k , id ;
};
struct tn{
     int x , id ;
}; 
struct node{
     int l , r , s , v ; 
};

int ts ; 
node t[maxn] ;

int n , q , ans[maxq] , b[maxn] ;
tn N[maxn] ; 
tq Q[maxq] ; 

bool cmp_tq(tq q0 , tq q1){    return q0.x0 < q1.x0 ;   }
bool cmp_tn(tn n0 , tn n1){    return n0.x  < n1.x  ;   }

void sbt_init(){ 
     ts = 0 ;  t[0].l = t[0].r = t[0].s = 0 ;  
}

void zig(int &x){
     int y = t[x].l ;   if(!x||!y)  return ;
     t[x].l = t[y].r  ;   t[y].r = x ;
     t[y].s = t[x].s  ;   t[x].s = t[t[x].l].s + t[t[x].r].s + 1 ;  
     x = y ;
}

void zag(int &x){
     int y = t[x].r ;   if(!x||!y)  return ; 
     t[x].r = t[y].l  ;  t[y].l = x ; 
     t[y].s = t[x].s  ;  t[x].s = t[t[x].l].s + t[t[x].r].s + 1  ;
     x = y ;
}

void maintain(int &x ,int flag){
     if(x == 0 )  return ; 
     if(flag){
         if(t[t[t[x].l].l].s > t[t[x].r].s ){
               zig(x);
         }else if(t[t[t[x].l].r].s > t[t[x].r].s){
               zag(t[x].l);  zig(x);
         }else{
             return ;
         }
     }else{
         if(t[t[t[x].r].r].s > t[t[x].l].s){
               zag(x);
         }else if(t[t[t[x].r].l].s > t[t[x].l].s){
               zig(t[x].r);  zag(x);
         }else{
               return ;
         }
     }
     maintain(t[x].l , true);  maintain(t[x].r , false );
     maintain(x , true)     ;  maintain(x , false )     ;
}

void ins(int &x , int v ){
     if(x == 0){
        x = ++ ts ;  t[x].l = t[x].r = 0 ; t[x].s = 1 ; t[x].v = v ; 
     }else{
        t[x].s ++ ;
        if(v <= t[x].v ){  
             ins(t[x].l , v );
        }else{ 
             ins(t[x].r , v );
        }
        maintain(x , v<=t[x].v);
     }
}

int del(int &x , int v){
     if(x == 0 )  return -1;
     t[x].s -- ; 
     if((t[x].l==0 && v < t[x].v) || (t[x].r==0 && v > t[x].v) || (v == t[x].v)){
          int temp = t[x].v ; 
          if(t[x].l==0 || t[x].r==0 ){
               x = t[x].l + t[x].r ;
          }else{
               t[x].v = del(t[x].l , t[x].v+1);
          }
          return temp ;      
     }else{
          if(v < t[x].v ) return  del(t[x].l , v );
          if(v > t[x].v ) return  del(t[x].r , v );
     }
}

int sel(int x , int k){
    if(k <= t[t[x].l].s )  
         return sel(t[x].l , k );
    else if(k == t[t[x].l].s + 1)   
         return t[x].v ;
    else  
         return sel(t[x].r , k - t[t[x].l].s - 1);
}

int  main(){
     int i  , j , root ;
     scanf("%d%d" , &n , &q);
     for(i = 1 ; i <= n ; ++ i){
            scanf("%d" ,&N[i].x);  N[i].id = i ;
     }
     for(i = 1 ; i <= q ; ++ i){
            scanf("%d%d%d" , &Q[i].x0 , &Q[i].x1 ,&Q[i].k );  Q[i].id = i ;
     }
     sort(N+1 , N+n+1 , cmp_tn);
     sort(Q+1 , Q+q+1 , cmp_tq);
     sbt_init();   root = 0 ;
     for(i = 1 ; i<= n ; ++ i)  b[N[i].id] = i ;
     for(i = 1 ; i<= q ; ++ i){
             if(i == 1){
                   for(j = Q[1].x0 ; j <= Q[1].x1 ; ++ j )  ins(root , b[j]);
             }else{
                   if(Q[i-1].x1 < Q[i].x0 ){
                        for(j = Q[i-1].x0 ; j <= Q[i-1].x1 ; ++ j)  del(root , b[j]);
                        for(j = Q[i].x0   ; j <= Q[i].x1   ; ++ j)  ins(root , b[j]);
                   }else{
                        for(j = Q[i-1].x0 ; j <  Q[i].x0   ; ++ j)  del(root , b[j]);
                        for(j=Q[i-1].x1+1 ; j <= Q[i].x1   ; ++ j)  ins(root , b[j]);
                   }
             }
             ans[Q[i].id] = N[sel(root , Q[i].k)].x ;
     }
     for(i = 1 ; i <= q ; ++ i)  printf("%d\n" , ans[i] ) ; 
     //system("pause");
     return 0;
}

