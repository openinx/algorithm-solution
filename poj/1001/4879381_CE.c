#include<stdio.h>
int main()
{ int b=0,i,j,n ;
  float m;
  char c[6],d[6];
  while(scanf("%s%d",c,&n)==2);
  c[6]=0;
for(i=0;i<6;i++)
  { if(c[i]=='.')
   { k=i;
    for(j=k;j<6;j++)
    c[j]=c[j+1];
   } 
    break;
  } 
for(i=0;i<6;i++)
 b=c[i]*10^(5-i);
  m=b^n/10^(n*(5-k));
 printf("%f\n",m);
return 0;
}
      