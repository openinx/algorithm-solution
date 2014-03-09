#include<iostream>
using namespace std;
const int maxn = 205;
double p[maxn][maxn];
double opt[maxn][maxn];
int n,tot;

inline double Max(double a,double b) {  return a > b ? a : b;}

double record(int x,int y,int l,int r)
{     
      if(opt[x][y]!= -1) return opt[x][y];
      if(x==0) {  opt[x][y] = 1.0 ; return 1.0; }
      int i,mid = ( l + r ) >>1;
      opt[x][y] = 0;
      if( y <= mid)
      {   
           for(i = mid + 1 ; i<=r ; ++i)
           {   
               opt[x-1][y] = record(x-1,y,l,mid);
               opt[x-1][i] = record(x-1,i,mid+1,r);
               opt[x][y] += opt[x-1][y] * opt[x-1][i] * p[y][i];
           }
      }
      else 
      {    
           for(i = l ; i<=mid ; ++i)
           {   
               opt[x-1][y] = record(x-1,y,mid+1,r);
               opt[x-1][i] = record(x-1,i,l,mid);
               opt[x][y] += opt[x-1][y] * opt[x-1][i] * p[y][i] ;
           }
      }
      return opt[x][y];
}
      
int main()
{    
     int i,j,best_i;
     double best,t;
     while(scanf("%d",&n)!=EOF && n!=-1)
     {     
           tot = 1<<n;
           for(i=1;i<=tot;++i)
             for(j=1;j<=tot;++j)
              scanf("%lf",&p[i][j]);
           for( i = 0 ; i<= tot ; ++i)
             for(j = 1;j<=tot;++j)
               opt[i][j] = -1;
               
           best = -1;
           for(i=1;i<=tot;++i)
           {
                t = record(n,i,1,tot);
                if(best < t) 
                {  
                   best = t ; best_i = i;
                }
           }
           printf("%d\n",best_i);
     }
     return 0;
}
