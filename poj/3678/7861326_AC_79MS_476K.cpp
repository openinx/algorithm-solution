#include<iostream>
#include<cstring>
#define  MAXN 2005
using namespace std ;

struct Edge{
       int y , next ;
};
Edge  e[MAXN*MAXN] ;
int   es , hd[MAXN];
int   Vcnt , Ecnt    ;

inline  void ins(int x ,int y){
       e[es].y = y , e[es].next = hd[x] , hd[x] = es ++ ;
}

bool cal(bool x , bool y , char cmd[]){
     if(!strcmp(cmd ,"AND")){
           return x & y ;
     }else if(!strcmp(cmd ,"OR")){
           return x|y   ;
     }else if(!strcmp(cmd,"XOR")){
           return x^y   ; 
     }
}

int bcnt , top , idx ;
int stk[MAXN] ,instk[MAXN] ,dfn[MAXN] , low[MAXN] ,bel[MAXN];

void Tarjan(int x){
     int i ,y ;
     dfn[x] = low[x] = ++ idx ;
     instk[x] = 1 , stk[top++] = x ;
     for(i = hd[x] ; i!=-1 ;i=e[i].next){
             y = e[i].y ; 
             if(dfn[y] == -1){
                  Tarjan(y) ; 
                  low[x] = min(low[x] ,low[y]) ;  
             }else if(instk[y]){
                  low[x] = min(low[x] ,dfn[y]);
             }
     }
     if( low[x] == dfn[x]){
           ++ bcnt  ;
           do{
                y =  stk[--top] ;  instk[y] = 0 ;  bel[y] = bcnt ;
           }while(y!=x);
     }
}


int main(){
     int i , x , y , c;
     char  cmd[10] ;
     scanf("%d%d" , &Vcnt ,&Ecnt);
     es = 0 ; memset(hd , -1 ,sizeof(hd));
     while(Ecnt--){
           scanf("%d%d%d%s",&x,&y,&c,cmd);  ++ x  ; ++ y ;
           if(cal(0,0,cmd) != c ){
               ins(2*x-1,2*y) , ins(2*y-1,2*x) ;
           }
           if(cal(0,1,cmd) != c){
               ins(2*x-1,2*y-1) ,ins(2*y,2*x) ;
           }
           if(cal(1,0,cmd) != c){
              ins(2*x ,2*y) , ins(2*y-1,2*x-1) ;
           }
           if(cal(1,1,cmd) != c){
              ins(2*x,2*y-1) , ins(2*y,2*x-1);
           }
     }
     bcnt = idx = top = 0 ; 
     memset(dfn   , -1 , sizeof(dfn)) ;
     memset(instk , 0  , sizeof(instk));
     for(i = 1 ; i<=Vcnt*2 ; ++i)
       if(dfn[i] == -1) 
          Tarjan(i);
     for(i = c = 1 ; i<=Vcnt ;++i)
          if(bel[2*i-1] == bel[2*i] ){
              c = 0  ; break ;
          }
     if(c)  
        puts("YES");
     else
        puts("NO");
     return 0 ;     
}
