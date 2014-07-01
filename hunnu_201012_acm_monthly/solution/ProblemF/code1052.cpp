#include<iostream>
using namespace std ;

const int maxn = 110 ;
const int INF  = 1000000100 ;

int N , M , G[maxn][maxn] , low , up , Matrix[maxn][maxn] , a[maxn][maxn] , G0[maxn][maxn] ;

void input(){
     
     int i , j , x , y , w;
     
     scanf("%d%d\n" , &N , &M);
     scanf("%d%d\n" , &low , &up);
     
     for(i = 1 ; i <= N ; ++i)
        for(j = 1 ; j<=N ;++j ) 
           G[i][j] = INF ;
        
     for(i = 1 ; i <= M ;++i){
           scanf("%d%d%d" , &x ,&y , &w);
           G[y][x] = G[x][y] = min(G[x][y] , w);
     }
     
     for(i = 1 ; i<= N ; ++i)  for(j = 1 ; j<=N ;++j)   G0[i][j] = G[i][j] ;

}

//   Matrix = Matrix * G^exp ;
void power_Matrix(int exp){
     
     int i , j , k ; 
     
     while(exp){
            if(exp & 1){
                  for(i = 1 ; i<= N ; ++i)
                      for(j = 1 ; j <= N ; ++j){
                           a[i][j] = INF ;
                           for(k = 1 ; k <= N ; ++k)
                               a[i][j] = min(a[i][j] , Matrix[i][k] + G[k][j]);
                      }
                  for(i = 1 ; i<= N ; ++i)  for(j = 1 ; j <= N ;++j)  Matrix[i][j] = a[i][j] ;
            }
            exp = exp / 2 ;
            for(i = 1 ; i <= N ; ++i)
                 for(j = 1 ; j<= N ; ++j){
                        a[i][j] = INF ;
                        for(k = 1 ; k <= N ; ++k)
                            a[i][j] = min(a[i][j] , G[i][k] + G[k][j]);
                 }
            for(i = 1 ; i<= N ; ++i) for(j = 1 ; j<= N ; ++j)  G[i][j] = a[i][j];
     }
     
}


void work(){
     
     int i , j ;
     for(i = 1 ; i <= N ; ++i)  for(j = 1 ; j<= N ; ++j)   Matrix[i][j] = INF ;
     
     for(i = 1 ; i <= N ; ++i)  Matrix[i][i] = 0 ;
     
     power_Matrix(low);
     
     for(i = 1 ; i <= N ; ++i) for(j = 1 ; j<= N ; ++j) G[i][j] = G0[i][j] ;
     
     for(i = 1 ; i <= N ; ++i)  G[i][i] = 0 ;
     
     power_Matrix(up - low);
     
     if(Matrix[1][N] >= INF ){  
             printf("-1\n");
     }else{ 
             printf("%d\n" ,Matrix[1][N]);
     }
             
}

int main(){
    
    //freopen("1.std.in" ,"r"  ,stdin);  freopen("1.std.out" ,"w" ,stdout);
    
    
    int testCase ; 
    scanf("%d" , &testCase);
    
    while(testCase--){
          input();
          work();
    }
    
    //fclose(stdin);  fclose(stdout);
    
    return 0 ;
    
}
