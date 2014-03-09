#include<iostream>
#include<stdlib.h>
using namespace std;

const int maxn = 10010;
const int maxe = 1000010;
struct node
{    
     int v,next;
};
node e[maxe];
int gh[maxn];
int es , N, E , cnt;
int low[maxn], ans[maxn] , dfn[maxn] , root[maxn];

void ins(int vs,int vt)
{   
     e[es].v = vt ; e[es].next = gh[vs] ; gh[vs] = es ++ ;
}

void dfs(int v)
{    
     dfn[v] = low[v] = ++cnt;
     
     int i, w;
     for( i = gh[v] ; i!=-1 ; i = e[i].next)
     {    
          w = e[i].v; 
          if(!dfn[w]) 
          {     
                dfs(w); 
                low[v] = min( low[v] , low[w]);
                if(low[w] >= dfn[v]) 
                     ans[v] ++ ;
          }
          else  
              low[v] = min(low[v] , dfn[w]);
     }
}
           

int main()
{    
     int i,j,vs,vt , tot ;
     while(scanf("%d%d",&N,&E)!=EOF && ( N || E))
     {    
          es  = 0 , cnt = 0 , tot = 0 ;
          memset(gh , -1, sizeof(gh));
          for(i = 0 ; i<E ; ++i)
          {     
                scanf("%d%d",&vs,&vt);
                ins(vs,vt); ins(vt,vs);
          }
          
          memset( dfn , 0 , sizeof(dfn));  
          memset( ans , 0 , sizeof(ans));
          memset(root , 0 , sizeof(root));
          
          for(i = 0 ; i<N ; ++i)
            if(!dfn[i]) 
            {       
                    root[i] = 1 ;   dfs(i);  ++ tot;
            }
          
          int ret = 0 ; 
          for(i = 0 ; i< N ; ++i)
              if(root[i]) 
                    ret = max( ret , ans[i] + tot -1 ) ; 
              else 
                    ret = max( ret , ans[i] + tot ) ;
     
          cout<<ret<<endl;
     }
     return 0;
}
             
                                    
     
    

