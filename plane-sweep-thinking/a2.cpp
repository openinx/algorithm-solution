#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<set>
#define maxn  30005
using namespace std ;

typedef __int64 lld ;

struct rect{
     int x0 , y0 , x1 , y1 , h ; 
};

struct event{
     int x , y0 , y1 , type ;
};

struct node{
     int l , r , cnt , m ; 
}; 

node t[6*maxn] ;
event e[2*maxn] ; 
rect r[maxn] , Rt[maxn] ;
set<int> win ; 
set<int>::iterator it ;
int Height[4] , M  , n , Rs , posY[2*maxn] , es , ps ; 

inline bool cmp(event a , event b ){
     if(a.x != b.x )  return a.x < b.x ; 
     return a.type > b.type ;
}

inline int L(int x) { return x<<1 ; }
inline int R(int x) { return (x<<1)|1 ; }

int bs(int x ){
    int l = 1 , r = ps , mid  ; 
    while(l<=r){
         mid = (l + r)>>1 ; 
         if(posY[mid] == x )  return mid ;
         if(x < posY[mid]  )  r = mid - 1; 
         if(x > posY[mid]  )  l = mid + 1;
    }
    return 0 ;
}

void Build(int x , int l , int r){
     int mid ; 
     t[x].l = l , t[x].r = r , t[x].cnt = t[x].m = 0 ;
     if(l + 1 != r){
          mid = (l + r)>>1 ;
          Build(L(x) , l , mid );
          Build(R(x) , mid , r );
     }
} 

void Update(int x ){
     if(t[x].cnt > 0 ){
           t[x].m = posY[t[x].r] - posY[t[x].l] ; 
     }else if(t[x].l + 1 == t[x].r ){
           t[x].m = 0 ;
     }else {
           t[x].m = t[L(x)].m + t[R(x)].m ; 
     }
}

void Insert(int x ,int l , int r , int d ){
     if(t[x].l == l && t[x].r == r){
             t[x].cnt += d ;  
     }else{
           int mid = (t[x].l + t[x].r)>>1 ; 
           if(r <= mid ) 
               Insert(L(x) , l , r , d );
           else if(mid <= l)
               Insert(R(x) , l , r , d );
           else {
               Insert(L(x) , l , mid ,d);
               Insert(R(x) ,mid ,r ,  d);
           }
     }
     Update(x);
}

lld calc_area(){
    int i , j ;
    lld  area ; 
    es =0 ;  area = 0 ;  win.clear() ;
    for(i = 1 ; i <= Rs ; ++i){
         win.insert(Rt[i].y0);  win.insert(Rt[i].y1);
         ++es ;  e[es].x = Rt[i].x0 ;  e[es].y0 = Rt[i].y0 ;  e[es].y1 = Rt[i].y1 ;  e[es].type = +1 ;
         ++es ;  e[es].x = Rt[i].x1 ;  e[es].y0 = Rt[i].y0 ;  e[es].y1 = Rt[i].y1 ;  e[es].type = -1 ;
    }
    
    for(it = win.begin() , ps = 0 ;  it!=win.end() ; it ++ )
         posY[++ps] = *it ;
    
    sort(e+1 , e+es+1 , cmp );
    
    Build(1 , 1 , ps);
    
    for(i = 1 ; i < es ; ++ i){
            Insert(1 , bs(e[i].y0) , bs(e[i].y1) , e[i].type );
            area += (lld)t[1].m * (lld)(e[i+1].x - e[i].x ) ;
    }
    return area ; 
}

int main(){
    int acase , i , h , cid = 0 ; 
    lld ans , square ; 
    scanf("%d" ,&acase );
    while(acase--){
          scanf("%d%d" , &n , &M);
          for(i = 1 ;i<=M ; ++i)  scanf("%d" ,&Height[i]);
          for(i = 1 ; i<=n ; ++i){
                scanf("%d%d%d%d%d" , &r[i].x0 , &r[i].y0 , &r[i].x1 , &r[i].y1 , &r[i].h );
                r[i].h = Height[r[i].h] ;
          }
          sort(Height+1 , Height+M+1);  //printf("%I64d");
          Height[0] = 0 ;   ans = 0 ; 
          for(h = 1 ; h <= M ; ++ h){
                Rs = 0 ; 
                for(i = 1 ; i<=n ; ++ i)
                      if(r[i].h >= Height[h]){
                           Rt[++Rs] = r[i] ;
                      }
                //printf("Rs : %I64d\n" ,Rs);
                square = calc_area() ;  //printf("square : %d\n" , square);
                ans += square * (Height[h] - Height[h-1] ) ;
          }
          printf("Case %d: %I64d\n" , ++cid , ans );          
    }
    //system("pause");
    return 0 ;
}
