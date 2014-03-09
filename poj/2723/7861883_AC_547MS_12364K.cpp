#include<iostream>
#define MAXN ((1<<12)+3)
using namespace std;
int  key , door , Pair[MAXN] , lock[MAXN] , N;
bool gh[MAXN][MAXN] , instk[MAXN];

int bcnt ,idx ,top , dfn[MAXN] , low[MAXN],stk[MAXN] , bel[MAXN];

void Tarjan(int x){
     int i ,  y ;
     low[x] = dfn[x] = ++ idx ;
     instk[x] = 1 , stk[top ++ ] = x ;
     for(y = 0 ; y < N ; ++ y)
        if(gh[x][y]){
                if(dfn[y] == -1){
                   Tarjan(y) ; 
                   low[x] = min(low[x] , low[y]) ;
                }else if(instk[y]){
                   low[x] = min(low[x] , dfn[y]) ;
                }
        }
     if(low[x] == dfn[x]){
          ++ bcnt ;
          do{
             y = stk[--top] ; instk[y] = 0 ;  bel[y] = bcnt; 
          }while(y!=x);
     }
}

bool check(int MAX_DOOR){
     int i , j , k ;
     N = 2*MAX_DOOR ; 
     for(i = 0 ; i < N ; ++i) 
         for(j = 0 ; j < N ; ++j)
         gh[i][j] = 0 ; 
     for(i = 0 ; i < MAX_DOOR ; ++ i)
         for(j = i + 1; j < MAX_DOOR ; ++j){
               if(Pair[lock[2*i]]  == lock[2*j])    gh[2*i][2*j+1] = gh[2*j][2*i+1] = 1;
               if(Pair[lock[2*i]]  == lock[2*j+1])  gh[2*i][2*j] = gh[2*j+1][2*i+1] = 1;
               if(Pair[lock[2*i+1]] == lock[2*j])   gh[2*i+1][2*j+1]= gh[2*j][2*i]  = 1;
               if(Pair[lock[2*i+1]] == lock[2*j+1]) gh[2*i+1][2*j] = gh[2*j+1][2*i] = 1; 
         }
     bcnt = top = idx = 0 ; 
     for(i = 0 ; i < N ; ++ i)   instk[i] = 0 , dfn[i] = -1 ;
     for(i = 0 ; i < N ; ++ i)
         if(dfn[i] == -1)  Tarjan(i);
     for(i = 0 ; i < MAX_DOOR ; ++ i)
         if(bel[2*i] == bel[2*i+1])  return false;
     return true;
}

int main(){
    int i ,x , y , l , r , mid , ans;
    while(scanf("%d%d", &key,&door)!=EOF && (key+door)){
          for(i = 0 ; i<key ; ++i){
                 scanf("%d%d",&x,&y);
                 Pair[x] = y , Pair[y] = x ;
          }
          for(i = 0 ; i<2*door ;++i)   scanf("%d" , &lock[i]);
          ans = 1 , l = 1 , r = door ;
          while(l <= r){
                 mid = (l + r) / 2  ;
                 if(check(mid)){
                      ans = mid ;  l = mid + 1 ;
                 }else{
                      r  = mid - 1; 
                 }   
          }
          printf("%d\n" , ans);
    }
    return 0 ;
}
