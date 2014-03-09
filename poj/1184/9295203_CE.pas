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
const int M = 6000007 ;

struct node{  
   bool tag ;
   int c , next ; 
};
struct MyMap{
     node e[M] ; 
     int hd[M] , es ;
     void init(){
          es = 0 ; memset(hd ,-1 , sizeof(hd));
     }
     void insert(int c , bool tag){
          int x = c % M ; 
          e[es].next = hd[x] , e[es].c = c ,  e[es].tag = tag , hd[x] = es ++ ; 
     }
     bool find(int c , bool tag){
          int x = c % M ; 
          for(int i = hd[x] ; i!=-1 ; i=e[i].next )
              if(e[i].c == c && e[i].tag == tag ) return true ;
          return false ;
     }
}HashMap;

int getCurson(int now){
    return (now&(0xf<<24))>>24 ;
}
int setCurson(int now , int pos){
    now -= now&(0xf<<24) ; 
    return now|(pos<<24) ;
}
int getBit(int now , int i){
    return  (now&(0xf<<(i<<2)))>>(i<<2) ;
}
int setBit(int now , int i , int digit){
    now -= now&(0xf<<(i<<2)) ;
    return now|(digit<<(i<<2)) ;
}

int getNext(int now , int i){
    int next = now , curson=getCurson(now) ,  d0 , d5 , di ; 
    switch(i){
       case 0 :
            d0 = getBit(now , 0)  ,  di = getBit(now ,curson);
            next = setBit(now , 0 , di) ;
            next = setBit(next, curson , d0 );
            return next ; 
       case 1 :  
            di = getBit(now ,curson)  ,  d5 = getBit(now , 5 );
            next = setBit(now , 5 ,di );
            next = setBit(next, curson , d5);
            return next ;
       case 2 :  
            di = getBit(now ,curson) ;  di = (di<9 ? di+1 : 9) ; 
            next = setBit(now , curson , di);
            return next ;
       case 3 :  
            di = getBit(now ,curson) ;  di = (di>0 ? di-1 : 0 ) ; 
            next = setBit(now , curson ,di);
            return next ;
       case 4 :  
            curson = (curson>0 ? curson-1 : 0) ; 
            next = setCurson(now , curson);
            return next ;
       case 5 :  
            curson = (curson<5 ? curson+1 : 5) ; 
            next = setCurson(now , curson);
            return next ;
    }
}

int encode(char *s){
    int now = 0 ; 
    now = setCurson(0 , 0);
    for(int i = 0 ; i< 6 ;++i)
       now = setBit(now , i , s[i]-'0');
    return now ;
}

void decode(int now){
    cout << "curson:" << getCurson(now) <<" ";
    for(int i = 0 ; i < 6 ; ++ i)
      cout << getBit(now ,i);
    cout << endl;
}

int qSrc[M] , qsHead , qsTail ;
int qDes[M] , qdHead , qdTail ; 

int bfs(int src , int des){
    if(src == des) return 0 ; 
    int step = 0 , i , now , next ; 
    
    qsHead = qsTail = 0 ;  
    qSrc[qsTail++] = setCurson(src , 0); qSrc[qsTail++] = -1 ;
    
    qdHead = qdTail = 0 ;  
    for(i = 0 ; i < 6 ; ++ i)
        qDes[qdTail ++ ] = setCurson(des , i);  qDes[qdTail++ ] = -1;
    HashMap.init(); 
    do{
       step ++ ; 
       while(qsHead < qsTail){
              now = qSrc[qsHead ++ ] ; 
              if(now == -1){
                      qSrc[qsTail++]=-1;
                      break ;
              }
              for(i = 0 ; i < 6 ; ++ i){
                   next = getNext(now , i);
                   if(next == now ) continue ;
                   if(HashMap.find(next , 1)){
                        return step ;
                   }else{ 
                        HashMap.insert(next , 0);
                        qSrc[qsTail++] = next ;
                   }
              }
       }
       step++ ; 
       while(qdHead < qdTail){
             now = qDes[qdHead ++ ] ;
             if(now == -1) {
                    qDes[qdTail++]=-1 ; 
                    break ;
             }
             for(i = 0 ; i < 6 ; ++ i){
                   next = getNext(now , i);
                   if(next == now) break ;
                   if(HashMap.find(next , 0)){
                        return step ;
                   }else{
                        HashMap.insert(next , 1);
                        qDes[qdTail++] = next ;
                   }
             }
       }
    }while(1);
}
int main(){
    /*
    * int now = encode("123456");
    * for(int i = 0 ; i < 6 ; ++ i)
    * decode(getNext(now , i)); 
    */
    
    char start[8] , end[8] ; 
    while(cin>>start>>end){
         int res = bfs(encode(start) , encode(end));
         cout << res << endl ;
    }
    //system("pause");
    return 0 ;
}
