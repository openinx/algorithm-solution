#include<iostream>
#include<queue>
using namespace std ;

const  int  maxn = 105 * 105 ;
const  int  maxe = 4 * maxn  ;
const  double INF = 1e100    ;
const  double EPS = 1e-8    ;
int dx[]={1,0,-1,0} ,dy[]={0,1,0,-1};

struct node{
       int y , next ;
       double c ;
};
node e[maxe] ;
int  es , hd[maxn] ,S ,T , N ; 
char bd[105][105] ;
int  row ,col ;

inline int sgn(double x){
       return (x>EPS)-(x<-EPS);
}


void ins(int x , int y , double c){
     e[es].y = y , e[es].c = c ,
     e[es].next = hd[x] , hd[x] = es ++ ;
}

double dist[maxn] ; 
int    vis[maxn]  ;

double SPFA(){
       queue<int> Q ; 
       int i , u , v ;
       for(i = 0 ; i <= N ; ++ i)  dist[i] = INF , vis[i] = 0 ;
       dist[S] = 0 , vis[S] = 1 , Q.push(S);
       while(!Q.empty()){
              v = Q.front() ; Q.pop() ;  vis[v] = 0 ;
              for(i = hd[v] ; i!=-1 ; i=e[i].next)
                 if(dist[u = e[i].y] > dist[v] + e[i].c ){
                     dist[u] = dist[v] + e[i].c ; 
                     if(!vis[u])  vis[u] = 1 , Q.push(u);
                 }
       }
       return dist[T] ;
}

double Try(double t ){
     int i , j , k ,nx ,ny; 
     es = 0 ; memset(hd , -1 ,sizeof(hd));  N = row * col + 1 ;
     for(i = 0 ; i <row ; ++ i)
         for(j = 0 ; j <col ; ++j)
           if(bd[i][j]!='#'){
                for(k = 0 ; k < 4 ;++ k){
                    nx = i + dx[k] , ny = j + dy[k]  ;
                    if((nx<0||ny<0||nx>=row||ny>=col)||bd[nx][ny]=='#') continue ;
                    if(k ==0 || k==2) 
                           ins(i*col+j , nx*col+ny ,t);
                    else   
                           ins(i*col+j , nx*col+ny ,1);
                }
               if(bd[i][j]=='S')  
                        S = i*col+j ;
               else  if(bd[i][j]=='E')  
                        T = i*col+j ;
           }
    return  SPFA();
}

int main(){
    int cs , i , tst = 0 ;
    char str[20] ;
    double  des , t1 ,t2 ,t3 , ty;
    scanf("%d" ,&cs);
    while(cs--){
              scanf("%lf%d" ,&des ,&row); gets(str);
              for(i = 0 ; i<row ;++i)  gets(bd[i]);
              col = strlen(bd[0]); 
              t1 = 0 , t3 = 1000 ;
              for(i = 0 ; i < 100 ; ++i){
                      t2 =(t1+t3)/2 ;
                      ty = Try(t2); 
                      if(!sgn(ty-des))  break ;
                      else  if(sgn(ty-des)==1) 
                              t3 = t2 ;
                      else   
                              t1 = t2 ;
              }  
              printf("Case #%d: %0.3lf%s\n" ,++tst , t2*100 ,"%");
    }
    return 0;
}
