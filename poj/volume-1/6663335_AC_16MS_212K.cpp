#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b)((a)>(b) ? (a):(b))
#define size 105
char gene[5]="ACGT";
int  a[6][6]={{5,-1,-2,-1,-3},
              {-1,5,-3,-2,-4},
              {-2,-3,5,-2,-2},
              {-1,-2,-2,5,-1},
              {-3,-4,-2,-1,0}
              };
int m[size][size] ;
int find(char c)
{    for(int i=0;i<4;++i) 
       if(c==gene[i]) return i;
} 
int main()
{   char si[size],sj[size];
    int t,i,j,ni,nj,x,y,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--)
    {   scanf("%d%s%d%s",&ni,si,&nj,sj);
        m[0][0]=0;
        for(j=1;j<=nj;++j) 
        {   y=find(sj[j-1]);
            x=4;
            m[0][j]=m[0][j-1]+a[x][y];
        }
        for(i=1;i<=ni;++i)
        {   x=find(si[i-1]);
            y=4;
            m[i][0]=m[i-1][0]+a[x][y];
        }
        for(i=1;i<=ni;++i)
          for(j=1;j<=nj;++j)
          {    x=find(si[i-1]);
               y=find(sj[j-1]);
               m[i][j]=MAX(MAX(m[i-1][j]+a[x][4],m[i][j-1]+a[4][y]),m[i-1][j-1]+a[x][y]);
          }
       printf("%d\n",m[ni][nj]);
    }
    //system("pause");
    return 0;
}              
               
                   
        
                             
