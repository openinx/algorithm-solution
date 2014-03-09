#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

const int maxn = 10005 ;
typedef __int64 lld ; 

class SegmentTree{
      public :
          void build(lld x ,lld l , lld r){
             t[x].l = l , t[x].r = r , t[x].sum = t[x].max_prefix = 0 ;
             if(l != r){
                  lld mid = (l+r)>>1 ;
                  build(L(x) , l , mid ) ;
                  build(R(x) , mid+1,r );
             }
          }
          void update(lld x , lld index , lld value ){
               if(t[x].l == t[x].r ){
                   t[x].sum += value ; t[x].max_prefix = t[x].sum  ;
               }else{
                   lld mid=(t[x].l + t[x].r)>>1 ;
                   if(index <= mid)
                        update(L(x) , index , value);
                   else 
                        update(R(x) , index , value) ;
                   t[x].sum = t[L(x)].sum + t[R(x)].sum ; 
                   t[x].max_prefix = max(t[L(x)].max_prefix , t[L(x)].sum + t[R(x)].max_prefix ) ; 
               }
          }
          lld query(){ return t[1].max_prefix ;  }
      private : 
          struct node{
              lld l , r , sum , max_prefix  ; 
          }t[8*maxn];
          lld L(lld x) { return x<<1; }
          lld R(lld x) { return (x<<1)|1; }
}stree ;

struct star{
     lld x , y , w ; 
     bool operator < (const star & that)const{
          return x < that.x ; 
     }
}s[ maxn ];

map<lld ,lld> my ; 
lld idx , posy[2*maxn] ; 

int main(){
    lld n , w , h , i , cur , ans ; 
    while( scanf("%I64d%I64d%I64d" ,&n , &w ,&h) !=EOF ){
        my.clear() ; 
        for(i = 0 ; i < n ; ++ i){
             scanf("%I64d%I64d%I64d" , &s[i].x , &s[i].y , &s[i].w) ;
             my[ s[i].y ] = my[ s[i].y+h ] = 1 ;    
        }
        idx = 0 ; 
        for(map<lld ,lld>::iterator it = my.begin() ; it!=my.end() ; it++)
           my[ it->first ] = ++idx ;
        sort(s , s + n ) ; 
        stree.build(1 , 1 , idx ) ;
        cur = ans = 0 ; 
        for(i = 0 ; i < n ; ++ i){
            for(; cur < n ; ++ cur)
              if(s[cur].x - s[i].x < w ){
                   stree.update(1 , my[s[cur].y] , s[cur].w) ;
                   stree.update(1 , my[s[cur].y+h] , -s[cur].w ) ;
                   ans = max(ans , stree.query() ) ; 
                   //cout << "answer :" << ans << endl ;
              }else break ;
            stree.update(1 , my[s[i].y] , -s[i].w );
            stree.update(1 , my[s[i].y+h] , s[i].w) ; 
        }
        printf("%I64d\n" , ans);
    }
    //system("pause");
    return 0 ;
}
