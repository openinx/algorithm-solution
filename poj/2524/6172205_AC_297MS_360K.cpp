#include<stdlib.h>
#include<stdio.h>
#define size 50002
long N,M,s[size];
long Find_parent(long t)
{  long j,u;
   for(u=t;s[u]>0;u=s[u]);
   for(j=t;j!=u;j=s[j]) s[j]=u;
   return u;
}   
void Union(long i,long j)
{  if(s[i]>s[j])
   {  s[j]+=s[i];
      s[i]=j;
   }
   else 
   {  s[i]+=s[j];
      s[j]=i;
   }
} 
void output()
{ long i;
  for(i=1;i<=N;i++)
  printf("%ld ",s[i]);
  printf("\n");
}        
int main()
{  long a,b,a1,b1,i,count,test=0;
   scanf("%ld%ld",&N,&M);
   while(N&&M)
   { for(i=1;i<=N;i++) s[i]=-1;
     for(i=1;i<=M;i++)
     {
       scanf("%ld%ld",&a,&b);
       a1=Find_parent(a);
       b1=Find_parent(b);
       if(a1!=b1) Union(a1,b1);
     }
     //output();
     count=0;
     for(i=1;i<=N;i++)
     if(s[i]<0) count++;
     printf("Case %ld: %ld\n",++test,count);
     scanf("%ld%ld",&N,&M);
  } 
  //system("pause");
  return 0;
}     
      
       
   
   
   
