#include<iostream>
#include<stdlib.h>
using namespace std;

const int maxn = 30010;
const int maxe = 160000;
const int maxint = 1000000000;

struct node
{    
     int v,w,next;
};

node e[maxe];
int N , E , es , gh[maxn];

void ins(int vs,int vt,int vc)
{    
     e[es].v = vt ; e[es].w = vc ; e[es].next = gh[vs] ; gh[vs] = es ++ ;
}

int d[maxn] , vis[maxn] ,s[maxn] ,top; 

int relax(int u,int v,int vw)
{   
    if(d[v] > d[u] + vw ) 
    {    
         d[v] = d[u] + vw  ; 
         return 1 ;
    }
    return 0;
}

int spfa()
{   
    int i,v,w;
    top = 0 ;
    for( i = 1; i<=N  ; ++i)  d[i] = maxint  ,  vis[i] = 0 ;
    s[++top] = 1 ,  d[1] = 0 , vis[1] = 1;
    while(top) 
    {    
          v = s[top -- ]  , vis[v] = 0;
          for( i = gh[v] ; i!=-1 ; i=e[i].next)
          {     
                 w = e[i].v ; 
                 if( 1 == relax(v, w ,e[i].w) && !vis[w])
                 {    
                       vis[w] = 1 , s[++top] = w; 
                 }
          }
    }
    return d[N];
}

int main()
{   
     int i,vs,vt,vc;
     while(scanf("%d%d",&N,&E)!=EOF)
     {     
           es = 0 ;
           memset(gh, -1, sizeof(gh));
           for( i = 0 ; i<E ; ++i)
           {    
                 scanf("%d%d%d",&vs,&vt,&vc);
                 ins(vs,vt,vc);
           }
           cout<<spfa()<<endl;
     }
     return 0;
}
           
