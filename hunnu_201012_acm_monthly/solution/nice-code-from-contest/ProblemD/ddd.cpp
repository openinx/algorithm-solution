#include<iostream>
using namespace std;

int step[1001][1001];
char map[1001][1001];

int main()
{
    int t,n,m,k,tx,ty,jx,jy;
    cin>>t;
    while (t--)
    {
          cin>>n>>m>>k;
          for (int i=0;i<n;i++)cin>>map[i];
          
          for (int i=0;i<1000;i++)
              for (int j=0;j<1000;j++)
              {
                  step[i][j]=-1;
                  if (map[i][j]=='T'){tx=i; ty=j;}
                  if (map[i][j]=='J'){jx=i; jy=j;}
              }
              
          step[tx][ty]=0;
          int now=0;
          for (int haschanged=1;haschanged==1;)
          {
              haschanged=0;
              for (int i=0;i<n;i++)
                  for (int j=0;j<m;j++)
                  {
                      if (step[i][j]==now)
                      {
                         if (i>0&&map[i-1][j]!='*'&&step[i-1][j]==-1){step[i-1][j]=now+1; haschanged=1;}
                         if (j>0&&map[i][j-1]!='*'&&step[i][j-1]==-1){step[i][j-1]=now+1; haschanged=1;}
                         if (i<n-1&&map[i+1][j]!='*'&&step[i+1][j]==-1){step[i+1][j]=now+1; haschanged=1;}
                         if (j<m-1&&map[i][j+1]!='*'&&step[i][j+1]==-1){step[i][j+1]=now+1; haschanged=1;}                 
                      }
                  }
              now++;
          }
          /*
          for (int i=0;i<n;i++)
          {
              for (int j=0;j<m;j++)
              {
                  cout<<step[i][j]<<" ";
              }
              cout<<endl;
          }
          */
          int ttime=0,flag=0,tmp;
          //cout<<"now position:"<<jx<<"  "<<jy<<endl;
          for (;ttime<k;ttime++)
          {
              cin>>tmp;
              if (tmp==0&&jx<n-1&&map[jx+1][jy]!='*'){jx++;}
              else if (tmp==1&&jy<m-1&&map[jx][jy+1]!='*'){jy++;}
              else if (tmp==2&&jx>0&&map[jx-1][jy]!='*'){jx--;}
              else if (tmp==3&&jy>0&&map[jx][jy-1]!='*'){jy--;}
              //cout<<"now position:"<<jx<<"  "<<jy<<endl;
              if (step[jx][jy]!=-1 && ttime+1==step[jx][jy]){flag=1;}
          }
          if (flag==1)cout<<"Yes"<<endl;
          else cout<<"No"<<endl; 
    }
    return 0;
}

