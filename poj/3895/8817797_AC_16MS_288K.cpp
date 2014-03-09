#include<iostream>
using namespace std ;
const int  maxn = 5000 ;
const int  maxe = 10 * maxn ;

struct node{
       int y ,next ;
};
node e[maxe] ;
int  es , hd[maxn] , N ,E ;
int  dep[maxn] , ans ;

void dfs(int x){
     int i , y ;
     for(i = hd[x] ; i!=-1 ; i=e[i].next){
          y = e[i].y ;
          if(dep[y]==-1){
             dep[y] = dep[x] + 1 ;  dfs(y);
          }else{
             ans = max(ans , dep[x]-dep[y]+1);
          }
     }
}

int main(){
    int tst , i , x, y ;
    scanf("%d",&tst);
    while(tst--){
           scanf("%d%d",&N,&E);
           es = 0 ;  memset(hd,-1,sizeof(hd));
           for(i = 0 ; i<E ; ++i){
                  scanf("%d%d",&x,&y); 
                  e[es].y = y , e[es].next = hd[x] , hd[x] = es ++ ;
                  e[es].y = x , e[es].next = hd[y] , hd[y] = es ++ ;
           }
           ans = 0 ;  memset(dep , -1 ,sizeof(dep));
           for(i = 1 ; i<=N ;++i) 
             if(dep[i]==-1){
                 dep[i] = 0 ; dfs(i);
             }
           printf("%d\n" , ans <= 2 ? 0 : ans);
    }
    return 0 ;
}

