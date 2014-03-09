#include<iostream>
#include<queue>
#define maxn 500
#define maxe 50005
#define inf (1<<28)

using namespace std ;

struct node
{   
    int x, y , c ,next ;
} ;

int N , S , T  ;
int hd[maxn] , es ;
node e[maxe] ;
int ps[maxn] , cur[maxn] ,dep[maxn] ;

void ins(int x ,int y ,int c)
{    
     e[es].x = x, e[es].y = y , e[es].c = c, e[es].next = hd[x] , hd[x] = es ++ ;
     e[es].x = y, e[es].y = x , e[es].c = 0, e[es].next = hd[y] , hd[y] = es ++ ;
}

void readln()
{    
     int i , j ,  t , cow , food , drink , fi,di , tot;
     scanf("%d%d%d",&cow,&food,&drink);
     S = 2*cow + food + drink + 1 ; 
     T = S + 1  ; 
     N = T ; 
     tot = 2*cow ; 
     es = 0 ;  
     memset(hd, -1 ,sizeof(hd));     //  init graph 
     for(i = 1 ; i<=cow  ; ++i) ins(i, cow+i,1);
     for(i = 1 ; i<=cow  ; ++i)
     {   
         scanf("%d%d",&fi,&di);
         for(j =1 ;j<=fi ; ++j)
         {  
              scanf("%d",&t);
              ins(cow + i , tot + t , 1);
         }
         for(j =1 ;j<=di ; ++j)
         {
              scanf("%d",&t);
              ins(tot + food + t , i , 1);
         }
     }
     for(i = 1 ; i<=food ; ++i) ins(tot + i , T ,1);
     for(i = 1 ; i<=drink; ++i) ins(S , tot + food + i , 1 );
}

int maxflow()
{   
    int del , maxf = 0  , u , v , i ;
    while(1)
    {
       queue<int> Q ; 
       Q.push(S) ;
       memset(dep , -1 ,sizeof(dep));  
       while(!Q.empty()) 
       {  
            v = Q.front() ; Q.pop() ;
            for(i = hd[v] ; i!=-1 ; i=e[i].next)
            { 
               u = e[i].y ;
               if( e[i].c && dep[u]==-1 ) dep[u] = v , Q.push(u) , ps[u] =  i ;
            }
            if( dep[T]!=-1 )  break;
       }
       if( dep[T]==-1 ) break;
       
       for(del = inf , u = T ; u!=S ; u = dep[u])  
              del = min( del , e[ps[u]].c ) ; 
       for(u = T ; u!=S ; u = dep[u])  
              e[ps[u]].c -= del , e[ps[u]^1].c += del ;
       maxf += del ;    
    }
    return maxf  ;
}

int main()
{   
    readln();
    printf("%d\n",maxflow());
    //while(getchar());
    return 0 ;
}
