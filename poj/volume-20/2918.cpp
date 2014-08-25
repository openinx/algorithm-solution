#include <iostream>
#include <stdio.h>

using namespace std;

char b[9][10];

bool check(int x, int y){
     int i, j ; 
     for(i = 0 ; i < 9 ; ++ i){
         if(i != y && b[x][i] == b[x][y] ) return false;
         if(i != x && b[i][y] == b[x][y] ) return false;
     }
     for(i = 0 ; i < 3 ; ++ i){
         for(j = 0 ; j < 3 ; ++ j){
             int si = i + x / 3 * 3 , sj = j + y / 3 * 3 ; 
             if( !(si == x && sj == y) && b[si][sj] == b[x][y])
                 return false; 
         }
     }
     return true;
}

void dfs(int t){
     if(t >= 9 * 9 ) {
         for(int i = 0 ; i < 9 ; ++ i){
             for(int j = 0 ; j < 9 ; ++ j)
                 putchar(b[i][j]);
             putchar('\n');
         }
         putchar('\n');
         return ;
     }
     int x = t / 9 , y = t % 9 ;
     if(b[x][y] != '0'){  
          dfs(t+1);
          return ;
     }
     for(int i = 1 ; i <= 9 ; ++ i){
          b[x][y] = i + '0' ; 
          if(check(x,y))
              dfs(t + 1);
          b[x][y] = '0' ; 
     }
}

int main(){
    int n; 
    while(scanf("%d", &n) != EOF && n){
       for(int i = 0 ; i < n ; ++ i){
           for(int k = 0 ; k < 9 ; ++ k){
               scanf("%s", b[k]);
           }
           printf("Scenario #%d:\n", i + 1); 
           dfs(0);
       }      
    }
    return 0 ;
}
