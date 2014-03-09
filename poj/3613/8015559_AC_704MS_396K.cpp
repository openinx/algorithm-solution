#include<iostream>
#include<set>
using namespace std ;

typedef __int64 lld ;
const  lld INF = 2100000000 ;
const  lld maxn = 101 ;

set<lld> win ;
set<lld>::iterator it ;
lld Vcnt , Ecnt , S , T;
lld st[maxn] , ed[maxn] , length[maxn] , pos[maxn] , N ;
lld G[maxn][maxn] , Matrix[maxn][maxn] , a[maxn][maxn];
lld dist[maxn];

lld  bbs(lld x){
     lld l = 0 ,  r = N - 1 , mid ; 
     while(l <= r){
          mid = (l + r) /2 ; 
          if(pos[mid] == x)  return mid ; 
          if(x < pos[mid]){
                r = mid - 1; 
          }else{
                l = mid + 1 ;
          }
     }
}

lld work(){
    lld i , j , k , exp = Vcnt - 1 , ans; 
    for(i = 0 ; i < N ; ++ i)  dist[i] = G[S][i];
    for(i = 0 ; i < N ; ++ i) for(j = 0 ; j < N ; ++ j)  Matrix[i][j] = INF ;
    for(i = 0 ; i < N ; ++ i)  Matrix[i][i] =  0 ;
    
    while(exp){
           if(exp & 1){
                for(i = 0 ; i < N ; ++ i)
                   for(j = 0 ; j < N ; ++ j){
                        a[i][j] = INF ;
                        for(k = 0 ; k < N ; ++ k)
                           a[i][j] = min(a[i][j] , Matrix[i][k] + G[k][j]); 
                   }
                for(i = 0 ; i < N ; ++ i)  for(j = 0 ; j < N ;++ j)  Matrix[i][j] = a[i][j] ;  
           }
           exp = exp / 2 ; 
           for(i = 0 ; i < N ; ++ i)
              for(j = 0 ; j < N ; ++ j){
                     a[i][j] = INF ;
                     for(k = 0 ; k < N ;++ k)
                        a[i][j] = min(a[i][j] , G[i][k] + G[k][j]);
              }
           for(i = 0 ; i < N ; ++ i)  for(j = 0 ; j < N ; ++ j)  G[i][j] = a[i][j] ;
    }
    ans = INF ;
    for(k = 0 ; k < N ; ++ k) 
        ans = min(ans , dist[k] + Matrix[k][T] );
    return ans ;
}

int main(){
    lld i , j , x ,y ,ans;
    win.clear();
    scanf("%I64d%I64d%I64d%I64d" , &Vcnt , &Ecnt , &S , &T);
    for(i = 0 ; i < Ecnt ; ++ i){
           scanf("%I64d%I64d%I64d" ,&length[i] , &st[i] , &ed[i]);
           win.insert(st[i]);
           win.insert(ed[i]);
    }
    
    // cout<<INF<<endl;
    
    for(it = win.begin() , N = 0 ; it!=win.end() ; it++) 
          pos[N++] = *it ;
    
    //cout<<"Vertex:"<<N<<endl;
    
    for(i = 0 ; i < N ; ++i)
        for(j = 0 ; j < N ; ++ j)
        G[i][j] = INF ;
    
    S = bbs(S) ;  T = bbs(T);  
    
    // cout<<"start : " << S << " end :" << T <<endl ;
    
    for(i = 0 ; i < Ecnt ; ++ i){
          x = bbs(st[i]) , y =bbs(ed[i]) ;
          
          // cout<<x<<" --- "<<y<<endl;
          
          G[x][y] = G[y][x] = length[i] ;
    }
    
    ans = work();
    
    printf("%I64d\n" , ans);

    //while(getchar());
    return 0 ;
}

