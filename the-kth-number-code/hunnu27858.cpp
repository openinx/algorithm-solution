#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std ; 

struct Heap{
       
       const static int HEAP_MAXN = 200005 ;
       
       int h[HEAP_MAXN] , size ;
       void init(){
            size = 0 ;
       }
       void push(int v){
            int i ,  j ; 
            h[++size] = v ;  i = size ; 
            while(i > 1){
                 j = i>>1 ; 
                 if(h[j] > h[i]){
                     swap(h[i] , h[j]);
                 }else break ; 
                 i = j ; 
            } 
       }
       int pop(){
           int res = h[1] , i = 1 , j ;
           h[1] = h[size--] ; 
           while(2*i <= size){
                 j = i<<1 ;
                 if(h[j+1]<h[j] && j+1<=size) ++j ; 
                 if(h[j] < h[i]){
                     swap(h[i] , h[j]);
                 }else break ;
                 i = j ; 
           } 
           return res ;
       }
       int top(){ 
           return h[1] ; 
       }
       int empty() { 
           return size==0 ; 
       }
};

struct SplayTreeNode{
     int ch[2] , pre , sz ;
     int v ; 
};

struct SplayTree{
     
     const static int SPLAY_MAXN = 200005 ;
     
     inline int L(int x) { return e[x].ch[0] ; }
     inline int R(int x) { return e[x].ch[1] ; }
     inline int F(int x) { return e[x].pre   ; }
       
     SplayTreeNode e[SPLAY_MAXN] ; 
     int  es , root , stack[SPLAY_MAXN] , top , size ; 
     
     inline int get(int x){  return e[x].v ; }
     
     void init(){
         es = root = top = size = 0 ; 
         e[0].ch[0] = e[0].ch[1] = e[0].pre = e[0].sz = 0 ;
     }
     
     int newNode(int v ,int father){
         int x = (top ? stack[--top] : ++es ) ;
         e[x].pre = father ;
         e[x].sz = 1 ;
         e[x].v = v ; 
         e[x].ch[0] = e[x].ch[1] = 0 ;
         return x ;
     }
     
     void clrNode(int x){
          if(x) stack[top++] = x ;
     }
     
     void rotate(int x){
          if(!x) return ; 
          int y , z , f ; 
          y = F(x) , z = F(y) , f = (R(y)==x);
          e[y].ch[f] = e[x].ch[!f] ; 
          if(e[x].ch[!f]) 
             e[e[x].ch[!f]].pre = y ;
          e[x].ch[!f] = y ;  
          e[y].pre = x ; 
          e[x].pre = z ; 
          if(z) 
            e[z].ch[R(z)==y] = x ; 
          e[x].sz = e[y].sz ;
          e[y].sz = e[L(y)].sz + e[R(y)].sz + 1 ; 
          if(y == root) root = x ; 
     }
     
     void splay(int x , int goal){
          int y , z , f ; 
          while(F(x)!=goal){
                if(F(F(x))==goal){
                    rotate(x);
                }else{
                    y = F(x) , z = F(y) , f = (R(z)==y);
                    if(e[y].ch[f] == x){
                        rotate(y);  rotate(x);
                    }else{
                        rotate(x);  rotate(x);
                    }
                }
          }
     }
     
     void insert(int v){
          int x = root , y = 0 ; 
          ++ size ; 
          if(root == 0){
               root = newNode(v , 0); return ;
          }
          while(x){
               y = x ;
               if(v <= e[x].v){
                    x = L(x);
               }else{
                    x = R(x);
               }
          }
          x = newNode(v , y);
          if(v <= e[y].v ){
               e[y].ch[0] = x ;
          }else{
               e[y].ch[1] = x ;
          }
          splay(x , 0);
     }
     
     int find(int v){
          int y = 0 , x = root ; 
          while(x){
               y = x ;
               if(v == e[x].v ) break ; 
               if(v < e[x].v){
                    x = L(x);
               }else{
                    x = R(x);
               }
          }
          splay(x ? x:y , 0);
          return x ;
     }
     
     void erase(int v){
          if(find(v)==0) return ;
          int y = L(root) , z = R(root) ; 
          -- e[root].sz ;  -- size ; 
          if(y == 0){
               clrNode(root);
               root = z ;
               e[root].pre = 0 ;
          }else{
               while(R(y)){ 
                  --e[y].sz ; y = R(y);
               } 
               -- e[y].sz ;
               splay(y , root);
               if(z){
                  e[z].pre = y ; e[y].ch[1] = z ;
               }
               clrNode(root);
               root = y ; 
               e[root].pre = 0 ; 
          }
     }
     
     int getkth(int k){
         if(k < 1 || k > size ) return 0 ; 
         int x = root , y = 0 , ls ;
         while(x){
              y = x ;
              ls = e[L(x)].sz + 1 ; 
              if(k == ls ) break ; 
              if(k <  ls ){
                  x = L(x); 
              }else{
                  k -= ls ; x = R(x);
              }
         }
         splay(x , 0);
         return x ; 
     }
     
     void traval(int x){
          if(x){
              traval(L(x));
              printf(" %d" , e[x].v);
              traval(R(x));
          }
     }
     
     void debug(){
          printf("The Element Is :");  traval(root);  printf("     =====Size = %d\n" , size); 
     }
};

SplayTree T ;
Heap H ;

int main(){ 
    int cmdSize , minPay , k , addPay , delCnt ; 
    char cmd[5] ;
    scanf("%d%d" , &cmdSize , &minPay);
    T.init() ;   
    H.init() ;
    addPay = 0 ;  delCnt = 0 ;
    while(cmdSize--){
        scanf("%s%d" , cmd , &k);
        if(cmd[0]=='I'){
             if(k >= minPay){
                T.insert(k - addPay);
                H.push(k-addPay);
             }
        }else if(cmd[0]=='A'){
             addPay += k ; 
        }else if(cmd[0]=='S'){
             addPay -= k ; 
             while(!H.empty() && H.top() + addPay < minPay ){
                   k = H.pop() ;  
                   T.erase(k);     delCnt ++ ; 
             }
        }else if(cmd[0]=='F'){
             if(k > T.size ) 
                  printf("-1\n");
             else 
                  printf("%d\n" , T.get(T.getkth(T.size-k+1)) + addPay);
        }
        //T.debug();
    }    
    printf("%d\n" , delCnt);
    //system("pause");
    return 0 ;
}
