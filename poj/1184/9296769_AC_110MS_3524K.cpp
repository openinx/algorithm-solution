#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std ;

typedef __int64 lld ;

const int MAXN = 400000 ;
const lld M    = 390003 ; 
const lld MASK = (lld)1<<30 ; 

struct node{  
   lld state ;
   lld next , step ; 
};

struct MyMap{
     node e[MAXN] ; 
     lld hd[MAXN] , es ;
     void init(){
          es = 0 ; 
          memset(hd ,-1 , sizeof(hd));
     }
     void insert(lld c , lld step ){
          lld x = c % M ; 
          e[es].next = hd[x] , e[es].state = c , e[es].step = step , hd[x] = es ++ ; 
     }
     int find(lld c){
          lld x = c % M ; 
          for(int i = hd[x] ; i!=-1 ; i=e[i].next )
              if(e[i].state == c ) return true ;
          return false ;
     }
}HashMap;

lld getCurson(lld now){
    return (now&(0xf<<24))>>24 ;
}
lld setCurson(lld now , lld pos){
    now -= now&(0xf<<24) ; 
    return now|(pos<<24) ;
}
lld getBit(lld now , lld i){
    return  (now&(0xf<<(i<<2)))>>(i<<2) ;
}
lld setBit(lld now , lld i , lld digit){
    now -= now&(0xf<<(i<<2)) ;
    return now|(digit<<(i<<2)) ;
}
lld getVisit(lld now){
    return ( now & (63LL<<30)) >> 30 ;
}
lld addVisit(lld now , lld i){
    return now |(MASK<<i) ;
}
lld getNext(lld now , lld i){
    lld next = now , curson=getCurson(now) ,  d0 , d5 , di ; 
    switch(i){
       case 0 :  // swap the first digit and the curson digit .
            d0 = getBit(now , 0)  ,  di = getBit(now ,curson);
            next = setBit(now , 0 , di) ;
            next = setBit(next, curson , d0 );
            next = addVisit(next , 0) ;
            return next ; 
       case 1 :  // swap the last digit and the curson digit .
            di = getBit(now ,curson)  ,  d5 = getBit(now , 5 );
            next = setBit(now , 5 ,di );
            next = setBit(next, curson , d5);
            next = addVisit(next , 5);
            return next ;
       case 2 :  // move the curson to left 
            curson = (curson>0 ? curson-1 : curson) ; 
            next = setCurson(now , curson);
            next = addVisit(next , curson);
            return next ;
       case 3 : // move the curson to right   
            curson = (curson<5 ? curson+1 : curson) ; 
            next = setCurson(now , curson);
            next = addVisit(next ,curson);
            return next ;
    }
}

lld q[MAXN] , head , tail ;

void bfs(){
     lld i ;
     lld src = 0 , now , next , step = 1  ; 
     for(i = 0 ; i < 6 ; ++ i)
         src = setBit(src , i , i);
     src = setCurson(src , 0);
     src = addVisit(src , 0);

     HashMap.init(); 
     head = tail = 0 ; 
     q[tail ++ ] = src ;  q[tail ++ ] = -1 ;
     HashMap.insert(src , 0 );  
     
     while(head < tail ){
           now = q[head ++ ] ;
           if(now == -1){
                  step ++ ; 
                  if(head < tail ){
                     now = q[head ++ ] ;
                     q[tail ++ ] = -1 ;
                  }else break ;
           } 
           
           for(i = 0 ; i < 4 ; ++ i){
                next = getNext(now , i);   
                if(next == now || HashMap.find(next) ) continue ;
                HashMap.insert(next , step );
                q[tail ++ ] = next ;
           }
     }
}


int main(){
    
    bfs();
    
    char start[8] , end[8] ; 
    while(cin>>start>>end){
        lld i , x , res = 0x7FFFFFFF , pos , k , temp ;
        lld state ,  visit ; 
        for(x = 0 ; x < MAXN ; ++ x)
           for(i = HashMap.hd[x] ; i!=-1 ; i=HashMap.e[i].next ){
                  state = HashMap.e[i].state ; 
                  visit = getVisit(state);
                  temp = HashMap.e[i].step ;
           
                  for(k = 0 ; k < 6 ; ++ k){
                        pos = getBit(state , k) ;
                        if(start[pos] != end[k] && 0 == (visit & (1<<k))){    
                              temp = 0x7FFFFFFF ; 
                              break ;
                        }else{ 
                              temp += abs(start[pos] - end[k]); 
                        }
                  } 
                  res = min(res , temp );
           } 
        cout << res << endl ;          
    }
    //system("pause");
    return 0 ;
}

