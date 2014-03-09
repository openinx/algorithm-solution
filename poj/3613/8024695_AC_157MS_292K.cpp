#include<iostream>
#include<set>
using namespace std ;

const  int INF = 1000000100 ;
const  int maxn = 101 ;

set<int> win ;
set<int>::iterator it ;
int Vcnt , Ecnt , S , T;
int st[maxn] , ed[maxn] , length[maxn] , pos[maxn] , N ;
int G[maxn][maxn] , Matrix[maxn][maxn] , a[maxn][maxn];
//int dist[maxn];

int  bbs(int x){
     int l = 0 ,  r = N - 1 , mid ; 
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

int work(){
    int i , j , k , exp = Vcnt , ans; 
    //for(i = 0 ; i < N ; ++ i)  dist[i] = G[S][i];
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
           exp = exp >> 1 ; 
           for(i = 0 ; i < N ; ++ i)
              for(j = 0 ; j < N ; ++ j){
                     a[i][j] = INF ;
                     for(k = 0 ; k < N ;++ k)
                        a[i][j] = min(a[i][j] , G[i][k] + G[k][j]);
              }
           for(i = 0 ; i < N ; ++ i)  for(j = 0 ; j < N ; ++ j)  G[i][j] = a[i][j] ;
    }
    //ans = INF ;
    //for(k = 0 ; k < N ; ++ k) 
        //ans = min(ans , dist[k] + Matrix[k][T] );
    return Matrix[S][T] ;
}

int main(){
    int i , j , x ,y ,ans;
    
    win.clear();
    scanf("%d%d%d%d" , &Vcnt , &Ecnt , &S , &T);
    for(i = 0 ; i < Ecnt ; ++ i){
           scanf("%d%d%d" ,&length[i] , &st[i] , &ed[i]);
           win.insert(st[i]);
           win.insert(ed[i]);
    }
    
    for(it = win.begin() , N = 0 ; it!=win.end() ; it++) 
          pos[N++] = *it ;

    for(i = 0 ; i < N ; ++i) for(j = 0 ; j < N ; ++ j) G[i][j] = INF ;
    
    S = bbs(S) ;  T = bbs(T); 
    
    for(i = 0 ; i < Ecnt ; ++ i){
          x = bbs(st[i]) , y =bbs(ed[i]) ;
          G[x][y] = G[y][x] = length[i] ;
    }
    
    ans = work();
    printf("%d\n" , ans);
    
    return 0 ;
}
