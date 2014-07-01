#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>

using namespace std ;

const int MAXN = 26 ;
const int MOD  = 30011 ; 
const int MAX_V = 25 ; 

bool visit[MAXN][MAXN] ;
int dp[MAXN][MAXN] , val[MAXN] ; 
vector<int> list[MAXN] ;

int DFS(int n , int M ){
     int len = list[n].size() ;
     dp[n][ val[n] ] = 1 ;
     for(int i = 0 ; i <= val[n] ; ++ i) visit[n][i] = 1 ;
     if(visit[n][M]) return dp[n][M] ;
     for(int i = 0 ; i < len ; ++ i){
          int s = list[n][i] ; 
          for(int j = MAX_V ; j> val[n] ; -- j){
              for(int k = val[s] ; k <= j-val[n] ; ++ k){
                   dp[n][j] = (dp[n][j] + dp[n][j-k] * DFS(s , k)) % MOD ;
              }
          }
     }
     for(int j = MAX_V ; j > val[n] ; --j) visit[n][j] = 1 ;
     return dp[n][M];
}

int main(){
    freopen("1.std.in" , "r" , stdin);
    freopen("1.std.out" , "w" ,stdout);
    for(int i = 0 ; i < MAXN ; ++ i)
       val[i] = i % 5 + 1 ; 
    int CaseNumber , lines  ; 
    char s[30] ;
    scanf("%d" , &CaseNumber);
    while(CaseNumber--){
         scanf("%d" , &lines );
         for(int i = 0 ; i < MAXN  ; ++ i)
             list[i].clear() ;
         for(int i = 0 ; i < lines ; ++ i){
               scanf("%s" , s);
               for(int j = 1 ; j < strlen(s) ; ++ j)
                  list[s[0]-'A'].push_back(s[j]-'A');
         }
         memset(dp , 0 , sizeof(dp));
         memset(visit , 0 ,sizeof(visit));
         int ans = 0 ; 
         for(int i = 0 ; i < MAXN ;++ i){
            ans = (ans + DFS(i,MAX_V)) % MOD ;
         } 
         printf("%d\n" , ans );
    }
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0 ;
}
