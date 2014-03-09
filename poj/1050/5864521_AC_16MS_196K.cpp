#include<stdio.h>
#include<stdlib.h>
#define size 101
long m[size][size],N;
long num[size];
long max(long a,long b)
{return ((a>b)? a:b);}
long maxsum(long n,long *b)
{ long i,t,temp;
  t=max(b[1],0);
  temp=-1;
  for(i=2;i<=n;i++)
  { t=max(t+b[i],0);
    if(t>temp) temp=t;
  }
  return temp;
}
long MaxMatrix(int n)
{  long i,j,*b,t,k,c;
   b=num;
   t=-1;
   for(i=1;i<=n;i++)
   { for(j=1;j<=n;j++) b[j]=0;
     for(j=i;j<=n;j++) 
     { for(k=1;k<=n;k++) b[k]+=m[j][k];
       c=maxsum(n,b);
       if(t<c) t=c;
     }
   }
   return t;
}       
int main()
{ long i,j;
  while(scanf("%ld",&N)!=EOF)
  {  for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
       scanf("%ld",&m[i][j]);
     printf("%ld\n",MaxMatrix(N));
  }
 // system("pause");
  return 0;
}     
     
     
        
  
  
