#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#define FillMatrix(_a , _N , _M , _value) for(int xi=0;xi<_N;++xi)for(int xj=0;xj<_M;++xj) _a[xi][xj]=_value

using namespace std ;

const int MAX_A = 50 ; 
const int MAX_B = 50 ;
const int MAX_N = MAX_A + MAX_B ; 
const int MAX_K = 11 ; 
const int INT_INF = 100000005 ; 

struct edge{ 
       int vex , level , weight ; 
       edge(){}
       edge(int _vex , int _level , int _weight)
          :vex(_vex) , level(_level)  , weight(_weight){} 
} ; 

int mat[MAX_N][MAX_N] , dist[MAX_N][MAX_N] ;
int A , B , M , L , K , VexNum  ;
int sourceVex , sourceLevel , destVex , destLevel ;  

vector<edge> g[MAX_N][MAX_K] ;

void AddEdge(int fromVex , int fromLevel , int toVex , int toLevel , int weight ){
     g[fromVex][fromLevel].push_back( edge(toVex , toLevel , weight) ) ;
}

void GetData(){
     int i , j , k , from , to , weight ;
     scanf("%d%d%d%d%d" , &A ,&B , &M , &L , &K); 
     VexNum = A + B ;  K = K + 1 ;
     FillMatrix(mat , VexNum , VexNum , INT_INF);
     for(i = 0 ; i < VexNum ; ++ i)  mat[i][i] = 0 ; 
     for(i = 0 ; i < M ; ++ i){
          scanf("%d%d%d" , &from , &to , &weight); 
          --from ; --to ;
          mat[from][to] = mat[to][from] = weight ;
     }
     for(i = 0 ; i < VexNum ; ++ i) for(j = 0 ; j < VexNum ; ++ j)
         dist[i][j] = mat[i][j] ;
     for(k = 0 ; k < VexNum ; ++ k )
       for(i = 0 ; i < VexNum ; ++ i)
          for(j = 0 ; j < VexNum ; ++ j)
             if(k < A && dist[i][j] > dist[i][k] + dist[k][j] )
                 dist[i][j] = dist[i][k] + dist[k][j] ;
}

void BuildGraph(){
     int i , j , k ; 
     sourceVex = A + B - 1 ; sourceLevel = 0 ; 
     destVex = 0 ; destLevel = K-1 ;
     for(i = 0 ; i < MAX_N ; ++i) for(j = 0 ; j < MAX_K ; ++j)
        g[i][j].clear() ;
     for(k = 0 ; k < K ; ++ k)
        for(i = 0 ; i < VexNum ; ++ i)
           for(j = 0 ; j < VexNum ; ++ j)
              if(mat[i][j] < INT_INF)  
                 AddEdge(i , k , j , k , mat[i][j]) ;
     for(k = 0 ; k < K - 1 ; ++ k)
        for(i = 0 ; i < VexNum ; ++ i)
           for(j = 0 ; j < VexNum ; ++ j)
              if(dist[i][j] <= L )
                 AddEdge(i , k , j , k+1 , 0 ) ;
}

int d[MAX_N][MAX_K] , visit[MAX_N][MAX_K] ;

typedef pair<int , int > Pii ; 

int ShortestPath(){
     queue< Pii > Q ;
     FillMatrix(d , MAX_N , MAX_K , INT_INF) ;
     FillMatrix(visit , MAX_N , MAX_K , 0 );
     Q.push( Pii(sourceVex , sourceLevel) );
     d[sourceVex][sourceLevel] = 0 ; 
     visit[sourceVex][sourceLevel] = 1 ;
     while(!Q.empty()){
          Pii status = Q.front() ;
          Q.pop() ; 
          visit[status.first][status.second] = 0 ;
          for(vector<edge>::iterator it = g[status.first][status.second].begin() ; 
          it != g[status.first][status.second].end() ;  it ++ ){
                 if(d[it->vex][it->level] > d[status.first][status.second] + it->weight){
                        d[it->vex][it->level] = d[status.first][status.second] + it->weight ;
                        if(visit[it->vex][it->level] == 0 ){
                             Q.push( Pii(it->vex , it->level ) );
                             visit[it->vex][it->level] = 1 ; 
                        }// end for if  
                 }// end for if 
          }//end for for  
     }// end for while
     return d[destVex][destLevel] ;
}// end for fuction 

int main(){
    
    freopen("1.std.in" , "r" , stdin);
    freopen("1.std.out" , "w" , stdout);
    
    int CaseNumber ; 
    scanf("%d" , &CaseNumber) ;
    while(CaseNumber -- ){
          GetData() ; 
          BuildGraph() ;
          int answer = ShortestPath() ;
          printf("%d\n" , answer);
    }
    
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0 ;
}
