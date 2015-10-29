#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)|1)
#define maxn  105 

typedef struct{
    double x ,y0 ,y1 ;
    int type ;    
}event;
typedef struct node{
    int l , r , cnt ;
    double m ; 
}node;

int n , ps , es ;
double posY[2*maxn] , py[2*maxn] ;
event e[2*maxn] ;
node  t[6*maxn] ; 

int bs(double x){
    int l = 1 , r = ps , mid ;
    while(l<=r){
        mid = (l+r)>>1 ;
        if(posY[mid] == x) return mid ;
        if( x < posY[mid]) r = mid -1 ;
        if( x > posY[mid]) l = mid +1 ; 
    }
    return 0 ;
}

void double_sort(double *a , int l , int r){
     int i = l , j = r ; 
     double x = a[(l+r)>>1] , temp ;
     if(l>=r) return ;
     do{
         while(a[i]<x) ++ i ; 
         while(a[j]>x) -- j ;
         if(i<=j){
            temp = a[i] ; a[i] = a[j] ; a[j] = temp ;
            i++ ; j-- ;
         }
     }while(i<=j) ;
     if(i<r) double_sort(a , i , r);
     if(l<j) double_sort(a , l , j);
}

int less(event a , event b){
    if(a.x != b.x ) return a.x < b.x ;
    return a.type > b.type ;  
}

void event_sort(event *a , int l ,int r){
     if(l>=r) return ;
     int i = l , j = r ;
     event x = a[(l+r)>>1] , temp ; 
     do{
          while(less(a[i] , x)) ++ i ;
          while(less(x , a[j])) -- j ; 
          if(i<=j){
              temp = a[i] ; a[i] = a[j] ; a[j] = temp ; 
              ++ i ; -- j ; 
          }
     }while(i<=j) ;
     if(i<r) event_sort(a , i , r);
     if(l<j) event_sort(a , l , j);
}

void update(int x){
     if(t[x].cnt){
         t[x].m = posY[t[x].r] - posY[t[x].l];  //printf("cedu:%0.2lf\n" , t[x].m);
     }else if(t[x].r-t[x].l==1){
         t[x].m = 0 ; 
     }else{
         t[x].m = t[L(x)].m + t[R(x)].m ; 
     }
}

void segtree_build(int x , int l ,int r){
     int mid ;
     t[x].l = l , t[x].r = r , t[x].cnt = 0 , t[x].m = 0 ; 
     if(r-l!=1){
            mid = (l+r)>>1 ;
            segtree_build(L(x) , l , mid);
            segtree_build(R(x) ,mid ,  r);
     }
}

void segtree_insert(int x , int l , int r , int delta){
     int mid = (t[x].l + t[x].r)>>1 ;
     if(t[x].l == l && t[x].r == r){
          t[x].cnt += delta ; 
     }else if(r<=mid){
          segtree_insert(L(x) , l , r , delta);
     }else if(mid<=l){
          segtree_insert(R(x) , l , r , delta);
     }else {
          segtree_insert(L(x) , l ,mid, delta);
          segtree_insert(R(x) ,mid, r, delta);
     }
     update(x);
}

int main(){
    double x0 , y0 , x1 , y1 , area ;
    int i , cid = 0 , l , r ;
    while(scanf("%d" ,&n)!=EOF && n){
         es = ps = 0 ;
         for(i = 1 ; i<=n ;++i){
              scanf("%lf%lf%lf%lf" , &x0 , &y0 , &x1 , &y1);
              ++ es ; e[es].x = x0 , e[es].y0 = y0 , e[es].y1 = y1 , e[es].type = +1 ;  py[es] = y0 ; 
              ++ es ; e[es].x = x1 , e[es].y0 = y0 , e[es].y1 = y1 , e[es].type = -1 ;  py[es] = y1 ;
         }
         double_sort(py , 1 , es);
         posY[1] = py[1] ;  ps = 1 ; 
         for(i = 2 ; i<=2*n ; ++ i)  
            if(posY[ps]!=py[i])   posY[++ps] = py[i] ;
         event_sort(e , 1 , es);
         area = 0 ;
         
         //for(i = 1 ; i<=ps; ++i) printf("posY[%d] = %0.2lf\n" , i , posY[i]);
         
         segtree_build(1 , 1 , ps);   
         for(i = 1 ; i <es ; ++ i){
             l = bs(e[i].y0) ; r = bs(e[i].y1);  
             segtree_insert(1 , l , r , e[i].type);  
             //printf("TYPE = %d   ===== " , e[i].type);
             //printf("%0.2lf\n" , t[1].m);
             area += t[1].m * (e[i+1].x - e[i].x ) ;
             //printf("[%d , %d]\n" , l , r);
         }
         /**/
         printf("Test case #%d\nTotal explored area: %0.2lf\n\n" , ++cid , area) ; 
    }
    //system("pause");
    return  0 ;
}
