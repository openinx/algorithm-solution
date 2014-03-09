#include<stdio.h>
int main()
{ int a=0,n,i,k=6,j=0;
  char s[6];
  while(scanf("%s%d",s,&n)==2);
  for(i=0;i<6;i++)
  {
   if(s[i]!='.') 
   {if(j==0)
    a=s[i]*10^(5-i)+a;
    if(j==1)
    a=s[i]*10^(6-i)+a; 
    }   
   else {j=1;k=i;}
   }
  a=a^n;
  if(k==2) printf(".%d\n",a);
  if(k==6) printf（"%d\n",a);
  if(k<6&&k>2)
  printf("%f\n",((float)a)/10^(n*(5-k)));
  return 0;
}