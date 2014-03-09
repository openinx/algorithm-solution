#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define maxn 100002
#define maxq 50002

int a[maxn] , q[maxq][3] , ia[maxn] , iq[maxq] , ans[maxq] , in[maxn] , n , m; 
struct node{
       int l , r , cover , cnt ;
}; 
node t[3*maxn] ;

void segtree_build(int x , int l , int r){
     t[x].l = l , t[x].r = r , t[x].cover = t[x].cnt = 0 ; 
     if(l == r)  return ;
     int mid = (l + r)>>1 ;
     segtree_build(x<<1 , l , mid );
     segtree_build((x<<1)+1 , mid+1 , r);
}

void segtree_update(int x , int l ,int r , int d){
     if(t[x].l == l && t[x].r == r){
            t[x].cover += d ;   return ;
     }
     int mid = (t[x].l + t[x].r)>>1 ;
     if(r <= mid ){
           segtree_update(x<<1 , l , r , d );
     }else if(mid < l){
           segtree_update((x<<1)+1 , l , r , d);
     }else{
           segtree_update(x<<1 , l , mid , d);
           segtree_update((x<<1)+1 , mid+1 , r , d);
     }
}

int segtree_query(int x , int p){
     if( t[x].l == t[x].r ){
          return  t[x].cover + t[x].cnt ;       
     }
     int mid = (t[x].l + t[x].r)>>1 ;
     t[x<<1].cover += t[x].cover ;                   
     t[(x<<1)+1].cover += t[x].cover ;  
     t[x].cnt += t[x].cover ;   t[x].cover = 0 ; 
     if(p <= mid ){
          return segtree_query(x<<1 , p );
     }else{
          return segtree_query((x<<1)+1 , p );
     }
}

int segtree_getkth(int k){
    int l , r , mid , rank ,ans ;
    l = 1 ; r = n ; 
    while(l<=r){
         mid = (l+r)>>1  ;  
         rank = segtree_query(1 , mid)+1;   //printf("mid = %d  rank = %d\n" ,mid , rank);
         if(k == rank ) {
               ans = mid ;
               l = mid + 1 ;
         }
         if(k <  rank )  r = mid -1 ; 
         if(k >  rank )  l = mid +1 ; 
    }
   return ans ;
}

void asort(int l ,int r){
     if(l == r)  return ;
     int i = l , j = r , x=a[(l+r)>>1] , tp ;
     do{
          while(a[i] < x) ++ i ; 
          while(a[j] > x) -- j ;
          if(i<=j){
              tp = a[i] ; a[i] = a[j] ; a[j] = tp ;
              tp =ia[i] ; ia[i]=ia[j] ; ia[j]= tp ; 
              i ++ ; j -- ;
          }
     }while(i<=j) ;
     if(i < r )  asort(i , r);
     if(l < j )  asort(l , j);
}

void qsort(int l , int r){
     if(l==r) return ;
     int i=l ,j=r , x = q[(l+r)>>1][0] , tp ;
     do{
         while(q[i][0] < x) ++ i ;
         while(q[j][0] > x) -- j ;
         if(i<=j){
              tp = q[i][0] ; q[i][0] = q[j][0] ; q[j][0] = tp ; 
              tp = q[i][1] ; q[i][1] = q[j][1] ; q[j][1] = tp ; 
              tp = q[i][2] ; q[i][2] = q[j][2] ; q[j][2] = tp ;
              tp = iq[i]   ; iq[i]   = iq[j]   ; iq[j]   = tp ;
              i++ ; j-- ;
         }
     }while(i<=j);
     if(i<r) qsort(i , r);
     if(l<j) qsort(l , j);
}

/*
int main(){
    int x , y;
    char cmd[343] ;
    segtree_build(1 , 1 , 10000);
    while(scanf("%s" ,cmd)!=EOF){
        if(!strcmp(cmd ,"ins")){
              scanf("%d%d" , &x ,&y);  segtree_update(1 , x ,y ,1);
        }else if(!strcmp(cmd ,"del")){
              scanf("%d%d" ,&x ,&y);   segtree_update(1 , x ,y ,-1);
        }else{
              scanf("%d%d" ,&x ,&y);   printf("ans : %d\n" , segtree_query(1 , x , y));
        }
    }
    return 0 ;
 }
*/



int main(){
    int i , k ; 
    scanf("%d%d" ,&n , &m);
    for(i = 1 ; i<= n ; ++ i)  {  
          scanf("%d"  ,&a[i]);  ia[i]= i ; 
    }
    for(i = 1 ; i<= m ; ++ i)  {  
          scanf("%d%d%d" , &q[i][0] , &q[i][1] , &q[i][2]);  iq[i] = i ; 
    }
    asort(1 , n);   qsort(1 , m);  
    //for(i = 1 ;i<=n ; ++i) printf(" %d" , a[i]); printf("\n");
    segtree_build(1 , 1 , n+1);
    for(i = 1 ; i<= n ; ++ i)  in[ia[i]] = i ;   //for(i = 1 ; i<=n ; ++i) printf(" %d" , in[i]);  printf("  end\n"); 
    for(i = 1 ; i<= m ; ++ i){
           if(i==1){
                     for(k = q[1][0] ; k<= q[1][1] ; ++ k)  segtree_update(1 , in[k]+1 , n+1 , 1);         
           }else{
                if(q[i-1][1] < q[i][0]){
                    for(k = q[i-1][0] ; k <= q[i-1][1] ; ++ k)  segtree_update(1 , in[k]+1 , n+1 , -1) ;
                    for(k = q[i][0] ; k <= q[i][1] ; ++ k)  segtree_update(1 , in[k]+1 , n+1 , 1);
                }else{
                    for(k = q[i-1][0] ; k < q[i][0] ; ++ k)  segtree_update(1 ,in[k]+1 , n+1 , -1 ) ;
                    for(k = q[i-1][1]+1 ; k <= q[i][1] ; ++k)  segtree_update(1 ,in[k]+1 , n+1 , 1);
                }
           }
           //printf("segtree_getkth = %d\n" , segtree_getkth(q[i][2]) );
           //printf(" query_segtree_3 -----  %d\n"  , segtree_query(1 , 4));
           ans[iq[i]] = a[segtree_getkth(q[i][2])];   //printf("  fuck_end \n");
    }
    for(i = 1 ;i <= m ;++ i) printf("%d\n" , ans[i]);
    //system("pause");
    return 0 ;
}
