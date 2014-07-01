#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

//const double DOU_INF = 1e100 ;
const int SCREEN_HEIGHT = 1001  ; 
const int SCREEN_WIDTH  = 1001  ; 
const int MOD = 1000000009 ; 

struct Point{
       int x , y ; 
};
struct Edge{
       int ymax ; 
       double x , deltax ;         
       Edge(){}
       Edge(int _y , double _x ,double _d):
                ymax(_y) , x(_x) , deltax(_d) {}
       bool operator < (const Edge &that )const{
            if( abs(x - that.x) < 1e-8 ) 
                return deltax < that.deltax ;
            return x < that.x ;  
       }
};

int SUM = 0 ;
bool mark[SCREEN_HEIGHT][SCREEN_WIDTH] ; 
vector<Point> Polygon ;  

vector <Edge> ET[ SCREEN_HEIGHT ]   ;
vector <Edge> AEL , TEMP ; 
typedef vector<Edge>:: iterator vit ; 

int toEdge(Point a , Point b , Edge &e ){
    if(a.y > b.y ) swap(a , b);
    e.ymax = b.y ; 
    e.x = a.x ; 
    e.deltax = (double)(a.x - b.x) / (double)(a.y - b.y) ; 
    return a.y ; 
}

void InitData(){
     int n , i ;
     Point s , t ;  
     Edge e ; 
     
     memset(mark , false ,sizeof(mark));
     Polygon.clear() ; 
     AEL.clear() ;
     for(i = 0 ; i < SCREEN_HEIGHT ; ++ i)
         ET[i].clear() ;
     
     scanf("%d" , &n );
     for(i = 0 ; i < n ; ++ i){
          scanf("%d%d" ,&t.x , &t.y);
          Polygon.push_back(t);
     } 
         
     t = Polygon[ Polygon.size() - 1 ] ;
     for(i = 0 ; i < Polygon.size() ; ++ i){
           s = Polygon[i] ;
           if(t.y != s.y ){
              int ID = toEdge(s , t , e) ; 
              ET[ ID ].push_back(e) ;
           }
           t = s ;    
     }  
}

inline void PutPixel(int x , int y){
     //printf("%d %d\n" ,x , y);
     mark[x][y] = true ;
}

void FillHorizonalLine(int left , int right , int y ){
     for( int i = left ; i <= right ; ++ i )
          PutPixel(i , y);
}

inline int L(double x) { return (int)x + 1 ;}
inline int R(double x) { return abs(floor(x)-x)<1e-8 ? ((int)x-1) : (int)x ;}

void SweepLineFill(){
     double left , right ;
     int currentLine , i ; 
     for(currentLine=0 ; currentLine<SCREEN_HEIGHT ; ++ currentLine ){ 
          
          for(vit it = ET[currentLine].begin() ; it != ET[currentLine].end() ; ++ it)
                   AEL.push_back(*it);

          TEMP.clear() ;
          for(i = 0 ; i < AEL.size() ; ++i )
             if(AEL[i].ymax != currentLine )
                 TEMP.push_back(AEL[i]);
          AEL.clear();
          for(i = 0 ; i < TEMP.size(); ++ i)
              AEL.push_back(TEMP[i]);
          
          sort(AEL.begin() , AEL.end());
//printf("#debug===currentLine:%d======AEL.size():%d\n" , currentLine , AEL.size() );
          for(i = 0 ; i < AEL.size() ; i += 2){
                 left = AEL[i].x ; right = AEL[i+1].x ; 
                 FillHorizonalLine(L(left) , R(right) , currentLine);
          }
          
          for(i = 0 ; i < AEL.size() ; ++ i)
              AEL[i].x += AEL[i].deltax ; 
     }
}

void PaintLine(Point a , Point b){
     if(a.y == b.y){
        for(int i = min(a.x,b.x) ; i<=max(a.x,b.x) ;++i)
           mark[i][a.y] = false ;
     }else if(a.x == b.x){
        for(int i = min(a.y,b.y) ; i<=max(a.y,b.y) ;++i)
           mark[a.x][i] = false ;
     }else{
        if(a.x >  b.x) swap(a ,b);
        for(int i = a.x ; i <= b.x ; ++ i)
            if((i-a.x)*(a.y-b.y)%(a.x-b.x)==0){
                 mark[i][a.y+(i-a.x)*(a.y-b.y)/(a.x-b.x)] = false ;
            }
     }
}

void DeleteEdge(){
     Point s , t ; 
     t = Polygon[ Polygon.size() - 1 ] ;
     for(int i = 0 ; i < Polygon.size() ; ++ i){
         s = Polygon[i] ;
         PaintLine(s , t);
         t = s ;
     }
}

int main(){
    
    freopen("1.std.in" , "r" , stdin);
    freopen("1.std.out", "w" , stdout);
    
    int caseNumber ; 
    
//clock_t start_time  , end_time ; 
//start_time = clock() ;
    
    scanf("%d" ,&caseNumber);
    while(caseNumber -- ){
      InitData()  ; 
      SweepLineFill() ;
      DeleteEdge();
      SUM = 0 ;
      for(int i = 0 ; i < SCREEN_HEIGHT ; ++ i)
        for(int j = 0 ; j < SCREEN_WIDTH ; ++ j)
          if(mark[i][j]){
             SUM = (SUM+(i^j)) % MOD ;
//printf("#debug===(%d,%d)====\n",i,j);
          } 
      printf("%d\n" , SUM); 
    }
    
//end_time = clock() ;
//printf("time:%d ms\n" , (int)(end_time - start_time));
    
    fclose(stdin);
    fclose(stdout);
    
    
    return 0 ;
}
