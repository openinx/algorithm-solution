#include<iostream>
using namespace std;

const int maxn = 205;

int g[maxn][maxn];
int mx[maxn],my[maxn],fy[maxn];
int nx,ny;


int find(int v)
{   
    int i;
    for(i=1;i<=ny;++i)
        if(g[v][i] && !fy[i]) // i不在交错树上 
        {   
            fy[i]=1;          // 设为在交错树上 
            if(!my[i] || find(my[i]))    // i为未盖点或者通过i点找到增广路 
            {    mx[v]=i; my[i]=v; return 1;}
        }
    return 0;
}


int MaxMatch()
{   
    int i,ans=0;
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    for(i=1;i<=nx;++i)
      if(!mx[i])
      {    
           memset(fy,0,sizeof(fy));
           ans+=find(i);
      }
    //for(i=1;i<=nx;++i)
   //   cout<<i<<"---->"<<mx[i]<<endl;
    return ans;
}

int main()
{   
    int edge,i,j,cas=0,x,y;
    while(scanf("%d%d%d",&nx,&ny,&edge)!=EOF)
    {   
        if(nx==0 && ny==0 &&edge==0) break;
        memset(g,1,sizeof(g));
        for(i=1;i<=edge;++i)
        {    
             scanf("%d%d",&x,&y);
             g[x][y]=0;
        }
        printf("Case %d: %d\n",++cas,nx+ny-MaxMatch());
    }
    return 0;
}
                 
