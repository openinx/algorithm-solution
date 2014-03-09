#include<stdio.h>
#include<math.h>
int main()
{  double c,len;
   int i;
   scanf("%lf",&c);
   while(c){  len=0;
              i=1;
              while(len<c) len+=(double)1/(double)(++i); 
              printf("%d card(s)\n",i-1);
              scanf("%lf",&c);
            }
   return 0;
}              