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

const  int MAXN = 100005  ;
const  double INF = 1e20 ; 
const  double EPS = 1e-6  ; 

struct point{
     double x , y ; 
};

int n ;
point p[MAXN] ;

double calc(double r){
      double maxh = 0.0 ; 
      for(int i = 0 ; i < n ;++ i){
           maxh = max(maxh , r*p[i].y/(r - p[i].x));
      }
      return maxh ;
}

int main(){
    int acase , i ; 
    double x , y , z , lo , hi , x1 , x2 , fx1 ,fx2 , y1 , y2;
    //cin >> acase ;
    //while(acase -- ){
    while(scanf("%d" , &n)!=EOF) 
    {
         lo = 0 ; 
         for(i = 0 ; i < n ; ++ i){ 
            scanf("%lf%lf%lf" , &x , &y , &z );
            p[i].x = sqrt(x*x + y * y);  
            p[i].y = z ; 
            lo = max(lo , p[i].x );
         }
         hi = INF ; lo += EPS ; 
         while(lo + EPS < hi){
              x1 = lo + (hi - lo) / 3.0 ; 
              x2 = x1 + (hi - lo) / 3.0 ; 
              y1 = calc(x1);  fx1 = x1*x1*y1 ;
              y2 = calc(x2);  fx2 = x2*x2*y2 ; 
              if(fx1 < fx2 ){
                  hi = x2 ; 
              }else{
                  lo = x1 ; 
              }
         }
         printf("%0.3lf %0.3lf\n" , calc(lo) , lo );
    }
    //system("pause");
    return 0 ;
}
