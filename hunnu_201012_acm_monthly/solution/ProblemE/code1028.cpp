#include<iostream>
#include<set>
#include<stdlib.h>
using namespace std ;

const  int  maxn = 100010 ;
const  int  INF  = 1<<29 ; 

set<int> win ; 
set<int> :: iterator it ; 

struct node{
       int l , r , cnt ; 
};

node tree[3*maxn] ; 

void build(int l , int r , int i){
     tree[i].l = l , tree[i].r = r , tree[i].cnt = 0 ; 
     if(l + 1 == r)  return ; 
     int mid = (l + r) / 2 ; 
     build(l , mid , 2*i);
     build(mid , r , 2*i+1);
}

void ins(int x , int i){
     tree[i].cnt ++ ;
     if(tree[i].l + 1 == tree[i].r ) { 
          return ; 
     }
     int mid = (tree[i].l + tree[i].r ) / 2 ;
     if( x < mid )  
         ins(x , 2*i);
     else 
         ins(x , 2*i + 1) ;
}

int query(int l , int r , int i){
     if(tree[i].l == l && tree[i].r == r){
          return  tree[i].cnt ; 
     }
     int mid = (tree[i].l + tree[i].r) / 2 ;
     if(r <= mid )  
          return query(l , r , 2*i);
     else if(mid <= l )
          return query(l , r , 2*i+1);
     else  
          return query(l , mid , 2*i) + query(mid , r , 2*i+1);
}

int val[maxn] , valSize , big[maxn] , small[maxn] , seq[maxn]  , N ;

int  bbs(int x ){
     int l = 1 , r = valSize , mid ;
     while(l <= r){
           mid = (l + r) / 2 ; 
           if(val[mid] == x )  return mid ; 
           if(x < val[mid]) 
                r = mid - 1 ; 
           else 
                l = mid + 1 ; 
     } 
     return 0 ;
}

int main(){
    
    //freopen("1.std.in" , "r" , stdin); freopen("1.std.out" , "w" , stdout);
    //clock_t start , end ; 
    //start = clock();
    
    int TestCase , i , pos ; 
    scanf("%d" , &TestCase);
    while(TestCase -- ){
                   
          scanf("%d" , &N);
          
          win.clear();
          for(i = 1 ; i <= N ; ++ i){
                scanf("%d" , &seq[i]);  
                win.insert(seq[i]);
          }
          valSize = 0 ;  
          val[++valSize] = -INF ;  
          for(it = win.begin() ; it!= win.end() ; it ++ ){
                   val[ ++ valSize ] = *it ;  
          }
          val[++valSize] = INF ;
          memset(small , 0 ,sizeof(small));
          build(1 , valSize + 1 , 1);
          for(i = 1 ; i <= N ; ++ i){
               pos = bbs(seq[i]);
               small[i] = query(1,pos, 1);
               ins(pos , 1);
          }
          
          win.clear();
          for(i = 1; i <= N ; ++ i){
               seq[i] = -1 * seq[i] ; 
               win.insert(seq[i]);
          }
          valSize = 0 ; 
          val[++valSize] = -INF ;
          for(it = win.begin() ; it!=win.end() ; it++){
                val[ ++ valSize ] = *it ; 
          }
          val[++valSize] = INF  ;
          memset(big , 0 , sizeof(big));
          build(1 , valSize + 1 , 1);
          for(i = N ; i>=1 ; --i){
               pos = bbs(seq[i]);
               big[i] = query(1 , pos ,1);
               ins(pos , 1);
          }
          
          __int64 tot = 0  ; 
          for(i = 1 ; i <= N  ; ++ i){
               tot += (__int64)(big[i]*small[i]);
          }
          printf("%I64d\n" , tot);
    }
    
    
    //end = clock();  printf("Time : %d ms" , (int)(end - start));
    
    //fclose(stdin);  fclose(stdout);
    
    return 0 ;
}    
