#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int sx,sy,ex,ey;
int g[305][305],n;
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
typedef struct
{    int x,y;  }node;

bool out(node t)
{    return ((t.x<0)||(t.y<0)||(t.x>=n)||(t.y>=n));  }

int solve()
{    int i,j;
     if((sx==ex)&&(sy==ey)) return 0;
     for(i=0;i<n;++i)
       for(j=0;j<n;++j)  g[i][j]=-1;
     queue<node>q;
     node cur,son;
     cur.x=sx;
     cur.y=sy;
     g[sx][sy]=0;
     q.push(cur);
     while(!q.empty())
     {   
         cur=q.front();
         q.pop();
         for(i=0;i<8;++i)
         {    son.x=cur.x+dx[i];
              son.y=cur.y+dy[i];
              if(out(son)) continue;    
              if(g[son.x][son.y]!=-1) continue;
              g[son.x][son.y]=g[cur.x][cur.y]+1;
              if((son.x==ex)&&(son.y==ey)) return g[son.x][son.y];
              q.push(son);
         }
     }
}          
int main()
{   int testcase,i;
    scanf("%d",&testcase);
    while(testcase--)
    {   scanf("%d",&n);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("%d\n",solve());
    }
    //system("pause");
    return 0;
}        
