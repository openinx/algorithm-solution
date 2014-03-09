#include<iostream>
#include<stdlib.h>

using namespace std;

const int maxn = 10005;
const int maxe = 50005;

struct node
{ 
    int v,next;
};

node e[maxe];
int es, E , N ; 
int gh[maxn];

void ins(int vs, int vt )
{    
     e[es].v = vt , e[es].next=gh[vs] , gh[vs] = es ++ ;
}

int stack[maxn] , instack[maxn] ,low[maxn] ,dfn[maxn] , idx[maxn] , out[maxn] , ok[maxn] ;
int  cnt ,top , pnt ;

void tarjan( int v)
{
      int i,j,k , w , u;
      dfn[v] = low[v] = ++ cnt  ;
      stack[++top] = v;  instack[v] = 1; 
      for( i = gh[v] ; i!=-1 ;  i = e[i].next)
      {    
            w = e[i].v ; 
            if(!dfn[w])
            {   
                tarjan(w); 
                low[v] = min(low[w], low[v]); 
            }
            else 
               if(instack[w])  low[v] = min(low[v] , dfn[w]);
      }      
      if( dfn[v] == low[v])
      {    
           ++ pnt ;
           do {    u  = stack[top -- ] ;  instack[u] = 0 ; idx[u] = pnt ; ok[pnt] ++ ; 
           }  while( u!=v); 
      }  
}
      

int can()
{   
    int i,j,k;
    
    cnt = top  = pnt = 0 ; 
    memset(dfn , 0 , sizeof(dfn));    
    memset(ok ,0 , sizeof(ok));
    
    for( i = 1 ; i<=N ; ++i)
     if( !dfn[i] ) tarjan(i);
     
    if(pnt == 1)  return N ;
    
    memset(out, 0 , sizeof(out));
    for( i = 1 ; i<=N ; ++i )
        for( j = gh[i] ;j!=-1 ;j=e[j].next)
           if( idx[ e[j].v ] != idx[i] ) out[ idx[i] ] ++ ;
   
   int ret , num = 0 ;
   for(i = 1 ;i<=pnt ; ++i) 
      if( !out[i] )  {  num ++ ; ret = i ;}
   
   if(num == 0)  return N ;
   if(num > 1)   return 0 ;
   
   return ok[ret];
}  
    
int main()
{   
    int i,vs,vt;
    scanf("%d%d",&N,&E);
    es = 0  ;
    memset(gh , -1, sizeof(gh));
    for(i = 0 ; i<E ; ++i)
    {   
         scanf("%d%d",&vs,&vt);
         ins(vs,vt);
    }
    cout<<can()<<endl;
    
    //while(getchar());
    
    return 0;
}
     
     
