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

const int DN = 8 ; 
const int dx[] = {0 , -1 , -1 ,-1 , 0 , 1 , 1 , 1} ;
const int dy[] = {1 ,  1 ,  0 ,-1 ,-1 ,-1 , 0 , 1} ;
const int H = 16 ;
const int W = 30 ;
const int MINE = 9  ; 
const int NOT_CLICK = 11  ; 

int start_x , start_y ;
int  mine[H][W] , status[H][W] ; 
char board[H][W+5] ;

inline bool isOut(int _x , int _y){
    return  _x < 0 || _y < 0 || _x >= H || _y >= W ;
}

/*void show_2array(int _a[][W]){
     int i , j ;
     printf("\n\n");
     for(i = 0 ; i < H ; ++ i){
          for(j = 0 ; j < W ; ++ j)
             printf("%3d" , _a[i][j] );
          printf("\n");      
     }
}*/


typedef pair<int ,int> pii ;

void click(){
     
     queue< pii > Q ;
     for(int i = 0 ; i < H ; ++ i) 
        for(int j = 0 ; j < W ; ++ j)
           status[i][j] = NOT_CLICK ;
     
     status[ start_x ][ start_y ] = mine[start_x][start_y] ;
     if(mine[ start_x ][ start_y ] == 0 ){
         Q.push( pii(start_x , start_y));
         while(!Q.empty()){
                pii wo = Q.front() ; Q.pop() ;
                for(int k = 0 ; k < 8 ; ++ k){
                      pii ni(wo.first + dx[k] , wo.second + dy[k]);
                      if( ! isOut(ni.first ,ni.second ) 
                        &&  status[ni.first][ni.second] == NOT_CLICK 
                        &&  mine [ni.first][ni.second] == 0){
                              status[ni.first][ni.second] = mine[ni.first][ni.second] ;
                              Q.push(ni);
                        }
                }
         }
         
         for(int i = 0 ; i < H ; ++ i) 
           for(int j = 0 ; j < W ; ++ j)
              if(status[i][j] == 0){
                    for(int k = 0 ; k < DN ; ++ k){
                          pii wo(i + dx[k] , j + dy[k]) ;
                          if(!isOut(wo.first ,wo.second) && status[wo.first][wo.second]==NOT_CLICK)
                              status[wo.first][wo.second] = mine[wo.first][wo.second];
                    }
              }
           
     }
     for(int i = 0 ; i < H ; ++ i){
        for(int j = 0 ; j < W ; ++ j)     
            if(status[i][j] == NOT_CLICK)
                putchar('#');
            else 
                printf("%d" , status[i][j]);
        printf("\n");   
     }
}


int main(){
    
    freopen("1.std.in" , "r" , stdin);
    freopen("1.std.out" , "w" , stdout);
    int case_count , x , y , cas ; 
    scanf("%d" , &case_count );
    for(cas = 1 ; cas <= case_count ; ++ cas ){
        scanf("%d%d" ,&start_x , &start_y);
        --start_x ; --start_y ;
        for(int i = 0 ; i < H ; ++ i) 
           scanf("%s" , board[i]);
        memset(mine , 0 , sizeof(mine));
        for(int i = 0 ; i < H ; ++ i)
          for(int j = 0 ; j < W ; ++ j)
             if(board[i][j] == '*'){
                 mine[i][j] = MINE ;
             }else{
                  int m_cnt = 0 ; 
                  for(int k = 0 ; k < DN ; ++ k){
                       x = i + dx[k] ; y = j + dy[k] ;
                       if(!isOut(x , y) && board[x][y]=='*')
                          ++ m_cnt ;
                  }
                  mine[i][j] = m_cnt ;
             } 
             
        if(cas != 1)   
            printf("\n");
        click();
        
    }
    fclose(stdin);
    fclose(stdout);  
    return 0 ;
}
