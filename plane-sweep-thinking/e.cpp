#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std ; 

const int maxn = 100005 ; 

int n ;

struct point{
       double x , y ; 
       point(){}
       point(double _x , double _y):x(_x),y(_y){}
       bool operator < (const point &that)const{
            return y < that.y ;
       }
       friend bool cmp(const point &a , const point &b){
            return a.x < b.x ;
       }
}p[maxn]; 

set<point> bst ; 
set<point>::iterator it ;

inline double sq(double x) { return x * x ; }

int main(){
    int i , left ;
    double d ; 
    while( scanf("%d" , &n)!=EOF && n){
           for(i = 0 ; i < n ; ++ i)
              scanf("%lf%lf" , &p[i].x, &p[i].y) ; 
           sort(p , p + n , cmp);
           
          // for(i = 0 ; i < n ; ++ i)
           //  cout << p[i].x << " " << p[i].y << endl ;
           bst.clear() ;
           bst.insert(p[0]) ;
           left = 0 ;
           d = 1e300 ; 
           for(i = 1 ; i < n ; ++ i){
                while(left < n && (p[i].x - p[left].x > d)) bst.erase(p[left++]) ;
                for(it = bst.lower_bound(point(p[i].x,p[i].y - d)); it!=bst.end() && (it->y - p[i].y < d) ; ++ it){
                    d = min(d , sqrt(sq(p[i].x-it->x) + sq(p[i].y-it->y)));
                }
                bst.insert(p[i]);
           }
           printf("%0.2f\n" , d/2.0);
    }
    //system("pause");
    return 0 ; 
}
