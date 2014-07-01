#include<iostream>
#include<string.h>
using namespace std ;

const  int MAXN = 105 ; 

int N , M , K , route[MAXN] ;
int tx , ty , jx , jy;
int    vis0[MAXN][MAXN] , vis1[MAXN][MAXN]; 
int    dx[] = {1,0,-1,0} , dy[] = {0,1,0,-1} ;
char   bd[MAXN][MAXN]  ;

bool can(){
     //if(tx == jx && ty == jy)  return true ;
     memset(vis0 , 0 , sizeof(vis0));  vis0[tx][ty] = 1 ;
     for(int step = 0 ; step < K ; ++ step){
            jx += dx[route[step]] ;  jy += dy[route[step]] ;
            memset(vis1 , 0 , sizeof(vis1));
            for(int i = 0 ; i < N ; ++ i)
               for(int j = 0 ; j < M ; ++ j)
                 if(vis0[i][j]){
                     for(int k = 0 ; k < 4 ; ++ k){
                          int nx = i + dx[k] ; 
                          int ny = j + dy[k] ; 
                          if(nx<0||ny<0||nx>=N||ny>=M||bd[nx][ny] == '*')  continue ;
                          vis1[nx][ny] = 1 ; 
                          if(vis1[jx][jy])  return true ;
                     }
               }
            for(int i = 0 ; i < N ; ++ i)
               for(int j = 0 ; j < M ; ++ j)
               vis0[i][j] = vis1[i][j] ;
     }
     
     return false ;
}

int main(){
    
    //freopen("1.std.in" , "r" , stdin);  freopen("1.std.out" , "w" , stdout);  
    //clock_t start , end ; 
    //start = clock();
    
    int testCase , i , j , k ; 
    scanf("%d" , &testCase);
    while(testCase--){
          scanf("%d%d%d" , &N , &M , &K);
          for(i = 0 ; i < N ; ++ i)  scanf("%s" , bd[i]);
          for(i = 0 ; i < K ; ++ i)  scanf("%d" , &route[i]);
          for(i = 0 ; i < N ; ++ i)
              for(j = 0 ; j < M ; ++ j){
                   if(bd[i][j] == 'T'){
                        tx = i ;  ty = j ;
                   }else if(bd[i][j] == 'J'){
                        jx = i ;  jy = j ;
                   }
              }
          if(can())
              puts("Yes");
          else 
              puts("No");
    }
    
    //end = clock();
    //printf("%d\n" , (int)(end - start) );
    //while(getchar());
    //fclose(stdin);  fclose(stdout);
    
    return 0 ; 
}
