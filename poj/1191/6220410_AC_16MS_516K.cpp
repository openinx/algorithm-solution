#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define inf 100000000
long d[9][9][9][9][15],data;
long m[9][9];
long MIN(long a,long b)
{  return(a>b? b:a);}
long dp(long x1,long y1,long x2,long y2,long k)
{ long i,a,b,min=inf,c; 
  if(d[x1][y1][x2][y2][k]!=-1) return d[x1][y1][x2][y2][k];
  for(a=x1;a<x2;a++)
  { b=dp(x1,y1,a,y2,k-1)+d[a+1][y1][x2][y2][0];
    c=d[x1][y1][a][y2][0]+dp(a+1,y1,x2,y2,k-1);
    min=MIN(c,MIN(b,min));
  }
  for(a=y1;a<y2;a++)
  { b=dp(x1,y1,x2,a,k-1)+d[x1][a+1][x2][y2][0];
    c=d[x1][y1][x2][a][0]+dp(x1,a+1,x2,y2,k-1);
    min=MIN(c,MIN(b,min));
  }
  d[x1][y1][x2][y2][k]=min;
  return min;
}         
int main()
{  long i,j,n,x,y,k,sum,t;
   double answer;
   while(scanf("%ld",&n)!=EOF&&n)
   { sum=0; 
     for(i=1;i<=8;i++)
       for(j=1;j<=8;j++)
       { scanf("%ld",&m[i][j]);
         sum+=m[i][j];
       }  
     for(i=1;i<=8;i++)
       for(j=1;j<=8;j++)
         for(x=1;x<=8;x++)
           for(y=1;y<=8;y++) 
            for(k=1;k<=n;k++)
    d[i][j][x][y][k]=-1;
    for(i=1;i<=8;i++)
      for(j=1;j<=8;j++)
       for(x=i;x<=8;x++)
        for(y=j;y<=8;y++)
        {  t=0;
           long ux,uy;
           for(ux=i;ux<=x;ux++)
            for(uy=j;uy<=y;uy++)
            t+=m[ux][uy];
          d[i][j][x][y][0]=t*t;
        }    
    data=dp(1,1,8,8,n-1);
    answer=sqrt((double)data/(double)n-((double)sum/(double)n)*((double)sum/(double)n));
    printf("%0.3f\n",answer);
  }
  //system("pause");
  return 0;
}
