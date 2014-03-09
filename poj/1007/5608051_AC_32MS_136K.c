#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 51
#define Maxlen 101
typedef struct{
char str[Maxsize];
int count;
}Node;
Node N[Maxlen];
void sort(int n)
{  int i,j;
   Node e;
   for(i=1;i<n;i++)
     for(j=1;j<=n-i;j++)
     if(N[j].count>N[j+1].count)
     {  e=N[j];
        N[j]=N[j+1];
        N[j+1]=e;
     }
}   
int main()
{  int i,j,k,n,len,t;
   char ch;
   scanf("%d%d",&len,&n);
   getchar();
   for(i=1;i<=n;i++)
   {    k=-1;
        N[i].count=0;
        while((ch=getchar())!='\n')
        {  N[i].str[++k]=ch;
           for(t=0;t<k;t++)
           if(N[i].str[t]>N[i].str[k])
           N[i].count++;
        }
        N[i].str[++k]='\0';
   }
   sort(n);
   for(i=1;i<=n;i++)
   puts(N[i].str);
   //system("pause");
   return 0;
}  

























           
