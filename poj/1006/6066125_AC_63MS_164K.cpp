#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{  int p,e,i,d,u,x,test=0;
   int j,k;
   scanf("%d%d%d%d",&p,&e,&i,&d);
   while(p!=-1&&e!=-1&&i!=-1&&d!=-1)
   {  p=p%23;
      e=e%28;
      i=i%33;
      for(j=1;j<=23;j++)
      if((j+d)%23==p%23) break;
      for(k=j+d;;k+=23)
      if(k%23==p%23)
       if(k%28==e%28)
         if(k%33==i%33)
         break;
     printf("Case %d: the next triple peak occurs in %d days.\n",++test,k-d);
   scanf("%d%d%d%d",&p,&e,&i,&d);
  }
  //system("pause");
  return 0;
}     
      
      
