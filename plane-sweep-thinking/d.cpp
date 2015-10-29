#include<iostream>
#include<set>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn = 50005 ;
const double EPS = 1e-8 ;

using namespace std ;

struct circle{
    int x ,y , r ;
};

int circle_size , xCut ; 
circle c[maxn] ;


struct event{
     int id , type , w ;
};

bool operator < (event a ,event b){
     if(a.w != b.w )  return a.w < b.w ;
     if(a.type != b.type )  return a.type < b.type ; 
     if(a.id != b.id )  return a.id < b.id ;
}

inline double square(double x){
       return x*x ;
}

inline int sgn(double x){
       return  (x>EPS)-(x<-EPS);
}

struct Point{
     int id , type ;
     Point(){}
     Point(int _id ,int _type){
         id = _id , type = _type ;
     }
     double yPos(){
         double distance = square(c[id].r) - square(xCut-c[id].x);
         return c[id].y + type * sqrt(distance);      
     }
};

bool operator < (Point a , Point b){
     double tmp = a.yPos() - b.yPos() ; 
     if(sgn(tmp) != 0 )  return sgn(tmp) < 0 ;
     if(a.id != b.id) return a.id < b.id ;
     return a.type < b.type ;
}

int fa[maxn] , dp[maxn];
event  e[maxn*2];
set<Point>bst ;

int getDepth(int x){
    if(dp[x] != -1) return dp[x] ;
    dp[x] = 1 + getDepth(fa[x]);
    return dp[x] ;
}

int main(){
    int i , current ;
    set<Point>::iterator it ; 
    while(scanf("%d" ,&circle_size)!=EOF){
          bst.clear();
          for(i=0 ; i<circle_size ;++i){
              scanf("%d%d%d" ,&c[i].x ,&c[i].y ,&c[i].r);  fa[i] = -1 ; 
          }
          for(i = 0 ; i < circle_size ;++ i){
              e[i].id = i , e[i].type = 1 , e[i].w = c[i].x + c[i].r ;
              e[i+circle_size].id = i ; e[i+circle_size].type = -1 ; e[i+circle_size].w =c[i].x - c[i].r ; 
          }
          sort(e , e+2*circle_size);
          
          for(i = 0 ; i < 2*circle_size ; ++ i){
                 xCut = c[e[i].id].x ;  current = e[i].id ; 
                 if(e[i].type == +1){
                       bst.erase(Point(current , +1));  
                       bst.erase(Point(current , -1));
                 }else{
                       bst.insert(Point(current, +1));  
                       it = bst.insert(Point(current, -1)).first ;
                       if(it == bst.begin()){
                             fa[current] = circle_size ;
                       }else{
                           it -- ;
                           if(it->type == -1){
                                fa[current] = it->id ;
                           }else{
                                fa[current] = fa[it->id] ;
                           }
                       }
                 }
          }         
          memset(dp , -1 ,sizeof(dp));  dp[circle_size] = 0 ;
          int ans = 0 ; 
          for(i = 0 ; i < circle_size ; ++ i)
               ans = max(ans , getDepth(i));
          printf("%d\n" , ans);
    }
   // system("pause");
    return 0 ;
}
