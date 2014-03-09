#include<stdio.h>
#include<stdlib.h>
#define Int __int64
long f[221][11];
long a[11];
long DIVID(long n,long k)
{  Int i,j;
   for(i=0;i<=k;i++) f[0][i]=0;
   for(i=0;i<=n;i++) f[i][0]=0;
   for(i=1;i<=k;i++) f[1][i]=0;
   for(i=1;i<=n;i++) f[i][1]=1;
   for(i=2;i<=n;i++)
    for(j=2;j<=k;j++)
    if(i>=j)f[i][j]=f[i-j][j]+f[i-1][j-1];
    else f[i][j]=0;
  return f[n][k];
}
long key,sum,reminder,start,end,last,count;
void result(long m,long k,long rank)
{  long i;
   sum=0;
   a[0]=1;
   reminder=m;
   for(key=1;key<=k;key++)
   {  start=a[key-1];
      end=reminder/(k-key+1);
      for(i=start;i<=end;i++)
      { a[key]=i;
        last=reminder-a[key];
        last=last-(a[key]-1)*(k-key);
        count=DIVID(last,k-key);
        if(rank<=count+sum)
         if(rank>sum) break;
        sum+=count;
      }
      reminder-=a[key];
   }
   //printf("reminder:%ld\n",reminder);
}          
   
int main()
{  long i,j,m,k,rank,test;
   while(scanf("%ld",&test)!=EOF)
   {  for(i=1;i<=test;i++)
      { scanf("%ld%ld%ld",&m,&k,&rank);
        //printf("divid:%ld\n",DIVID(m,k));
        result(m,k,rank);
        for(j=1;j<=k;j++)
        printf("%ld\n",a[j]);
      }  
   }   
  // system("pause");
   return 0;
}   
