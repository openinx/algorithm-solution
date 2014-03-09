#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{  long count,i,j,x,y,m,n;
   while(scanf("%ld",&count)!=EOF)
   {  if(count==1) 
      { printf("TERM %ld IS %ld/%ld\n",count,1,1);
        continue;
      }
      i=long((1+sqrt(8*(double)count-7))/2);
      m=i*(i+1)/2;
      n=(i-1)*i/2;
      if(count>m) i++;
      j=count-n-1;
      if(!(i%2))
      {  x=1;
         y=i;
         x+=j;
         y-=j;
      }
      else 
      { x=i;
        y=1;
        x-=j;
        y+=j;
      }
      printf("TERM %ld IS %ld/%ld\n",count,x,y);
  }
  //system("pause");
  return 0;
}       
           
         
         
           
