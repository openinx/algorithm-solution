#include<stdio.h>
//#include<stdlib.h>
int main()
{  int i,k,a,b,c,d,j=0;
   scanf("%d%d%d%d",&a,&b,&c,&d);
   while((a!=-1)&&(b!=-1)&&(c!=-1)&&(d!=-1))
   {  a=a%23;
      b=b%28;
      c=c%33;
      for(i=1;i<=23*28;i++)
      {  k=33*i+c;     
         if((k>d))     
             if((k%23==a)&&(k%28==b))
             break;
      }
      printf("Case %d: the next triple peak occurs in %d days.\n",++j,k-d);
      scanf("%d%d%d%d",&a,&b,&c,&d);
   }       
   //system("pause");
   return 0;
}   
