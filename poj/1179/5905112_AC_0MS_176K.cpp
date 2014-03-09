#include<stdio.h>
#include<stdlib.h>
#define size 51
int v[size],n,m[size][size][2];
char e[size];
int min(int a,int b)
{ return((a<b)? a:b);}
int max(int a,int b)
{ return ((a>b)? a:b);}
void search(int i,int s,int j,int &mint,int &maxt)
{  int k=(i+s-1)%n+1;
   int a,b,c,d,q,p;
   a=m[i][s][0];
   b=m[k][j-s][0];
   c=m[i][s][1];
   d=m[k][j-s][1];
   if(e[k]=='t')
   {  mint=a+b;
      maxt=c+d;
   }
   else 
   { p=max(a*b,a*d);
     q=max(c*b,c*d);
     maxt=max(p,q);
     p=min(a*b,a*d);
     q=min(c*b,c*d);
     mint=min(q,p);
   }
}     
void Min_score()
{ int i,j,k,mint,maxt,s,MAX;
  for(i=1;i<=n;i++) m[i][1][0]=m[i][1][1]=v[i];
  for(j=2;j<=n;j++)
    for(i=1;i<=n;i++)
    { m[i][j][1]=-20000;
      m[i][j][0]=20000;
      for(s=1;s<j;s++)
      {   search(i,s,j,mint,maxt);
          if(m[i][j][1]<maxt) m[i][j][1]=maxt;
          if(m[i][j][0]>mint) m[i][j][0]=mint;
      }
    }
  MAX=-3000;
  for(i=1;i<=n;i++)
  {if(m[i][n][1]>MAX) MAX=m[i][n][1];
   //printf("%d\n",m[i][n][1]);
  } 
  printf("%d\n",MAX);
  for(i=1;i<=n;i++)
  if(m[i][n][1]==MAX)
  printf("%d ",i);
  printf("\n");
}         
int main()
{  int i,j;
   char c;
   while(scanf("%d",&n)!=EOF)
   {  getchar();
      for(i=1;i<=n;i++)
      { while((c=getchar())==' ');
        e[i]=c;
        scanf("%d",&v[i]);
      }
      Min_score();
   }
  // system("pause");
   return 0;
}          
