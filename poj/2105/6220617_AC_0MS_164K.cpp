#include<stdio.h>
#include<stdlib.h>
int c[4];
char s[35];
void DEAL()
{ int i,j,st,t;
  for(i=0;i<4;i++)
  {  st=8*i;
     t=1; c[i]=0;
     for(j=7+st;j>=st;j--)
     { c[i]+=t*(s[j]-'0'); 
       t*=2;
     }
  }
  printf("%d",c[0]);
  for(i=1;i<4;i++) printf(".%d",c[i]);
  printf("\n");
}       
     
int main()
{  int i,j,test_case;
   while(scanf("%d",&test_case)!=EOF)
   {  for(i=1;i<=test_case;i++)
      { scanf("%s",s);
        DEAL();
      }
   }
   //system("pause");
   return 0;
}      
         
   
