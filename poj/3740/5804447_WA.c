#include<stdio.h>
//#include<stdlib.h>
#define M 17
#define N 301
int main()
{  int i,j,k,r,c,count;
   int grid[M][N];
   while(scanf("%d%d",&r,&c)!=EOF)
   { for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        scanf("%d",&grid[i][j]);
     k=0;
     for(i=1;i<=c;i++)
     { if(k) break;
       count=0;
       for(j=1;j<=r;j++)
       if(grid[j][i]) count++;
       if(count==1) k=1;
     }
     if(k) printf("Yes, I found it\n");     
     else printf("It is impossible\n");
   }
   //system("pause");
   return 0;
}     
   
   
