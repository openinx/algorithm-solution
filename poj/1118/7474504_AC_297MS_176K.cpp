#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int maxn = 1005;
const double inf = 1e100;

struct node
{    
     double x,y;
};

node operator - ( node a,node b )
{    
     node c; 
     c.x = a.x - b.x ; c.y = a.y -  b.y;
     return c;
}

node p[maxn];
double lk[maxn];

bool  can()
{   
    int n , tot ,ans ,cnt , i ,j;
    node c;
    scanf("%d",&n);  if( n == 0)  return false;
    for(i = 0 ;i<n; ++i)  
           scanf("%lf%lf",&p[i].x, &p[i].y);
    ans = 0;
    for( i = 0 ; i<n; ++i)
    {   
        for( tot = 0 , j = 0 ;j<n; ++j)
          if(j!=i)
          {     
              c = p[j] - p[i];
              if(c.x == 0) lk[tot ++ ] = inf;
              else 
                  lk[ tot ++ ] = c.y / c.x ;
          }
       sort(lk , lk + tot);
       
       //for( j = 0 ;j < tot; ++j)  cout<<lk[j]<<endl;
       
       double first = lk[0] ; cnt = 1;
       for( j = 1 ; j < tot ; ++j)
           if(lk[ j ] == first) 
                 ++cnt ;
           else 
           {   
               //cout<<"cnt:"<<cnt<<endl;
               ans = max( cnt + 1 ,ans ) ; cnt = 1 ; 
               first = lk[j];
           }      
       ans = max( cnt + 1 ,ans ) ;   
    }
    printf("%d\n",ans);
    return true;
}

int main()
{   
    while(can()) ;
    return 0;
}
     
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
