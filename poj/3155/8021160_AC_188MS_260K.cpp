#include<iostream>
using namespace std ; 

typedef __int64  lld ;
const int maxn = 110 ;
const int maxe = 5000 ;
const double EPS = 1e-5 ;
const double MULTIPLE = 1000000000 ;
const lld    LLD_INF = (lld)1<<60  ;

int n , m , st[1005] , ed[1005] , vis[maxn] , dgr[maxn] ;

struct node{
       int x , y , next ;
       lld  c ;
};

node e[maxe] ; 
int  es , hd[maxn] , S , T ; 

void ins(int x , int y , double c){
     e[es].x = x ,e[es].y = y ,e[es].c = (lld)(c*MULTIPLE) , e[es].next = hd[x] , hd[x] = es ++ ;
     e[es].x = y ,e[es].y = x ,e[es].c = 0 , e[es].next = hd[y] , hd[y] = es ++ ;
}

int dep[maxn] , ps[maxn] , cur[maxn] ;

double MaxFlow(){
       int i , j , k , x ,y , top , f, r ;
       lld tr , maxf = 0 ;
       while(1){
              memset(dep , -1 ,sizeof(dep)); dep[S] = 0 ; f = r = 0 ; ps[r++] = S ;
              while(f!=r && dep[T]==-1){
                   for(i = hd[x = ps[f++]] ; i!=-1 ; i=e[i].next)
                     if(e[i].c && dep[y = e[i].y] == -1)  ps[r++] = y , dep[y] = dep[x] + 1 ;
              }
              if(dep[T] == -1) break ;
              i = S , top = 0 ; memcpy(cur , hd ,sizeof(hd));
              while(1){
                    if(i == T){
                         for(tr = LLD_INF , k = 0 ; k < top ; ++ k)
                            if(e[ps[k]].c < tr )  tr = e[ps[f=k]].c ;
                         for(k = 0 ; k < top ; ++ k)
                            e[ps[k]].c  -= tr , e[ps[k]^1].c +=tr ;
                         maxf += tr , i = e[ps[top=f]].x ;
                    }
                    for(j = cur[i] ;j!=-1 ; j=cur[i]=e[j].next)
                       if(e[j].c && dep[e[j].y] == dep[i] + 1) break ;
                    if(j!=-1){
                       ps[top++] = j ; i =e[j].y ;
                    }else{
                       if(top==0) break ;
                       dep[i]=-1 ; i =e[ps[--top]].x ;
                    }
              }
       }
       return  double(maxf)/MULTIPLE ;
}

double calc(double g){
     int i , j ; 
     es = 0 ;  memset(hd , -1 ,sizeof(hd)) ;  S = n + 1 ; T = n + 2 ;
     for(i = 1 ; i <= m ; ++i){
           ins(st[i] , ed[i] , 1.0);
           ins(ed[i] , st[i] , 1.0);
     }
     for(i = 1 ; i <= n ; ++i){
           ins(S , i , m);
           ins(i , T , m + 2*g - dgr[i]);
     }
     return (m*n - MaxFlow())/2.0 ;
}

void dfs(int x){
     int i ,y ;
     vis[x] = 1 ; 
     for(i = hd[x] ; i!=-1 ; i=e[i].next)
        if(e[i].c && !vis[y=e[i].y])
            dfs(y);
}

void work(){
     double sol , l = 0 , r = m , mid ;    
     while(l + EPS < r){
            mid = (l + r) /2.0 ;
            if(calc(mid) > EPS)
                 l = mid ;
            else 
                 r = mid ;
     }
     calc(l);
     
     //cout<<"Answer : "<< l <<endl;
     
     memset(vis , 0 ,sizeof(vis)); dfs(S);
     int  cnt = 0 , i ;
     for(i = 1 ; i<= n ; ++i)  
         if(vis[i]) 
             ++ cnt;
     printf("%d\n" , cnt);
     for(i = 1 ; i<= n ; ++i)  
         if(vis[i]) 
             printf("%d\n",i);
}

int main(){
    int i , j ;
    while(scanf("%d%d" ,&n , &m)!=EOF){
            memset(dgr , 0 ,sizeof(dgr));
            for(i = 1 ; i <= m ; ++i){
                  scanf("%d%d" , &st[i] , &ed[i]);
                  dgr[st[i]] ++ ;  dgr[ed[i]] ++ ;
            }
            if(m==0){
                  printf("1\n1\n");
            }else{
                  work();
            }
    }
    return 0 ;
}
