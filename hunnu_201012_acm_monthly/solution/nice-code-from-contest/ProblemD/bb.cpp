#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int maxn=110;
int n,m,k;
string map[maxn];
int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool judge(int x,int y)
{
     if(x<0||x>=n||y<0||y>=m||map[x][y]=='*')   return false;
     return true;
}
struct point 
{
       int x;
       int y;
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[maxn][maxn];
        int b[maxn][maxn];
        int step[maxn*maxn];
        cin>>n>>m>>k;
        int i,j;
        int tx,ty;
        int jx,jy;
        getchar();
        for(i=0;i<n;i++)
        {
             cin>>map[i];
             for(j=0;j<m;j++)
             {
                 if(map[i][j]=='T')     {tx=i;ty=j;}
                 else   if(map[i][j]=='J')          {jx=i;jy=j;}
             }
             getchar();
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",step+i);
        }
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        map[tx][ty]='.';
        queue<point> coll;
        point p;
        int x=jx,y=jy;
        int count=0;
        a[jx][jy]=0;
        for(i=0;i<k;i++)
        {
             switch(step[i])
             {
                case 0:
                     {
                            x++;
                            break;
                     }
                case 1:
                     {
                            y++;
                            break;
                     }
                case 2:
                     {
                            x--;
                            break;
                     }
                case 3:
                     {
                            y--;
                            break;
                     }
             }
             a[x][y]=i+1;
        }
        while(!coll.empty()){coll.pop();}
        map[jx][jy]='.';
        p.x=tx;
        p.y=ty;
        coll.push(p);
        count=0;
        b[tx][ty]=0;
        while(!coll.empty()&&(count<k))
        {
              point p1=coll.front();
              coll.pop();
              count=b[p1.x][p1.y]+1;
              for(i=0;i<4;i++)
              {
                point p2;
                p2.x=p1.x+move[i][0];
                p2.y=p1.y+move[i][1];
                if(judge(p2.x,p2.y)&&(b[p2.x][p2.y]==-1))    
                {
                     coll.push(p2);
                     b[p2.x][p2.y]=b[p1.x][p1.y]+1;
                }
              }
        }
        int a1=a[x][y],a2=b[x][y];
        if((a1!=-1)&&(a2!=-1)&&(a1&1)==(a2&1)&&min(a1,a2)+abs(a1-a2)<=k)
              cout<<"Yes"<<endl;
        else                      cout<<"No"<<endl;
    }
   // system("pause");
    return 0;
}

