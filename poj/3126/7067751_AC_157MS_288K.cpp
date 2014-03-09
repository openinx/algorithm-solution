#include<iostream>
#include<queue>
using namespace std;

const int _size = 10000;
int p[_size],ps;
bool visit[_size];

void init()
{    memset(visit,1,sizeof(visit));
     int i,j;
     for(i=2;i<_size;++i)
        if(visit[i])
          for(j=i<<1;j<_size;j+=i)
             visit[j]=0;
     for(i=1000,ps=0;i<_size;++i)
      if(visit[i]) p[ps++]=i;  
}

int ax[4],bx[4],as,bs;
bool isnext(int a,int b)
{    int i,j;
     for(i=0;a;a/=10)  ax[i++]=a%10;
     for(i=0;b;b/=10)  bx[i++]=b%10;
     for(i=0,j=0;i<4;++i) if(ax[i]!=bx[i]) ++j;
     return j==1 ;
} 

int status[_size];
int solve()
{   
    if(as==bs)  return 0;
    queue<int>q;
    int i,cur,son;
    memset(status,-1,sizeof(status));
    status[as]=0;
    q.push(as);
    while(!q.empty())
    {   
        cur=q.front();
        q.pop();
        for(i=0;i<ps;++i)
        {
              son=p[i];
              if(status[son]==-1&&isnext(cur,son))
              {   
                  status[son]=status[cur]+1;
                  if(son==bs)  return status[son];
                  q.push(son);
              }
        }
    }
    return -1;
} 
int main()
{   int T,ans;
    init();
    cin>>T;
    while(T--)
    {    
         cin>>as>>bs;
         ans=solve();
         if(ans==-1) cout<<"Impossible"<<endl;
         else cout<<ans<<endl;
    }
    return 0;
}
    
