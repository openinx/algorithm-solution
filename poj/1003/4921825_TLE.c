#include<stdio.h>
int main()
{
  int i;
  float a,k,d;
  while((scanf("%f",&a)!=0)&&a!=0)
 {     k=0.5;
    for(i=3;k<a;i++)   
    { d=1/i;k+=d;}
    printf("%d  card(s)\n",i-2);  
  }
} 