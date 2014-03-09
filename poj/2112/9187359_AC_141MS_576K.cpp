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

const int MAXK = 31  ; 
const int MAXC = 201 ; 
const int MAXM = 16  ; 
const int maxn = MAXK + MAXC  ; 
const int maxe = maxn * maxn  ; 
const int INF  = 1000000000   ; 

int K , C , M , N , a[MAXK+MAXC][MAXK+MAXC] ; 

struct node
{   
    int x , y , c , next ;
} ; 

struct network
{   
     int S , T , N , es , hd[maxn] ; 
     node e[maxe] ; 
     int ps[maxn] , cur[maxn] , dep[maxn] ;
     void init(int vS , int vT ,int vN) ;
     void ins(int x,int y ,int c) ; 
     int dinic() ; 
} ; 

void network::init(int vS ,int vT ,int vN)
{ 
     S = vS , T = vT , N = vN ; 
     es = 0 ; memset(hd , -1 ,sizeof(hd));
}

void network::ins(int x,int y ,int c)
{   
     e[es].x = x , e[es].y = y , e[es].c = c, e[es].next = hd[x] , hd[x] = es ++ ; 
     e[es].x = y , e[es].y = x , e[es].c = 0, e[es].next = hd[y] , hd[y] = es ++ ;
}

int network::dinic()
{ 
     int u , v , f , r , i ,j, k ,  tr , top , maxf = 0  ; 
     while(1)
     { 
           f = r = 0 ; memset(dep , -1 ,sizeof(dep));
           ps[r++] = S , dep[S] = 0 ; 
           while(f != r )
           { 
               v = ps[f++] ; 
               for(i = hd[v] ; i !=-1 ; i = e[i].next){
                   u = e[i].y ; 
                   if(e[i].c && dep[u]==-1 ) 
                     dep[u] = dep[v] + 1 , ps[r++] = u ;
               }
               if(dep[T]!=-1) break;
           }       
           if(dep[T]==-1) break ;
           
           i = S , top = 0 ;  memcpy(cur,hd,sizeof(hd));
           while(1)
           {
                if(i == T)
                {
                    for(k = 0 , tr = INF ; k < top ; ++ k)
                        if( tr > e[ps[k]].c )  tr = e[ps[k]].c , f = k ;
                    for(k = 0 ; k < top ;  ++k)
                        e[ps[k]].c -= tr , e[ps[k]^1].c += tr  ; 
                    maxf += tr , i = e[ps[top = f]].x ;  
                }  
                for(j = cur[i] ; j!=-1 ; j = cur[i] = e[j].next)
                   if(e[j].c && dep[e[j].y] == dep[i] + 1) break; 
                if(j!=-1)
                     ps[top++] = j ,  i = e[j].y ;
                else
                { 
                     if( 0 == top ) break ;    //  The only end for while(1);
                     dep[i]=-1 , i = e[ps[--top]].x ;
                } 
           }
     }
     return maxf ;
}
network g ; 

bool isOK(int mid ){
     int i , j ;
     g.init(0 , K+C+1 , K+C) ;  
     for(i = K + 1 ; i <= K+C ; ++ i)  g.ins(0 , i , 1 ) ; 
     for(i = 1 ; i <= K ; ++ i)  g.ins(i , K+C+1 , M ) ;
     for(i = K + 1 ; i <= K+C ; ++ i)
        for(j = 1 ; j <= K ; ++ j)
            if(a[i][j] <= mid )
                g.ins(i , j , 1 );
     return g.dinic()==C ; 
}

int main(){
    int i , j ,k ,t , l , r , ans , mid ;
    scanf("%d%d%d" , &K , &C , &M);
    N = K + C ; 
    for(i = 1 ; i <= N ; ++ i)
     for(j = 1 ; j <= N ; ++ j){
         scanf("%d" , &t);
         a[i][j] = t==0 ? INF:t ; 
     }
    for(k = 1 ; k <= N ; ++ k)
        for(i = 1 ; i <= N ; ++ i)
          for(j = 1 ; j <=N ; ++ j)
             a[i][j] = min(a[i][j] , a[i][k] + a[k][j]);
    l = 0 ; r = 50000 ; 
    while(l <= r){
        mid = (l + r)>>1 ; 
        if(isOK(mid)){
              ans = mid ;  r = mid - 1 ;
        }else{
              l = mid + 1 ;
        }
    }
    printf("%d\n" , ans);
    //system("pause");
    return 0 ;
}
