#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 50
int a[size][size],n;
void SH(int na,int&x,int &y)
{ int i,j;
  for(i=0;i<n;i++)
  {  for(j=1;j<=a[i][0];j++)
     if(a[i][j]==na)
     {  x=i;
        y=j;
        return;
     }   
  }
} 
void Back(int t)
{  int i,u=a[t][0];
   a[t][0]++;
   for(i=u;i>=1;i--) a[t][i+1]=a[t][i];
   a[t][1]=t;
}
void move_onto(int na,int nb)
{  int i,j,xa,ya,xb,yb;
   SH(na,xa,ya);
   SH(nb,xb,yb);
   if(xa==xb) return;
   for(i=ya+1;i<=a[xa][0];i++)
   Back(a[xa][i]);
   a[xa][0]=ya-1;
   for(i=yb+1;i<=a[xb][0];i++)
   Back(a[xb][i]);
   a[xb][0]=yb+1;
   a[xb][a[xb][0]]=na;
}   
void move_over(int na,int nb)
{ int i,j,xa,ya,xb,yb;
  SH(na,xa,ya);
  SH(nb,xb,yb);
  if(xa==xb) return;
  for(i=ya+1;i<=a[xa][0];i++)
  Back(a[xa][i]);
  a[xa][0]=ya-1;
  a[xb][0]++;
  a[xb][a[xb][0]]=na;
}
void pile_onto(int na,int nb)
{  int i,j,xa,ya,xb,yb;
   SH(nb,xb,yb);
   SH(na,xa,ya);
   if(xa==xb) return;
   for(i=yb+1;i<=a[xb][0];i++)
   Back(a[xb][i]);
   a[xb][0]=yb;
   for(i=ya;i<=a[xa][0];i++)
   {  ++a[xb][0];
      a[xb][a[xb][0]]=a[xa][i];
   }
   a[xa][0]=ya-1;
}
void pile_over(int na,int nb)
{  int i,j,xa,ya,xb,yb;
   SH(na,xa,ya);
   SH(nb,xb,yb);
   if(xb==xa) return;
   for(i=ya;i<=a[xa][0];i++)
   {  ++a[xb][0];
      a[xb][a[xb][0]]=a[xa][i];
   }
   a[xa][0]=ya-1;
}           
void output()
{  int i,j;
   for(i=0;i<n;i++)
   {  printf("%d:",i);
      if(!a[i][0]) printf("\n");
      else 
      {  for(j=1;j<=a[i][0];j++)
         printf(" %d",a[i][j]);
         printf("\n");
      }
   }
}
int main()
{  int i,j,na,nb;
   char s1[20],s2[20];
   while(scanf("%d",&n)!=EOF)
   {  for(i=0;i<n;i++) 
      {  a[i][0]=1;
         a[i][1]=i;
      }
      scanf("%s",s1);
      while(strcmp("quit",s1))
      {  scanf("%d%s%d",&na,s2,&nb);
         if(!strcmp("move",s1))
         {  if(!strcmp("onto",s2)) move_onto(na,nb);
            else move_over(na,nb);
         }
         else 
         {  if(!strcmp("onto",s2)) pile_onto(na,nb);
            else pile_over(na,nb);
         }
         scanf("%s",s1);
      }
      output();
    }
    return 0;
}                                    
   
   
