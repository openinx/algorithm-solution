#include<stdio.h>
#include<math.h>
#define pi 3.1415926
int main()
{  int i,size,t;
   double s,x,y,r,add;
   scanf("%d",&size);
   for(i=1;i<=size;i++)
   {  scanf("%lf%lf",&x,&y);
      r=sqrt(x*x+y*y);
      t=0;
      s=add=0;
      while(add<r)
      { s+=100;
        add=sqrt(s/pi);
        t++;
      }
      printf("Property %d: This property will begin eroding in year %d.\n",i,t);    
   }
   printf("END OF OUTPUT.\n");
   return 0;
}   
