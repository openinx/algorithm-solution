#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std ;
const int INF = 1000000000 ;
const int maxn = 50005 ; 
struct node{
       int l , r , val ;
};
node tree[3*maxn] ;
void segtree_build(int root , int l , int r ){
     tree[root].l = l , tree[root].r = r ,  tree[root].val = INF ; 
     if(l != r){
           int mid = (l + r) >> 1 ;
           segtree_build(root<<1 ,  l , mid  );
           segtree_build((root<<1)+1 , mid+1 , r );
     }
}

void segtree_update(int root , int p , int val ){
     tree[root].val = min(tree[root].val , val );
     if(tree[root].l != tree[root].r ){ 
             int mid = (tree[root].l + tree[root].r ) >> 1 ;
             if(p <= mid )  
                 segtree_update(root<<1 , p , val );
             else 
                 segtree_update((root<<1)+1 , p , val );
     }
}

int segtree_min(int root , int l , int r){
     if(l== tree[root].l && tree[root].r == r)  return tree[root].val ; 
     int  mid = (tree[root].l + tree[root].r)>>1 ;
     if(r <= mid )  return segtree_min(root<<1 , l , r ) ;
     if(mid < l )   return segtree_min((root<<1)+1 , l , r );
     return min(segtree_min(root<<1 , l , mid ) , segtree_min((root<<1)+1 , mid+1 , r) );
}

int main(){
    int n , m , s , t, temp , i , ans ;
    while(scanf("%d%d" , &n , &m)!=EOF){
          segtree_build(1 , 1 , n );
          segtree_update(1 , 1 , 0 );
          for(i = 1 ; i <= m ; ++ i){
              scanf("%d%d" , &s ,&t );
              temp = segtree_min(1 , s , t ) + 1 ;
              segtree_update(1 , t , temp );
          }
          ans = segtree_min(1 , n , n );
          printf("%d\n" , ans );
    } 
    return 0 ;
}
