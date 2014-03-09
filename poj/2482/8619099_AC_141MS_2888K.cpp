#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn  100005 

typedef __int64 lld ;

/*
线段树节点说明： 
mxs 表示以 L 为起点的最大前缀和 ;
sum 表示[l,r]区间的数值总和  ; 
*/ 
struct seg_node{
       lld l , r , mxs , sum ;  
};
seg_node t[6*maxn] ; 

lld n , W , H , sx[maxn] , sy[maxn] ,hy[maxn] , level[maxn] ;
lld py[2*maxn] , posY[2*maxn] , ps ; 

inline lld L(lld x){
       return x<<1 ;
}

inline lld R(lld x ){
       return (x<<1)+1 ;
}

inline lld max(lld x ,lld y){
       return x > y ? x : y ; 
}

inline void swap(lld &x , lld &y){
       lld temp ; 
       temp = x ; x = y ; y = temp ;
}

void lld_sort(lld *a , lld l ,lld r){
     lld i = l , j = r , x = a[(l+r)>>1] , temp ; 
     do{
         while(a[i]<x) ++ i ; 
         while(a[j]>x) -- j ; 
         if(i<=j){
             swap(a[i] , a[j]);
             ++ i ; -- j ;
         }
     }while(i<=j) ; 
     if(i<r) lld_sort(a , i , r);
     if(l<j) lld_sort(a , l , j);
}

void star_sort(lld l ,lld r){
     lld i = l  , j = r , x = sx[(l+r)>>1] ,  temp ; 
     do{
         while(sx[i]<x) ++ i ; 
         while(sx[j]>x) -- j ; 
         if(i<=j){
              swap(sx[i] , sx[j]);
              swap(sy[i] , sy[j]);
              swap(hy[i] , hy[j]);
              swap(level[i] , level[j]);
              ++ i ; -- j ; 
         }
     }while(i<=j) ; 
     if(i<r) star_sort(i , r);
     if(l<j) star_sort(l , j);
}

lld bs(lld fuck){
    lld l = 1 , r = ps , mid ; 
    while(l<=r){
          mid = (l+r)>>1 ;
          if(posY[mid] == fuck) return mid ; 
          if(posY[mid] >  fuck) r = mid - 1;
          if(posY[mid] <  fuck) l = mid + 1 ;
    }
    return 0 ;
}

void segtree_build(lld x , lld l , lld r ){
     lld mid = (l+r)>>1 ;
     t[x].l = l , t[x].r = r , t[x].sum = t[x].mxs = 0 ;
     if(l != r){
          segtree_build(L(x) , l ,  mid);
          segtree_build(R(x) ,mid+1 ,r );     
     }
}

void segtree_insert(lld x , lld leaf , lld value ){
     if(t[x].l == t[x].r ){
          t[x].sum += value ;  t[x].mxs = t[x].sum ;
          return ;
     }
     lld mid = (t[x].l + t[x].r)>>1 ; 
     if(leaf <= mid )  segtree_insert(L(x) , leaf , value);
     if(mid  < leaf )  segtree_insert(R(x) , leaf , value);
     t[x].sum = t[L(x)].sum + t[R(x)].sum ; 
     t[x].mxs = max(t[L(x)].mxs ,  t[L(x)].sum + t[R(x)].mxs );
}

/*
void dfs(int x){
     printf("dfs order : %d\n" , t[x].sum );
     if(t[x].l != t[x].r ){
         dfs(L(x));
         dfs(R(x));
     }  
}
*/


int main(){
    
    //freopen("poj2482.in" , "r" , stdin);  freopen("hu2482.out" , "w"  , stdout);
    
    lld i , cur , ans ; 
    
    while(scanf("%I64d%I64d%I64d" ,&n, &W ,&H)!=EOF){
        
        for(i = 1 ; i<=n ; ++i) {
            scanf("%I64d%I64d%I64d" , &sx[i] , &sy[i] , &level[i]);
            py[2*i-1] = sy[i] ;  py[2*i] = sy[i] + H ;  hy[i] = sy[i] + H ;
        }
        
        lld_sort(py , 1 , 2*n);
        
        posY[1] = py[1] ;  ps = 1 ; 
        for(i = 2 ; i<=2*n ; ++ i)
           if(posY[ps]!=py[i]) 
               posY[++ps] = py[i] ;
        
        star_sort(1 , n);
        
        for(i = 1 ; i<=n ; ++i){
             hy[i] = bs(hy[i]);
             sy[i] = bs(sy[i]);
        }
               
        segtree_build(1 , 1 , ps);
        cur = 1 ;   ans = 0 ; 
        for(i = 1 ; i<=n ; ++i){
               for(; cur<=n ; ++cur)
                   if(sx[cur]-sx[i] < W ){
                         segtree_insert(1 , sy[cur] ,+level[cur]);
                         segtree_insert(1 , hy[cur] ,-level[cur]);
                         ans = max(ans , t[1].mxs );
                   }else break ;
                   
               //printf("max_prefix  ==== %I64d\n" , t[1].mxs );
        
               segtree_insert(1 , sy[i] , -level[i]);
               segtree_insert(1 , hy[i] , +level[i]);
        }
        
        //dfs(1);
        
        printf("%I64d\n" , ans);
    }
    //system("pause");
    return 0 ;
}
