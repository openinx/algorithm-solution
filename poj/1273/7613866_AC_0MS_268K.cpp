#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std ;

const int maxn = 205 ;
const int maxe = 2*maxn ;
const int inf = 200000000;

struct node
{   
   int x, y , c , next ;
   node(){}
   node(int ix,int iy,int ic,int inext):
   x(ix),y(iy),c(ic),next(inext) {}
} ;

struct network
{      
       node e[maxe] ;
       int S ,  T  , N , es , hd[maxn];
       int ps[maxn] , dep[maxn] , cur[maxn] ;
       void init(int vS ,int vT ,int vN);
       void ins(int x,int y ,int c) ;
       int dinic();
};

void network::init(int vS ,int vT ,int vN)
{
     S = vS , T = vT , N = vN ;
     es =  0 ; memset(hd , -1 ,sizeof(hd));    
}

void network::ins(int x,int y ,int c)
{   
    e[es].x = x, e[es].y = y ,e[es].c = c , e[es].next = hd[x] , hd[x] = es ++ ;
    e[es].x = y, e[es].y = x, e[es].c = 0 , e[es].next = hd[y] , hd[y] = es ++ ; 
}

int network::dinic()
{  
      int maxf = 0 , i ,j , k , u , v  , tr , top , f, r ;
      while(1)
      {
           f = r = 0 ; memset(dep , -1 ,sizeof(dep));
           ps[r++] = S  ;   dep[S] = 0 ;
           while(f!=r) 
           {
                v = ps[f++] ;
                for(i = hd[v] ; i!=-1 ; i = e[i].next)
                   if(e[i].c && dep[e[i].y] == -1) 
                      dep[e[i].y] = dep[v] + 1 , ps[r++] = e[i].y ;
                if(dep[T]!=-1)  break;
           } 
           if(dep[T]==-1)  break;
           
           i =S , top = 0 ; memcpy(cur , hd, sizeof(hd));
           while(1)
           {  
                  if(i == T)
                  {  
                     for( k = 0 , tr = inf  ; k < top ; ++k)
                       if( e[ps[k]].c < tr )   tr = e[ps[k]].c , f = k ;
                     for( k = 0 ; k < top ; ++ k)
                       e[ps[k]].c -= tr , e[ps[k]^1].c += tr ;
                     maxf += tr ;  i = e[ps[top = f]].x ;     
                  }
                  for( j = cur[i] ; cur[i]!=-1 ; j = cur[i] = e[j].next)
                      if(e[j].c && dep[e[j].y] == dep[i] + 1 )  break; 
                  if(cur[i]!=-1)
                  {  
                      ps[top++] = cur[i] ;  i = e[cur[i]].y ;
                  }
                  else 
                  {  
                     if(top == 0) break;
                     dep[i] = -1 ;  i = e[ps[--top]].x ;  
                  }
           }
      }
      return maxf ;
}

int main()
{   
    network  gh ;
    int i , ecnt , vcnt , s , t , w , S , T , N ; 
    while(cin>>ecnt>>vcnt)
    {
       S = 1 ; T = vcnt ; N = vcnt ;
       gh.init(S , T , N);
       for(i = 1 ; i<=ecnt ; ++i)
        {
           cin>>s>>t>>w ; 
           gh.ins(s, t , w);
        }
        cout<<gh.dinic()<<endl;
    }
    return 0 ;
}
    

       
