#include<stdlib.h>
#include<stdio.h>
#define maxn 200005

struct node{
    int l , r , c ;
};
node t[3*maxn] ;
int  position[maxn] , value[maxn] , ans[maxn] ;

void build(int x , int l , int r){
     t[x].l = l , t[x].r = r  ; 
     if(t[x].l == t[x].r){
           t[x].c = 1 ;   return ;
     }
     int mid = (t[x].l + t[x].r)>>1 ; 
     build(x<<1 , l , mid );
     build((x<<1)+1 , mid+1 ,r );
     t[x].c = t[x<<1].c + t[(x<<1)+1].c ;
}

int query(int x , int pos){
    if(t[x].l == t[x].r )  {
         t[x].c = 0 ; return t[x].l ;
    } 
    int ans  ; 
    if(pos <= t[x<<1].c ) 
         ans = query(x<<1 , pos );
    else  
         ans = query((x<<1)+1 , pos - t[x<<1].c);
    t[x].c = t[x<<1].c + t[(x<<1)+1].c ; 
    return ans ;
}

/*
void del(int  x , int p){
     if(t[x].l == t[x].r )  {
         t[x].c = 0 ;   return ;
     }
     int mid = (t[x].l + t[x].r )>>1 ; 
     if( p <= mid )
          del(x<<1 ,  p);
     else 
          del((x<<1)+1 , p);
     t[x].c = t[x<<1].c + t[(x<<1)+1].c ;
}
*/

int main(){
    int i , n , idx ; 
    while(scanf("%d" ,&n)!=EOF){
          for(i = 1 ; i<=n ; ++ i){
               scanf("%d%d" ,&position[i] , &value[i]);
          }
          build(1 , 1 , n );
          for(i = n ; i>=1 ;--i){
               idx = query(1 , position[i]+1) ;          
               //del(1 ,  idx);
               ans[idx] = value[i] ; 
          }
          printf("%d" , ans[1]);
          for(i = 2 ; i<=n ; ++ i)  
              printf(" %d" , ans[i]);
          printf("\n");
    }
    //system("pause");
    return 0 ;
}
