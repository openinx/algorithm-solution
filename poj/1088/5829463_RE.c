#include<stdio.h>
#include<stdlib.h>
#define size 103
#define inf 2000
#define len 1009
int map[size][size];
int step[size][size];
typedef struct node{
int x,y,num;
}Node;
Node pos[len];
int xx[4]={1,0,-1,0},
    yy[4]={0,-1,0,1};
void sort(int r,int c)
{  int i,j,t=r*c,k=1;
   Node e;
  for(i=1;i<t;i++)
    for(j=1;j<=t-i;j++)
    if(pos[j+1].num<pos[j].num)
    {  e=pos[j];
       pos[j]=pos[j+1];
       pos[j+1]=e;
    }
}          
int main()
{  int i,j,r,c,x,y,k=1;
   int temp;
   scanf("%d%d",&r,&c);
   for(i=1;i<=r;i++)
     for(j=1;j<=c;j++)
     {scanf("%d",&map[i][j]);
      step[i][j]=1;
      pos[k].x=i;
      pos[k].y=j;
      pos[k].num=map[i][j];
      ++k;
     } 
   sort(r,c);  
   for(i=2;i<=r*c;i++)
   {  x=pos[i].x;
      y=pos[i].y;
      temp=0;
      for(j=0;j<4;j++)
      {  if(x+xx[j]>r||x+xx[j]<1||y+yy[j]>c||y+yy[j]<1) continue;
         if(map[x+xx[j]][y+yy[j]]<map[x][y])
            if(temp<step[x+xx[j]][y+yy[j]])
            temp=step[x+xx[j]][y+yy[j]];
      }
      step[x][y]=temp+1;
   }
   temp=-1;
   for(i=1;i<=r;i++)
     for(j=1;j<=c;j++)
     if(step[i][j]>temp)
     temp=step[i][j];
   printf("%d\n",temp);
   //system("pause");
   return 0;
}                     
         
