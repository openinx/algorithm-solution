#include<iostream>
using namespace std ;
const  int  maxn = 20010  ;
const  int  maxe = 500000;
const  int  INF  = 1<<29  ;


struct node{
       int x ,y , c ,next ;
};
node e[maxe] ;
int  es , hd[maxn] , S , T , N;

void ins(int x , int y ,int c){
     e[es].x = x , e[es].y = y ,e[es].c = c ,e[es].next = hd[x] , hd[x] = es ++ ;
     e[es].x = y , e[es].y = x, e[es].c = 0 ,e[es].next = hd[y] , hd[y] = es ++ ;
}

int cur[maxn] , dep[maxn] , ps[maxn] ;
int dinic(){
    int i ,j ,k ,top , tr ,f ,r  ,u , v ,maxf = 0 ;
    while(1){
            memset(dep ,-1,sizeof(dep)); dep[S] = 0 ;  
            f = r = 0 ;  ps[r++] = S ;
            while(f!=r){
                    v = ps[f++] ;
                    for(i = hd[v] ; i!=-1 ; i=e[i].next)
                         if(e[i].c && dep[u = e[i].y] == -1 ) 
                         dep[u] = dep[v] + 1 , ps[r++] = u ;
                    if(dep[T]!=-1) break;
            }
            if(dep[T]==-1) break ;
            i = S , top = 0 ;  memcpy(cur ,hd,sizeof(hd));
            while(1){
                    if(i == T){
                          for(tr = INF , k = 0 ; k<top ; ++k)
                             if(tr > e[ps[k]].c ) tr = e[ps[f = k]].c ;
                          for(k = 0 ; k <top ; ++k)
                             e[ps[k]].c -= tr ,e[ps[k]^1].c += tr ;
                          maxf += tr , i = e[ps[top = f]].x ; 
                    }
                    for(j = cur[i] ;j!=-1 ; j=cur[i]=e[j].next)
                      if(e[j].c && dep[e[j].y]==dep[i]+1) break;
                    if(j!=-1){
                       ps[top++] = j ; i = e[j].y ;
                    }else{
                       if(0==top) break;
                       dep[i] = -1 ; i = e[ps[--top]].x ;
                    }
            }
    }
    return maxf ;
}

int main(){
    int n , job , cnt , k , i , j , v; 
    while(scanf("%d" ,&n)!=EOF){
           es = 0 ; memset(hd ,-1,sizeof(hd)); 
           S = 2*n ; T = 2*n+1 ; N = T ;
           for(k = 0 ; k < n ; ++k){
                 scanf("%d: (%d)" , &job , &cnt);
                 for(i = 0 ; i < cnt ;++i){
                          scanf("%d" ,&v); 
                          ins(job , v , 1 );
                 }
           }
           for(i = 0 ; i<n ; ++i)  ins(S ,i , 1),ins(n+i , T , 1);
           printf("%d\n" ,dinic());
    }
    return 0 ; 
}
