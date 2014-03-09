#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define geshi "error!\n"
char translate(char k)
{ if((k<='9')&&(k>='0')) return k;
  if((k=='A')||(k=='B')||(k=='C'))  return '2';
  if((k=='D')||(k=='E')||(k=='F'))  return '3';
  if((k=='G')||(k=='H')||(k=='I'))  return '4';
  if((k=='J')||(k=='K')||(k=='L'))  return '5';
  if((k=='M')||(k=='N')||(k=='O'))  return '6';
  if((k=='P')||(k=='R')||(k=='S'))  return '7';
  if((k=='T')||(k=='U')||(k=='V'))  return '8';
  if((k=='W')||(k=='X')||(k=='Y'))  return '9';
}
int Strcmp(char*p,char*q)
{ int i,max=8;
   for(i=1;i<=max;i++)
    { if(p[i]>q[i]) return 1;
      if(p[i]<q[i]) return -1;
    }
   return 0;
}
int main()
{  int size;
   int i,j,count=0;
   char **p,ch,*mo=(char*)malloc(20*sizeof(char));
   scanf("%d",&size);
   if(getchar()=='\n')
   {
       p=(char**)malloc((size+1)*sizeof(char*));
        if(!p) printf(geshi);
         for(j=0;j<=size;j++)
        { p[j]=(char*)malloc(20*sizeof(char));
           if(!p[j])printf(geshi);
           p[j][0]=0;
         }
      for(i=0;i<=20;i++)
       p[0][i]='~';
      for(i=1;i<=size;i++)
       { count=1;
         while((ch=getchar())!='\n')
            {  if(ch=='-')continue;
               if(count==4){ p[i][count++]='-';}
               p[i][count++]=translate(ch);
             }
          p[i][count]='\0';
          p[i][0]++;
         for(j=1;j<i;j++)
          { if((!Strcmp(p[i],p[j]))&&p[j][0])
              {   p[j][0]++;
                  p[i][0]=0;
              }
          }

       }
       for(i=1;i<=size;i++)
       {  mo=p[0];
         for(j=1;j<=size;j++)
           if(p[j][0]&&(Strcmp(p[j],mo)<0))
             mo=p[j];
         if((mo[0]>1)&&mo[0]!='~')
         { for(j=1;j<=8;j++)
           printf("%c",mo[j]);
           printf(" %d\n",mo[0]-1);
         }
         mo[0]=0;
       }
  }
  for(i=0;i<=size;i++)
   free(p[i]);
   free(p);
  return 0;
}

