#include<stdlib.h>
#include<stdio.h>
typedef struct node{
long x,y,z;
}Node;
Node N[16];
int main()
{  long i,x,y,z,t,data,index;
   for(i=0;i<16;i++)
   scanf("%ld%ld%ld",&N[i].x,&N[i].y,&N[i].z);
   scanf("%ld%ld%ld",&x,&y,&z);
   while(x!=-1&&y!=-1&&z!=-1)
   {  t=100000000;
      for(i=0;i<16;i++)
      {  data=(N[i].x-x)*(N[i].x-x)+(N[i].y-y)*(N[i].y-y)+(N[i].z-z)*(N[i].z-z);
         if(t>data)
         {  t=data;
            index=i;
         }
      }
      printf("(%ld,%ld,%ld) maps to (%ld,%ld,%ld)\n",x,y,z,N[index].x,N[index].y,N[index].z);
      scanf("%ld%ld%ld",&x,&y,&z);
   }
   //system("pause");
   return 0;
}            
         
