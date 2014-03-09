#include<stdio.h>
#include<stdlib.h>
#define size 1000002
char ch[size];
long s[size],e[size],m,test=0,len;
void DEAL_WITH()
{  long i,j,t,k,lent,ok,max;
   m=0;
   for(i=2;i<=len;i++)
   {  max=0;
      for(j=1;j<=m;j++)
      {  ok=1;
         lent=s[j]/e[j];
         if((s[j]+lent)!=i) continue;
         for(t=s[j]+1,k=1;t<=i;t++,k++)
         if(ch[t-1]!=ch[k-1]) {ok=0;break;}
         if(!ok) continue;
         if(max<i/lent) max=i/lent;
      }
     if(max) 
     {  ++m;
        s[m]=i;
        e[m]=max;
     }
     else  if(i%2)continue;
     else { t=i/2;
            ok=1;
            for(j=1,k=t+1;j<=t;j++,k++)
            if(ch[j-1]!=ch[k-1]) {ok=0;break;}
            if(ok) 
            { ++m;
              s[m]=i;
              e[m]=2;
            }  
          }
   }
   printf("Test case #%ld\n",++test);
   for(i=1;i<=m;i++)
   printf("%ld %ld\n",s[i],e[i]);
}                     
int main()
{  long i,j;
   scanf("%ld",&len);
   while(len)
   {  getchar();
      scanf("%s",ch);
      DEAL_WITH();
      printf("\n");
      scanf("%ld",&len);
   }
   //system("pause");
   return 0;
}      
      
  
