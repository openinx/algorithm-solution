#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 100005

struct node{
     int l , r , flag , c ;
};
node t[3*maxn] ;

inline void swap(int &x , int &y){
       int temp  ; 
       temp = x ; x = y ; y = temp ;
}

void build(int x , int l ,int r){
     t[x].l = l , t[x].r = r , t[x].flag = 0 , t[x].c = 1 ; 
     if(l == r )  return ; 
     int mid = (t[x].l + t[x].r) >> 1 ;
     build(x<<1 , l ,  mid );
     build((x<<1)+1 , mid+1 , r );
}

void down(int x){
     if(t[x].flag){
          t[x<<1].flag = 1 ;  t[x<<1].c = t[x].c ; 
          t[(x<<1)+1].flag = 1 ; t[(x<<1)+1].c = t[x].c ; 
          t[x].flag = 0 ; 
     }
}

void up(int x){
     t[x].c = t[x<<1].c | t[(x<<1)+1].c ;
}

void ins(int x , int l ,int r , int c){
     if(t[x].l == l && t[x].r == r){
         t[x].flag = 1 ;   t[x].c = c  ;   return ; 
     }
     down(x);
     int mid = (t[x].l + t[x].r )>>1 ; 
     if(r <= mid )  
         ins(x<<1 , l , r , c );
     else if(mid < l )
         ins((x<<1)+ 1 , l , r , c);
     else {
         ins(x<<1 , l , mid , c );
         ins((x<<1)+1 , mid+1 , r , c);
     }
     up(x);
}

int query(int x , int l , int r){
    if(t[x].l == l && t[x].r == r){
          return t[x].c ; 
    }
    down(x);
    int ans , mid = (t[x].l + t[x].r)>>1 ; 
    if(r <= mid )
         ans = query(x<<1 , l , r);
    else if(mid < l )
         ans = query((x<<1)+1 , l , r);
    else 
         ans = query(x<<1 , l , mid)|query((x<<1)+1 , mid+1 , r ) ;
    up(x);
    return ans ; 
}

int main(){
    char cmd[3] ;
    int i , L , T , O , A , B , C , ans ; 
    scanf("%d%d%d" , &L , &T , &O);
    build(1 , 1 , L );
    while(O--){
        scanf("%s" ,cmd);
        switch(cmd[0]){
            case 'C': 
                 scanf("%d%d%d" , &A , &B ,&C);
                 if(A>B)  swap(A , B);
                 C = 1<<(--C) ; 
                 ins(1 , A , B , C);
                 break ; 
            case 'P':
                 scanf("%d%d" ,&A , &B);
                 if(A>B)  swap(A ,B);
                 C = query(1 , A , B);
                 ans = 0 ; 
                 for(i = 0 ; i < T ; ++ i)
                    if(C&(1<<i))  ans ++ ; 
                 printf("%d\n" , ans);
                 break ;
            default: 
                 break ;
        }
    }
    //system("pause");
    return 0 ;
}



