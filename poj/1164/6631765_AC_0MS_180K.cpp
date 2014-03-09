#include<stdio.h>
typedef struct 
{   bool d[4];  //0 left,1 up,2 right,3 down
    bool visit;
}module;
module g[55][55];
int n,m,count;
bool read()
{    if(scanf("%d%d",&n,&m)==EOF) return false;
     int i,j,d;
     for(i=1;i<=n;++i)
       for(j=1;j<=m;++j)
       {   scanf("%d",&d);
           g[i][j].visit=false;
           for(int k=0;k<4;k++)
           {  g[i][j].d[k]=false;
              if((1<<k)&d) g[i][j].d[k]=true;
           }   
       }
       return true;
}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};  //direction should be aware
bool OutOfBound(int cx,int cy)
{    if(cx<1||cx>n) return true;
     if(cy<1||cy>m) return  true;
     return false;
}                 
void dfs(int x,int y,int &area)
{    int i,cx,cy;
     for(i=0;i<4;i++)
     {   cx=x+dx[i];
         cy=y+dy[i];
         if(OutOfBound(cx,cy)) continue;
         if(g[cx][cy].visit) continue;
         if(g[x][y].d[i]) continue;
         area++;
         g[cx][cy].visit=true;
         dfs(cx,cy,area);
     }    
}              
void sovle()
{    int i,j,temp,max=0;
     count=0;
     for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       if(!g[i][j].visit)
       {  count++;
          g[i][j].visit=true;
          temp=1;
          dfs(i,j,temp);
          if(max<temp) max=temp;
       }
       printf("%d\n%d\n",count,max);
}           
int main()
{   while(read()) sovle();
    return 0;
}    
                  

    
