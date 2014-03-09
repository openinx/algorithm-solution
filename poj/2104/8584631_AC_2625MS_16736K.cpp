#include<stdlib.h>
#include<stdio.h>
//using namespace std ;
const int maxn = 100005 ;
const int maxk = 22     ; 

struct seg{
      int l , r ; 
};
seg tree[3*maxn];
int sort[maxk][maxn] , id[maxk][maxn] , key[maxn] , n , m , start , end , K ; 

void segtree_build(int root , int l , int r , int dep ){
     tree[root].l = l  ; tree[root].r = r ; 
     if(l == r ){ sort[dep][l] = key[l] ;  id[dep][l] = l ; return ; }
     int  mid =(l + r ) >> 1 , i , j , k  ;
     segtree_build(root<<1  ,  l    , mid ,   dep + 1);
     segtree_build((root<<1)+1 , mid+1 , r,   dep + 1);
     i = l , j = mid+1 , k = l ; 
     while(i<=mid && j <= r){
             if(sort[dep+1][i] < sort[dep+1][j]){
                  sort[dep][k] = sort[dep+1][i] ;  id[dep][k++] = id[dep+1][i++] ;   
             }else{
                  sort[dep][k] = sort[dep+1][j] ;  id[dep][k++] = id[dep+1][j++] ; 
             }
     }
     while(i<=mid) { sort[dep][k] = sort[dep+1][i] ; id[dep][k++] = id[dep+1][i++] ; }
     while(j<= r ) { sort[dep][k] = sort[dep+1][j] ; id[dep][k++] = id[dep+1][j++] ; }
}

int  segtree_search(int root , int value ,  int dep){
     int l , r , mid , ans = 0 ; 
     if(start <= tree[root].l && tree[root].r <= end){
              l =  tree[root].l  ;   r = tree[root].r ; 
              while(l <= r){
                     mid = (l + r ) >> 1 ;
                     if(sort[dep][mid] == value)  break ;  
                     if(sort[dep][mid] <  value)  l = mid + 1;
                     if(sort[dep][mid] >  value)  r = mid - 1;        
              }
              if(sort[dep][mid]== value )   return  mid - tree[root].l ; 
              if(sort[dep][mid] < value )   return  mid - tree[root].l + 1 ; 
              if(sort[dep][mid] > value )   return  mid - tree[root].l ; 
     }
     mid = (tree[root].l + tree[root].r) >> 1 ;
     if(start <= mid )    ans +=  segtree_search(root<<1    ,  value ,  dep + 1);
     if(mid+1 <= end )    ans +=  segtree_search((root<<1)+1,  value ,  dep + 1);
     return ans ;
}

int calc(){
    int l = 1 , r = n  , mid , rank ;
    while(l <= r ){
          mid = (l + r) >> 1 ;
          rank = segtree_search(1 , sort[1][mid] , 1) + 1 ;  //printf("rank = %d  ----- value= %d\n" , rank , sort[1][mid] );  
          if(rank == K && id[1][mid]>=start && id[1][mid] <= end )  return sort[1][mid] ; 
          if(rank <= K ){
                  l = mid + 1 ; 
          }else{
                  r = mid - 1 ;
          }
    }
    return 0 ; 
}

int main(){
    int i , j ;
    scanf("%d%d" ,&n ,&m);
    for(i = 1 ; i<= n ; ++ i)  scanf("%d" , &key[i]);
    segtree_build(1 , 1 , n , 1 );
    while(m--){
        scanf("%d%d%d" , &start , &end , &K);
        printf("%d\n", calc());           
    }
   // system("pause");
    return 0 ;
}
