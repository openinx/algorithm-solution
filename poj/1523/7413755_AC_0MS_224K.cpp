#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
struct node{
       int v,next;
};

node e[maxn*maxn];
int es,N,idx, TestCase;
int gh[maxn],dfn[maxn],low[maxn],ans[maxn];


void ins(int vs,int vt)
{    
     e[es].v = vt ; e[es].next = gh[vs] ; gh[vs] = es ++;
}

bool Read()
{   
     int vs,vt;
     if(scanf("%d",&vs)==EOF || !vs) return false;
     N = es  = 0;
     memset(gh,-1,sizeof(gh));
     while(vs)
     {    
          scanf("%d",&vt);
          ins(vs,vt);  ins(vt,vs);
          N = max(max(vs,vt),N);
          scanf("%d",&vs);
     }
}

void dfs(int v)
{    
     int i,w;
     dfn[v] = low[v] = ++idx;
     for( i = gh[v] ; i!=-1 ; i=e[i].next)
     {    
           w = e[i].v;
           if(dfn[w]==0)  
           {   
               dfs(w);
               low[v] = min(low[v] , low[w]);
               if(low[w]>=dfn[v]) ans[v] ++ ;
           }
           else 
               low[v] = min(low[v] , dfn[w]);
     }
}


void can()
{    
     int i,check=0;
     idx = 0;
     memset(ans,0,sizeof(ans));
     memset(dfn,0,sizeof(dfn));
     dfs(1);
     cout<<"Network #"<<++TestCase<<endl;
     if(ans[1]>1) { cout<<"  SPF node "<<1<<" leaves "<<ans[1]<<" subnets"<<endl; check ++ ; }
     for(i=2;i<=N;++i)
       if(ans[i])
       {
         cout<<"  SPF node "<<i<<" leaves "<<ans[i]+1<<" subnets"<<endl;
         ++check;
       }
     if(!check)
       cout<<"  No SPF nodes"<<endl;
     cout<<endl;
}
      
int main()
{   
    TestCase = 0;
    while(Read()) can();
    return 0;
}



