#include<iostream>
using namespace std ;

const  int  maxV = 210 ; 
const  int  maxE = maxV*maxV ;
const  int  INF  = 2000000000 ;

struct node{
       int x , y , c , next  ;
};

node e[maxE] ; 
int  es , hd[maxV] ;

int  Matrix[maxV][maxV] , Vcnt , Ecnt , S , T , N;
int  in[maxV] , out[maxV];

void ins(int x ,int y ,int c){
     e[es].x = x , e[es].y = y ,e[es].c = c , e[es].next = hd[x]  , hd[x] = es ++ ;
     e[es].x = y , e[es].y = x ,e[es].c = 0 , e[es].next = hd[y]  , hd[y] = es ++ ;
}

int MaxFlow(){
    int dep[maxV] , ps[maxV] , cur[maxV] ;
    int tr , f , r , i , j , k , x , y ,top , maxf = 0 ; 
    while(1){
          memset(dep , -1 ,sizeof(dep));
          dep[S] = 0 ;  f = r = 0 ;  ps[r++] = S ;
          while(f!=r){
                 x = ps[f++] ; 
                 for(i = hd[x] ; i!=-1 ; i=e[i].next)
                     if(e[i].c && dep[y = e[i].y] == -1){
                          dep[y] = dep[x] + 1 ;  ps[r++] = y ;
                     } 
                 if(dep[T]!=-1)  break ;
          }
          if(dep[T]==-1) break ;
          
          i = S , top = 0 ;  memcpy(cur ,hd , sizeof(hd));
          while(1){
                if(i == T){
                       for(tr = INF , k = 0 ; k < top ; ++ k)
                           if(e[ps[k]].c < tr )  tr = e[ps[f=k]].c  ; 
                       for(k = 0 ; k < top ; ++k)
                           e[ps[k]].c -= tr , e[ps[k]^1].c += tr ;
                       maxf += tr ,   i = e[ps[top = f]].x ;  
                }
                for(j = cur[i] ; j!=-1 ; j = cur[i] = e[j].next)
                   if(e[j].c && dep[e[j].y] == dep[i] + 1) break ;
                if(j !=-1){
                     ps[top++] = j ;  i = e[j].y ;
                }else{
                     if(top == 0)  break ;
                     dep[i] = -1 ;  i = e[ps[--top]].x ;
                }
          }
    }
    return maxf ;
}


int vis[maxV] ;

void dfs(int x){
     int i , y ;
     vis[x] = 1 ; 
     for(i = hd[x] ; i!=-1 ; i=e[i].next){
           y = e[i].y ; 
           if(!vis[y] && e[i].c ){
               dfs(y);
           }
     }
}

void work(){
     int cnt , i ;
     memset(vis , 0  , sizeof(vis));
     printf("%d\n" , MaxFlow());
     
     dfs(S);
     
     cnt = 0 ;
     for(i = 1; i <=Vcnt ; ++i){
          if(!vis[i]) ++ cnt ;
          if(vis[Vcnt+i]) ++ cnt;
     }
     
     printf("%d\n" , cnt);
     
     for(i = 1 ; i <= Vcnt ; ++ i){
         if(vis[Vcnt+i])  printf("%d +\n" , i);
         if(!vis[i])      printf("%d -\n" , i);
     }
}

int main(){
    int i , j , x , y , w;
    scanf("%d%d" , &Vcnt , &Ecnt);   
    
    es = 0 ;   
    memset(hd , -1 ,sizeof(hd));
    N = 2*Vcnt + 2 ;
    S = 2*Vcnt + 1 ;   
    T = 2*Vcnt + 2 ;
    
    for(i = 1 ; i <= Vcnt ; ++ i) {  
          scanf("%d" , &w);
          ins(i + Vcnt , T , w);
    }
    for(i = 1 ; i <= Vcnt ; ++ i){
          scanf("%d" , &w);
          ins(S , i , w);
    }

    for(i = 0 ; i < Ecnt ; ++ i){
           scanf("%d%d" , &x , &y);
           ins(x , y + Vcnt, INF);
    }

    work();
    
    //while(getchar());
    return 0;
        
}
