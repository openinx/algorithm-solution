#include<iostream>
using namespace std;
#define maxn 21
#define minint -(1<<30)

int   d[maxn][maxn][maxn];

int dp(int a,int b,int c)
{   
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20)  return dp(20,20,20);
    if(d[a][b][c]!=minint) return d[a][b][c];
    if(a<b&&b<c)  
           d[a][b][c]=dp(a,b,c-1)+dp(a,b-1,c-1)-dp(a,b-1,c);
    else d[a][b][c]=dp(a-1,b,c)+dp(a-1,b-1,c)+dp(a-1,b,c-1)-dp(a-1,b-1,c-1);
    return d[a][b][c];
}


int main()
{    
     int a,b,c,i,j,k;
     for(i=0;i<maxn;++i)
        for(j=0;j<maxn;++j)
          for(k=0;k<maxn;++k)
           d[i][j][k]=minint;
     while(scanf("%d%d%d",&a,&b,&c)!=EOF)
     {     
           if(a==-1&&b==-1&&c==-1) break;
           printf("w(%d, %d, %d) = %d\n",a,b,c,dp(a,b,c));
     }
     return 0;
}
