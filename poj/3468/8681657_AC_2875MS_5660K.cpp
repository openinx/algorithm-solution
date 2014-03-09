#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std ;

const int MAXN = 400010 ; 

typedef __int64 lld ; 
#define keyTree (e[e[root].ch[1]].ch[0])
typedef struct {
        int ch[2] , pre , sz ;
        lld add , sum , val ; 
}Node;

struct SplayTree{
       int es , root ; 
       Node e[MAXN] ; 
       int que[MAXN] , stack[MAXN] , head , tail , top ; 
       
       inline int L(int x){ return e[x].ch[0] ; }
       inline int R(int x){ return e[x].ch[1] ; }
       inline int F(int x){ return e[x].pre   ; }
       
       void rotate(int x){
            int y , z , f ; 
            y = F(x) , z = F(y) , f = (R(y)==x) ;
            down(y) ; 
            down(x) ; 
            e[y].ch[f] = e[x].ch[!f] ;  
            if(e[x].ch[!f])  
                e[e[x].ch[!f]].pre = y ; 
            e[x].pre = e[y].pre ;  
            e[x].ch[!f] = y ;  
            e[y].pre = x ; 
            if(z) e[z].ch[R(z)==y] = x ; 
            if(y == root) root = x ; 
            up(y);
       }
       
       void splay(int x ,int goal){
            int y , z , f ;
            down(x);
            while(F(x)!=goal ){
                   if(F(F(x)) == goal){  
                       rotate(x) ;
                   }else{
                       y = F(x) , z = F(y) , f = (R(z)==y);
                       if(e[y].ch[f]==x){
                            rotate(y);  rotate(x);
                       }else{
                            rotate(x);  rotate(x);
                       }
                   }
            }
            up(x);
       }
       
       void rotateTo(int k , int goal){  // rotate the k_th Number to be the child of goal.
            int x = root , tot ; 
            ++ k ; 
            while(1){
                 down(x) ;
                 tot = e[L(x)].sz + 1 ;
                 if(k == tot)  break ;
                 if(k <  tot){
                    x = L(x);
                 }else{
                    x = R(x);
                    k -= tot; 
                 }
            }
            splay(x , goal);
       }
       
       void up(int x){
            e[x].sz  = 1 + e[L(x)].sz + e[R(x)].sz  ;
            e[x].sum = e[x].val + e[x].add + e[L(x)].sum + e[R(x)].sum ; 
       }
       
       void down(int x){
            if(e[x].add){
                  e[x].val += e[x].add ; 
                  //e[x].sum += e[x].sz * e[x].add ; 
                  e[L(x)].add += e[x].add ; 
                  e[R(x)].add += e[x].add ;    
                  e[L(x)].sum += e[L(x)].sz * e[x].add ; 
                  e[R(x)].sum += e[R(x)].sz * e[x].add ; 
                  e[x].add = 0 ; 
            }
       }
       
       void update(int l , int r , lld c){
            rotateTo(l-1 , 0);
            rotateTo(r+1 , root) ;
            e[keyTree].add += c ; 
            //e[keyTree].val += add ;
            e[keyTree].sum += e[keyTree].sz * c ; 
       }
       
       lld query(int l , int r ){
           rotateTo(l-1 , 0 );
           rotateTo(r+1 , root);
           return e[keyTree].sum ; 
       }

       int newNode(int v , int father){
              int x = (top ? stack[--top]: ++es ) ;
              e[x].ch[0] = e[x].ch[1] = 0 ;  
              e[x].sz = 1;  
              e[x].pre = father ;  
              e[x].add = 0 ;  
              e[x].sum = e[x].val = v ;   
              return x ;
       }
       
       int makeTree(int *a , int l , int r , int father ){
           if(l > r )  return 0 ; 
           int mid = (l + r)>>1 , x ;
           x = newNode(a[mid] , father);
           e[x].ch[0] = makeTree(a , l , mid-1 , x);
           e[x].ch[1] = makeTree(a ,mid+1 , r  , x); 
           up(x);
           return x ;
       }
       
       void init(int *a , int n){
            top = es = 0 ;  
            e[0].ch[0] = e[0].ch[1] = e[0].pre = e[0].sz = 0 ;
            root = newNode(-1 , 0 ) ;  
            e[root].ch[1] = newNode(-1 , root );  
            up(R(root));  
            up(root);
            keyTree  = makeTree(a , 1 ,  n , e[root].ch[1]);
            up(R(root));
            up(root);
       }    
       
       /*
       void showNode(int x ){
            printf("value=%3d size=%3d Sum=%3d Add=%3d Left_son=%3d Right_son=%3d Father=%3d\n" , e[x].val ,e[x].sz , e[x].sum , e[x].add , L(x) , R(x) , F(x));
       }

       void traval(int x ){
            if(x){
                traval(L(x));
                showNode(x);
                traval(R(x));
            }
       }
       
       void debug(){
            //showNode(0);
            printf("The element in tree is :\n");
            traval(root);
            printf("\n");
       }*/
};

SplayTree T ; 

int main(){
    
    //freopen("poj3468.in" , "r" , stdin); freopen("poj3468.out" , "w" ,stdout);
    
    char cmd[5] ; 
    int a[MAXN] , N , Q , l , r , i;
    lld c ;
    scanf("%d%d" , &N , &Q);
    for(i = 1 ; i <= N ; ++ i)
        scanf("%d" , &a[i]);
    T.init(a , N);
    while(Q--){
         scanf("%s" , cmd);
         if(cmd[0] =='Q'){
              scanf("%d%d" , &l ,&r) ;
              printf("%I64d\n" , T.query(l , r)); 
         }else if(cmd[0] == 'C'){
              scanf("%d%d%I64d"  ,&l , &r , &c);
              T.update(l , r , c) ;
         }
    }
    //system("pause");
    return 0 ;
}
