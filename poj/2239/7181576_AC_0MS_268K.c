#include<stdio.h>
#define maxn 305

int nx,ny;
int mx[maxn],my[maxn],fy[maxn];
int g[maxn][maxn];

int find(int v)
{   
    int w;
    for( w = 1 ; w <=ny; ++w)
      if(g[v][w] && fy[w]<0 )
      {    
           fy[w] = 1;
           if( my[w] < 0 || find(my[w]))
           {    mx[v] = w; my[w] = v;  return 1;  }
      }
    return 0;
}

int MaxMatch()
{
   int i,j,ans=0;
   for(i=1 ;i <= nx; ++i) mx[i] = -1;
   for(j=1 ;j <= ny; ++j) my[j] = -1;
   for(i=1; i <= nx;++i)
     if(mx[i] < 0)
     {
        for(j=1;j<=ny;++j)  fy[j]=-1;
        ans += find(i);
     }
   return ans;
}

int main()
{      
       int i,j,p,q,c;
       while(scanf("%d",&ny)!=EOF)
       {     
             nx = 7*12;
             for(i=1;i<=nx;++i)
                for(j=1;j<=ny;++j)
                g[i][j] = 0;
             for(i=1; i<=ny; ++i)
             {    
                  scanf("%d",&c);
                  while(c--)
                  {
                     scanf("%d%d",&p,&q);  g[(p-1)*12 + q][i]=1;
                  }
             }
             printf("%d\n",MaxMatch());
       }
       return 0;
}   

