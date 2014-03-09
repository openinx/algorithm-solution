#include<stdio.h>
#include<stdlib.h>
#define  size 1000002
bool s[2*size];
int main()
{  long i,j,n,a,b;
   while(scanf("%ld",&n)!=EOF)
   { for(i=1;i<size;i++) s[i]=false; 
     for(i=1;i<=n;i++)
      {  scanf("%ld%ld",&a,&b);
         for(j=2*a;j<=2*b;j++)
         s[j]=true;
      }
     a=2;
     for(j=3;j<2*size;j++)
     {  if(s[j]==s[a]) continue;
        else 
        { b=j-1;
          if(s[a]) printf("%ld %ld\n",a/2,b/2);
          a=j;
        }
     }
     //for(i=1;i<=10;i++) printf("%d",s[i]);
   }
   //system("pause");
   return 0;
}               
