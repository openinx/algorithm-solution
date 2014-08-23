#include <iostream>
using namespace std;
int x_len,y_len;
int num[100][100];
int flag[100][100]; 
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

int access(int x,int y)
{
    int k,temp;
    int max=0;
    if(flag[x][y]!=-1) return flag[x][y]; 
    for(k=0;k<4;k++)
    {
       if(x+xx[k]>=x_len||x+xx[k]<0) continue; 
       if(y+yy[k]>=y_len||y+yy[k]<0) continue;
       if(num[x+xx[k]][y+yy[k]]>=num[x][y]) continue;
       temp=access(x+xx[k],y+yy[k]);
       if(temp>max) max=temp;
    }
    flag[x][y]=max+1;
    return flag[x][y];
}

int main()
{
    int i,j;
    int lenth=0,t;
    cin>>x_len>>y_len;
    for(i=0;i<x_len;i++)
       for(j=0;j<y_len;j++)
          {
             cin>>num[i][j];
             flag[i][j]=-1;
          }
    for(i=0;i<x_len;i++)
       for(j=0;j<y_len;j++)
          {
             t=access(i,j);
             if(lenth<t) lenth=t;
          }
    cout<<lenth;
    
    return 0;
}

