#include<stdio.h>
#include<stdlib.h>
#define size 1001
int m[size][size],r,c;
long b[size];
long MaxSub()
{  int i,j;
   long max=0,temp,count;
   for(i=1;i<=c;i++)
   {  if(!b[i]) continue;
      count=1;
      j=i-1;
      while((j>=1)&&(b[j]>=b[i]))
      { j--;
        count++;
      }
      j=i+1;
      while((j<=c)&&(b[j]>=b[i]))
      { j++;
        count++;
      }
      temp=count*b[i];
      if(max<temp) max=temp;
  }
  return max;
}
void output()
{  int i,j;
   for(i=1;i<=r;i++)
    { for(j=1;j<=c;j++)
      printf("%d ",m[i][j]);
      printf("\n");
    }
}        
long Max_rectangle()
{  int i,j;
   long max=0,temp;
   for(i=2;i<=r;i++)
     for(j=1;j<=c;j++)
     if(m[i][j]) m[i][j]+=m[i-1][j];
   //output();
   for(i=1;i<=r;i++)
   { for(j=1;j<=c;j++) b[j]=m[i][j];
     temp=MaxSub();
     if(max<temp)
     max=temp;
   }
   return max;
}                   
int main()
{ int i,j,test;
  char ch[4];
  scanf("%d",&test);
  while(test--)
  {  scanf("%d%d",&r,&c);
     for(i=1;i<=r;i++)
     { for(j=1;j<=c;j++)
       { scanf("%s",ch);
         if(ch[0]=='F') m[i][j]=1;
         else m[i][j]=0;
       }
     }
     printf("%ld\n",3*Max_rectangle());
  }
 // system("pause");
  return 0;
}
          
      
  
