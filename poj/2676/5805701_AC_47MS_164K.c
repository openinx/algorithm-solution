#include<stdio.h>
//#include<stdlib.h>
#include<math.h>
#define size 82
typedef struct node{
int x,y;
}Node;
Node un[size];
int posx[10]={0,1,1,1,4,4,4,7,7,7},
    posy[10]={0,1,4,7,1,4,7,1,4,7};
int unfinish,map[size][size];
int place(int t)
{  int i,j,index,wait;
   wait=map[un[t].x][un[t].y];
   for(i=1;i<=9;i++)
   if(un[t].x>=posx[i]&&un[t].y>=posy[i]&&
           un[t].x<posx[i]+3&&un[t].y<posy[i]+3) break;
   index=i;
   for(i=posx[index];i<posx[index]+3;i++)
     for(j=posy[index];j<posy[index]+3;j++)
     if((!map[i][j])||((i==un[t].x)&&(j==un[t].y))) continue;
     else if(map[i][j]==wait) return 0;
   for(i=1;i<=9;i++)
   { if((i!=un[t].x)&&(map[i][un[t].y]==wait)) return 0;
     if((i!=un[t].y)&&(map[un[t].x][i]==wait)) return 0;
   }
   return 1;
}     
int DFS(int t)
{  int i,j;
   if(t>unfinish){ for(i=1;i<=9;i++)
                    {  for(j=1;j<=9;j++)
                       printf("%d",map[i][j]);
                       printf("\n");
                    }
                    return 1;
                 }         
   for(i=1;i<=9;i++)
   {  map[un[t].x][un[t].y]=i;
      if(place(t)) 
         if(DFS(t+1)) return 1;
      map[un[t].x][un[t].y]=0;
   }
   return 0;
}   
int main()
{  int i,j,max,t;
   char cc;
   scanf("%d",&max);
   getchar();
   for(t=1;t<=max;t++)
   {  unfinish=0;
      for(i=1;i<=9;i++)
      {  for(j=1;j<=9;j++)
         { scanf("%c",&cc);
           map[i][j]=cc-'0';
         }
         getchar();
      }
      for(i=9;i>=1;i--)
        for(j=9;j>=1;j--)
        if(!map[i][j]) { ++unfinish;
                         un[unfinish].x=i;
                         un[unfinish].y=j;
                        }  
      if(DFS(1));
  }
  //system("pause");
  return 0;
} 
