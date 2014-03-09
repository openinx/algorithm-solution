#include<stdio.h>
#include<string.h>
char a[300],b[300],c[300],d[300],e[300];
void contact(char *s1,char *s2,char *s12)
{  int len1=strlen(s1);
   int i,j;
   for(i=0;i<len1;i++)
   s12[i]=s1[i];
   for(i=len1;i<2*len1;i++)
   s12[i]=s2[i-len1];
   s12[2*len1]='\0';
   return ;
}
void shuffle(char *s1,char *s2,char *s12)
{  int len1=strlen(s1);
   int i,j;
   for(i=0;i<len1;i++)
   s12[2*i]=s2[i];
   for(i=0;i<len1;i++)
   s12[2*i+1]=s1[i];
   s12[2*len1]='\0';
   return ;
}
void binary(char *s1,char *s2,char *s12)
{  int i,len=strlen(s12),len1;
   len1=len/2;
   for(i=0;i<len1;i++)
   s1[i]=s12[i];
   for(i=0;i<len1;i++)
   s2[i]=s12[i+len1];
   s1[len1]=s2[len1]='\0';
   return ;
}
int count_shuffle(char*s1,char *s2,char *end)
{ char *start,*s12;
  int sum=0;
  start=d;
  s12=c;
  contact(s1,s2,start);
  shuffle(s1,s2,s12);
  sum++;
  do{
     if(!strcmp(s12,end))  return sum;
     binary(s1,s2,s12);
     shuffle(s1,s2,s12);
     sum++;
     }while(strcmp(s12,start));
  if(!strcmp(s12,end)) return  sum;
  return -1;
}
int main()
{  char *s1,*s2,*end;
   int size,i,j,len;
   s1=a;
   s2=b;
   end=e;
   scanf("%d",&size);
   for(i=0;i<size;i++)
   {  scanf("%d",&len);
      getchar();
      for(j=0;j<len;j++)
      scanf("%c",&s1[j]);
      getchar();
      for(j=0;j<len;j++)
      scanf("%c",&s2[j]);
      getchar();
      for(j=0;j<2*len;j++)
      scanf("%c",&end[j]);
      s1[len]=s2[len]=end[2*len]='\0';
      printf("%d %d\n",i+1,count_shuffle(s1,s2,end));
   }
    return 0;
}




