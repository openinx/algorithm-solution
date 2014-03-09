#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std ;
const int maxn = 105 ;

struct node{
    int a ,b;
    node(){}
    node(int ia,int ib):
    a(ia) , b(ib) {} 
};
node ed(-1,-1);
int used[maxn][maxn][3];
int A , B , C ;

void cmd(int i){
     switch(i){
        case 0: printf("FILL(1)\n"); break;
        case 1: printf("FILL(2)\n"); break;
        case 2: printf("DROP(1)\n"); break;
        case 3: printf("DROP(2)\n"); break;
        case 4: printf("POUR(1,2)\n"); break;
        case 5: printf("POUR(2,1)\n"); break;
     }
}

node extend(node st , int i){
     int  ab = min(B-st.b,st.a), ba = min(A-st.a ,st.b) ; 
     switch(i){
          case 0: return  node(A , st.b);
          case 1: return  node(st.a , B);
          case 2: return  node(0 , st.b);
          case 3: return  node(st.a , 0);
          case 4: return  node(st.a - ab , st.b + ab);
          case 5: return  node(st.a + ba , st.b - ba);
     }
}

void solve(int x,int y){
     if(used[x][y][1] == 0){
         cmd(used[x][y][2]) ; return ;
     }
     solve(used[x][y][1]/maxn, used[x][y][1]%maxn);
     cmd(used[x][y][2]); 
}

int bfs(){
     int step = 1 , i , x , y; 
     queue<node>Q;
     node st(0,0) , nxt ;
     memset(used,-1,sizeof(used)); 
     used[st.a][st.b][0]=0 ;  
     Q.push(st) ;  Q.push(ed) ;
     while(!Q.empty()){
          st = Q.front() ; Q.pop() ;
          if(st.a == -1 ){
                  if(Q.empty()) return 0 ;
                  st = Q.front() ; Q.pop() ;
                  Q.push(ed);   ++step ; 
          }             
          for(i = 0 ; i < 6 ; ++ i){
               nxt = extend(st,i);
               if(used[nxt.a][nxt.b][0]!=-1 ) continue ;
               used[nxt.a][nxt.b][0] = step ;
               used[nxt.a][nxt.b][1] = st.a * maxn + st.b ;
               used[nxt.a][nxt.b][2] = i ; 
               if(nxt.a == C || nxt.b == C){
                    printf("%d\n",step);
                    solve(nxt.a,nxt.b);
                    return 1 ;
               }
               Q.push(nxt); 
          }
     }
    return 0 ;
}

int main(){
    while(scanf("%d%d%d",&A,&B,&C)!=EOF)
       if(C == 0)  
               printf("0");
       else if(!bfs()) 
               printf("impossible\n"); 
    return 0 ;
}


