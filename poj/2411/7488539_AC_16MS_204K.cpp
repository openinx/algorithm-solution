#include<iostream>
#include<stdlib.h>
using namespace std;

typedef __int64 i64;
const int maxn = 1<<12;
const int maxl = 150;
int  status , als , n ,h ;
int all[maxl] ;
i64 f[maxn] , s[maxn];

inline void put(int &bd ,int i)
{       
       if(!( bd & (1<<i) )) bd += 1<<i;
}

inline void clr(int &bd ,int i)
{     
       if(  bd & (1<<i) )   bd -= 1<<i;
}


void dfs(int i)
{    
     if(i >= n - 1 ) 
     {  
        all[als ++ ] = status; 
        return ;
     }
     dfs(i + 1);
     put(status , i); put(status , i + 1 );
     dfs(i + 2);
     clr(status , i); clr(status , i + 1 ); 
}

i64 dp()
{
    int i , j , row , son , t , c; 
    
    status = als = 0 ;  dfs(0) ;
    
    memset(f , 0 ,sizeof(f));
    for(i = 0 ; i<als ; ++i) f[ all[i] ] = 1 ;
    
    for(row = 1 ; row < h; ++ row)
    {
         memset(s , 0 , sizeof(s));
         for(i = 0 ; i< (1<<n) ; ++i)
            if( f[i] != 0 )
            {   
               c =  i ^( (1<<n) - 1 ) ;
               
               for( j = 0 ; j< als ; ++j)
                 if( !( all[j] & c ) ) 
                 {    
                      t =  c + all[j] ; 
                      s[ t ] += f[i];
                 }
            }
         for(i = 0 ; i< (1<<n) ; ++i)
              f[i] = s[i] ;
    }
    return f[( 1<<n )- 1];
}
    
int main()
{     
      while(scanf("%d%d",&h , &n )!=EOF && ( h || n))   
                 printf("%I64d\n",dp());
      return 0;
}      
  
     
     
     
      
