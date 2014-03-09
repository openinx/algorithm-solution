#include<iostream>
using namespace std ;

const  int maxn = 110 ; 
const  int maxe = 1005 * 5;
const  double DOUBLE_INF = 1e300 ;
const  double EPS0 = 1e-5 ;
const  double EPS = 1e-18 ;

int n ,m , st[maxe] , ed[maxe] ,dgr[maxn];

struct node{
       int x , y , next ;
       double c ;
};

node e[maxe] ;
int  es ,hd[maxn] , S , T ;

inline int sgn(double x){
       return (x>EPS0)-(x<-EPS0) ;
}

void ins(int x ,int y ,double c){
     e[es].x = x ,e[es].y = y ,e[es].c = c , e[es].next = hd[x] , hd[x] = es ++ ;
     e[es].x = y ,e[es].y = x ,e[es].c = 0 , e[es].next = hd[y] , hd[y] = es ++ ;
}

int dep[maxn] , ps[maxn] , cur[maxn] ;

double MaxFlow(){
     int i ,j , k , x ,y , top , f , r ; 
     double tr , maxf = 0.0 ;
     while(1){
            memset(dep , -1 ,sizeof(dep)); dep[S] = 0 ; f = r = 0 ; ps[r++] = S ;
            while( f!=r && dep[T] == -1){
                    for(i = hd[x = ps[f++]] ; i!=-1 ; i=e[i].next)
                        if(e[i].c > EPS && dep[y = e[i].y] == -1) 
                             ps[r++] = y ,  dep[y] = dep[x] + 1 ;
            }
            if(dep[T]==-1) break;
            i = S , top = 0 ;  memcpy(cur , hd ,sizeof(hd));
            while(1){
                    if(i == T){
                        for(tr = DOUBLE_INF , k = 0 ; k < top ; ++ k)
                            if(e[ps[k]].c < tr )  tr = e[ps[f=k]].c ;
                        for(k = 0 ; k < top  ; ++ k)
                            e[ps[k]].c -= tr , e[ps[k]^1].c +=tr ;
                        maxf += tr ,  i = e[ps[top=f]].x ; 
                    }
                    for(j = cur[i] ; j!=-1 ; j=cur[i]=e[j].next)
                       if(e[j].c > EPS && dep[e[j].y] == dep[i] + 1) break ;
                    if(j!=-1){
                       ps[top++] = j ; i = e[j].y ;
                    }else{
                       if(0==top) break ;
                       dep[i] = -1 , i = e[ps[--top]].x ;
                    }
            }
     }
     return maxf ;

}

double calc(double mid){
       int i ;  
       double sol ;
       es = 0 ; memset(hd , -1 ,sizeof(hd));  S = n + 1 ; T = n + 2 ;
       for(i = 1 ; i <= m ; ++i) {
           ins(st[i] ,ed[i] , 1.0);
           ins(ed[i] ,st[i] , 1.0);
       }
       for(i = 1 ; i <= n ;++i){
           ins(S , i , m);
           ins(i , T , m + 2*mid - dgr[i]);
       }
       return (m*n-MaxFlow())/2.0 ;
}

int vis[maxn] ;

void dfs(int x){
     int i , y ; 
     vis[x] = 1 ;
     for(i = hd[x] ; i!=-1 ; i=e[i].next)
        if(e[i].c > EPS && !vis[y=e[i].y] )  
             dfs(y);
}

void work(){
     int i  , cnt ;
     double sol , l = 0 , r = m , mid ;
     while(sgn(l-r)){
           mid = (l + r)/2.0 ; 
           sol = calc(mid);
           if(sgn(sol) == 1){
                l = mid ;
           }else{
                r = mid ;
           }
     }
     
     //cout<<"Answer : " << l << endl ;
     
     calc(l);
     memset(vis , 0 ,sizeof(vis));   dfs(S) ;  
     cnt = 0 ; 
     for(i = 1 ; i <= n; ++i) 
         if(vis[i])  
             ++ cnt ; 
     printf("%d\n" , cnt);
     for(i = 1 ; i <= n ;++i)
         if(vis[i]) 
             printf("%d\n" , i);
}

int main(){
    int i ;
    while(scanf("%d%d" ,&n ,&m)!=EOF){
          memset(dgr , 0 , sizeof(dgr));
          for(i = 1 ; i<= m ;++i) { 
                scanf("%d%d" ,&st[i] ,&ed[i]);
                dgr[st[i]] ++ ; dgr[ed[i]] ++ ;
          }
          if(m == 0){
               printf("1\n1\n");
          }else{
               work();
          }
    } 
    return 0 ;
}




