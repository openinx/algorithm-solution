#include<iostream>
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

int dinic()
{   
    int maxf = 0 , top ,  f , r , u , v , i , j , k , tr  ;
    while(1)
    {    
          memset(dep , -1 , sizeof(dep)); f = r = 0 ;
          ps[r++] = S , dep[S] = 0 ;
          while(f!=r)
          { 
               v = ps[f++] ;
               for( i = hd[v] ; i!=-1 ; i=e[i].next)
               { 
                    u = e[i].y ;
                    if( e[i].c && -1 == dep[u] )  // dep[u]  have not be marked 
                       dep[u] = dep[v] + 1 , ps[r++] = u ;
               }
               if( dep[T]!=-1 )   break;
          }
          if( dep[T] == -1 )  break; 
          
          i = S , top = 0 ;  memcpy(cur , hd , sizeof(hd));
          while(1)
          {  
                if(i == T) 
                {
                     for(k = 0 , tr = inf ; k<top ; ++k )
                         if( tr > e[k].c )  tr = e[ ps[k] ].c , f = k ;
                     for(k = 0 ; k<top ;++k)
                         e[ps[k]].c -= tr , e[ps[k]^1].c += tr ;
                     maxf += tr ,  i = e[ ps[top = f] ].x ;   // back to the point 
                }
                for(j = cur[i] ; cur[i]!= -1 ; j = cur[i]=e[cur[i]].next)
                    if(e[j].c && dep[i] + 1 == dep[ e[j].y ] )  break;
                if( cur[i]!=-1 ) {
                    ps[top++] = cur[i] ; i = e[cur[i]].y  ;    //  trackback -> foward
                }
                else {
                    if( 0 == top )  break;   //  end while(1) 
                    dep[i]=-1 ;  --top ; i = e[ps[top]].x ;    //  trackback -> back  
                }
          }
    }
    return maxf ; 
}

int main()
{  
    readln();
    printf("%d",dinic());
    return 0 ;
}
     



















