#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<set>
#include<iostream>
#include<algorithm>
#define maxn 5005
using namespace std ;

struct seg_node{
     int l , r , mid   ; 
     int lbd , rbd , m , cnt , line ; 
};

struct event{
     int x , y0 , y1 , ty ; 
};

set<int> fuck ; 
set<int>::iterator it ;

seg_node t[6*maxn] ; 
event    e[2*maxn] ;
int es , posY[2*maxn], ps ;

inline int L(int x)    { return x<<1 ; }
inline int R(int x)    { return (x<<1)|1 ;}
inline int _abs(int x) { return x > 0 ? x : -x ; }

int bs(int x){
    int l = 1 , r = ps , mid ; 
    while(l<=r){
        mid = (l+r)>>1 ;
        if(posY[mid] == x)  return mid ; 
        if(x < posY[mid] )  r = mid - 1;
        if(posY[mid] < x )  l = mid + 1; 
    }
    return 0 ;
}

bool cmp(event a , event b ){
     if(a.x != b.x )  return a.x < b.x ; 
     return a.ty > b.ty ; 
}

void build(int x , int l ,int r ){
     t[x].l = l , t[x].r = r , t[x].m = t[x].cnt = t[x].line = t[x].lbd = t[x].rbd = 0 ;
     if(l+1 != r){
           int mid = (l + r)>>1 ; 
           build(L(x) , l , mid );
           build(R(x) , mid , r );
     }
}

void update(int x ){
     if(t[x].cnt > 0 ){
         t[x].lbd = t[x].rbd = t[x].line = 1 ;  
         t[x].m = posY[t[x].r] - posY[t[x].l] ; 
     }else if(t[x].l + 1 == t[x].r ){
         t[x].lbd = t[x].rbd = t[x].line = t[x].m = 0 ;
     }else{
         t[x].lbd = t[L(x)].lbd ;   
         t[x].rbd = t[R(x)].rbd ; 
         t[x].m = t[L(x)].m + t[R(x)].m ; 
         t[x].line = t[L(x)].line + t[R(x)].line - t[L(x)].rbd * t[R(x)].lbd ; 
     }
}

void Insert(int x , int l , int r , int d){
     if(t[x].l == l && t[x].r == r){
           t[x].cnt +=d ; 
     }else{
           int mid = (t[x].l + t[x].r)>>1 ; 
           if(r <= mid ){
                Insert(L(x) , l , r , d );
           }else if(mid <= l ){
                Insert(R(x) , l , r , d );
           }else{
                Insert(L(x) , l , mid ,d);
                Insert(R(x) , mid, r  ,d);
           }
     }
     update(x);
}

int main(){
    
    int N , i , x0 , y0 , x1 , y1 , last , ans ; 
    
    while(scanf("%d" , &N)!=EOF){
         
         fuck.clear() ;   es = 0 ;
         
         for(i = 1 ; i<= N ; ++ i){
              scanf("%d%d%d%d" , &x0 , &y0 , &x1 , &y1);
              fuck.insert(y0);  fuck.insert(y1);
              ++es ; e[es].x = x0 ;   e[es].y0 = y0  ; e[es].y1 = y1 ; e[es].ty = +1 ;
              ++es ; e[es].x = x1 ;   e[es].y0 = y0  ; e[es].y1 = y1 ; e[es].ty = -1 ; 
         }
         
         for(it = fuck.begin(), ps = 0 ; it!=fuck.end() ; it++) 
             posY[++ps] = *it ;
         
         sort(e+1 , e+es+1 , cmp);
         
         build(1 , 1 , ps );   ans = last = 0 ; 
         
         for(i = 1 ; i < es ; ++ i){
                 Insert(1 , bs(e[i].y0) , bs(e[i].y1) , e[i].ty );
                 ans = ans + 2 * t[1].line * (e[i+1].x - e[i].x ) ;
                 ans += _abs(t[1].m - last) ; 
                 last = t[1].m ;
         }
         ans += t[1].m ; 
         
         printf("%d\n" , ans);
    }
    //system("pause");
    return 0 ;
}
