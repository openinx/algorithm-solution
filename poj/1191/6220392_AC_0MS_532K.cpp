#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define inf 100000000
long d[9][9][9][9][16];
long m[9][9];
long MIN(long x,long y)
{  return((x<y)? x:y);}
void Init()
{  long i,j,k,l,x,y,t;
   for(i=1;i<=8;i++)
    for(j=1;j<=8;j++)
     for(k=i;k<=8;k++)
      for(l=j;l<=8;l++)
    {  t=0;
       for(x=i;x<=k;x++)
         for(y=j;y<=l;y++) t+=m[x][y];
      d[i][j][k][l][0]=t*t;   
    }
}
long DP(long sx,long sy,long ex,long ey,long n)
{ long min=inf,u,v,x,y; 
  if(d[sx][sy][ex][ey][n]!=-1) return d[sx][sy][ex][ey][n];
  for(u=sx;u<ex;u++)
  { x=DP(sx,sy,u,ey,n-1);
    y=DP(u+1,sy,ex,ey,n-1);
    min=MIN(min,x+d[u+1][sy][ex][ey][0]);
    min=MIN(min,y+d[sx][sy][u][ey][0]);
  }
  for(v=sy;v<ey;v++)
  {  x=DP(sx,sy,ex,v,n-1);
     y=DP(sx,v+1,ex,ey,n-1);
     min=MIN(min,x+d[sx][v+1][ex][ey][0]);
     min=MIN(min,y+d[sx][sy][ex][v][0]);
  }
  d[sx][sy][ex][ey][n]=min;
  return min;
}       
int main()
{  long i,j,step,sum,data,x,y,u,v;
   double result,r;
   while(scanf("%ld",&step)!=EOF)
   { sum=0;
     for(i=1;i<=8;i++)
      for(j=1;j<=8;j++)
        for(x=1;x<=8;x++)
         for(y=1;y<=8;y++)
          for(u=1;u<=step;u++)
     d[i][j][x][y][u]=-1;
     for(i=1;i<=8;i++)
      for(j=1;j<=8;j++)
      { scanf("%ld",&m[i][j]); 
        sum+=m[i][j];
      }
      result=double(sum); r=double(step);
      result=(-1)*sum/r*sum/r;   
      Init();
      data=DP(1,1,8,8,step-1);
      result=sqrt(result+(double)data/r);
      printf("%0.3f\n",result);
   }
   //system("pause");
   return 0;
}       
   
