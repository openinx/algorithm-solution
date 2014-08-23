#include<stdio.h>
int main()
{ float sum=0,a;
  int i;
  for(i=1;i<=12;i++)
  {  scanf("%f",&a);
     sum+=a;
  }   
  printf("$%0.2f\n",sum/(double)12);
  return 0;
}  
                          
