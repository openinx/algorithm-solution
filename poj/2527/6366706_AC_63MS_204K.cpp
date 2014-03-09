#include<stdio.h>
#include<stdlib.h>
#define size 10005
int main()
{   long n,k,i,j,a[size];
    scanf("%ld%ld",&n,&k);
    while(n!=-1&&k!=-1)
    {  for(i=0;i<=n;++i)
       scanf("%ld",&a[i]);
       while(n>=k)
       {  a[n-k]-=a[n];
          a[n]=0;
          for(i=n;i>=0;--i)
          if(a[i]!=0)  break;
          n=i;
       }
       if(n==-1) printf("0\n");
       else 
       {   printf("%ld",a[0]);
           for(i=1;i<=n;++i)
           printf(" %ld",a[i]);
           printf("\n");
       }
       scanf("%ld%ld",&n,&k);
    }
    //system("pause");
    return 0;
}             
           
                 
