#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std ;
const int maxn = 800000 ; 

struct type{
       int id , value ; 
       type(){}
       type(int _id , int _value){
           id = _id ;  value = _value ; 
       }
};

struct node{
      int l , r , s ;
      type v ; 
};

struct SBT{
      
      int ts , root , tot  ;
      node t[maxn] ; 
      
      void init(){
           root = ts = tot = t[0].l = t[0].r = t[0].s = 0 ; 
      }
      
      void zig(int &x){
           int y = t[x].l ;  if(x==0||y==0) return ;
           t[x].l = t[y].r ;  t[y].r = x ; 
           t[y].s = t[x].s ;  t[x].s = t[t[x].l].s + t[t[x].r].s + 1; 
           x = y ; 
      }
      
      void zag(int &x){
           int y = t[x].r ;  if(x==0||y==0) return ;
           t[x].r = t[y].l ;  t[y].l = x ; 
           t[y].s = t[x].s ;  t[x].s = t[t[x].l].s + t[t[x].r].s + 1;
           x = y ;
      }
      
      void maintain(int &x , int flag){
           if(flag){
                  if(t[t[t[x].l].l].s > t[t[x].r].s){
                         zig(x);
                  }else if(t[t[t[x].l].r].s > t[t[x].r].s){
                         zag(t[x].l) ; zig(x);
                  }else return ;
           }else{
                  if(t[t[t[x].r].r].s > t[t[x].l].s ){
                         zag(x);
                  }else if(t[t[t[x].r].l].s > t[t[x].l].s){
                         zig(t[x].r);  zag(x);
                  }else return  ;
           }
           maintain(t[x].l , true);  maintain(t[x].r , false );
           maintain(x , true );      maintain(x , false ) ;
      }
      
      void Insert(int &x , type v ){
           if(x == 0 ){
              x = ++ts ; t[x].l = t[x].r = 0 ; t[x].s = 1 ; t[x].v = v ;
           }else{
              t[x].s ++ ;
              if(v.value <= t[x].v.value){
                     Insert(t[x].l , v );  maintain(x , true);
              }else {
                     Insert(t[x].r , v );  maintain(x , false);
              }
           }
      }
      
      type Delete(int &x , type v){
           if(x == 0 )  return type(0 ,-1);
           -- t[x].s ;
           if((t[x].l==0&&(v.value<t[x].v.value))||(t[x].r==0&&(v.value>t[x].v.value))||(v.value==t[x].v.value)){
                 type temp = t[x].v ; 
                 if(t[x].l ==0 || t[x].r == 0 ){
                      x = t[x].l + t[x].r ; 
                 }else{
                      t[x].v = Delete(t[x].l , type(0 , v.value+1));
                 }
                 return temp ;
           }else{
               if(v.value < t[x].v.value )  return Delete(t[x].l , v ) ;
               if(v.value > t[x].v.value )  return Delete(t[x].r , v );
           }
      }
      
      type select(int x , int k ){
          int r = t[t[x].l].s + 1 ;
          if(k == r)  return t[x].v ; 
          if(k <  r)  return select(t[x].l , k);
          if(k >  r)  return select(t[x].r , k-r);
      }
      
      void ins(type v){ tot++ ; Insert(root , v );}
      void del(type v){ tot-- ; Delete(root , v );}
      
      type getmin(){
            return select(root , 1 );
      }
      
      type getmax(){
            return select(root ,tot) ;
      }
      /*
      void dfs(int x ){
           if(x!=0){
               dfs(t[x].l );
               printf(" %d" , t[x].v);
               dfs(t[x].r );
           }
      }
      
      void test(){
           printf("The element is : ");   
           dfs(root);
           printf("\n");
      }*/
};

SBT sbt ;

int main(){
    int cmd , id ,value ;
    type e ;  
    sbt.init() ;
    while(scanf("%d" , &cmd)!=EOF){
         if(cmd == 0){
              break ; 
         }else if(cmd == 1){
              scanf("%d%d" ,&id , &value); 
              e = type(id , value) ;
              sbt.ins(e) ;       
         }else if(cmd == 2){
              if(sbt.tot == 0 )  { printf("0\n"); continue ; }
              e = sbt.getmax() ;  sbt.del(e);
              printf("%d\n" , e.id);
         }else if(cmd == 3){
              if(sbt.tot == 0 )  { printf("0\n"); continue ; }
              e = sbt.getmin() ;  sbt.del(e);
              printf("%d\n" , e.id);
         }
    } 
    //system("pause");
    return 0 ; 
}




