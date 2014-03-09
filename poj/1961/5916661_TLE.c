#include<stdio.h>
#include<stdlib.h>
#define size 1000002
char ch[size];
long s[size],e[size],m,test=0,len;
int compare(long starta,long startb,long lena)
{  long i,j,middle;
   if(lena<=20)
   {  for(i=starta,j=startb;i<=starta+lena-1;i++,j++)
      if(ch[i]!=ch[j]) return 0;
      return 1;
   }
   middle=lena/2;
   if(!compare(starta,startb,middle)) return 0;
   if(!compare(starta+middle,startb+middle,lena-middle)) return 0;
   return 1;
}   
void DEAL_WITH()
{  long i,j,t,k,lent,ok,max;
   m=0;
   for(i=2;i<=len;i++)
   {  max=0;
      for(j=1;j<=m;j++)
      {  lent=s[j]/e[j];
         if((s[j]+lent)!=i) continue;
         ok=compare(s[j],0,lent);
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
            ok=compare(t,0,t);
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
      
  
