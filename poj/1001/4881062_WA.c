#include<stdio.h>
int main()
{ int wen ( int a,int n);
  int a=0,n,i,k=6,j=0,t;
  char s[6];
  while(scanf("%s%d",s,&n)==2);
  for(i=0;i<6;i++)
  {
   if(s[i]!='.') 
   {if(j==0)
    a=s[i]*wen(10,5-i)+a;
    if(j==1)
    a=s[i]*wen(10,6-i)+a; 
    }   
   else {j=1;k=i;}
   }
  a=wen(a,n);
  if(k==1) printf(".%d\n",a);
  if(k==6) printf("%d\n",a);
  if(k<6&&k>1)
    {t=a/wen(10,n*(5-k)); 
     printf("%d.%d\n",t,a-t);
     }   
    return 0;
}
  int wen(int a,int n)
{  int i,d=1;
  for(i=1;i<=n;i++)
  d=d*a;
  return d;
 }