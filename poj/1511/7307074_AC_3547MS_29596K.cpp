#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 2000005;
const __int64 maxt = 2000000000;
typedef __int64 i64; 
struct node {
       int x,y;
       i64 w;
};
struct qnode{
       int x;
       i64 w;
       qnode(int _x,i64 _w): x(_x),w(_w) {}
};
node  Edge[maxn];
int N,E;
int index[maxn] ;
i64 d[maxn];
bool vis[maxn];

bool cmp(node a,node b)
{    
     return a.x < b.x;
}

bool operator < ( qnode a,qnode b )
{    
     return a.w > b.w ;
}

void makeindex()
{   
    int i,j;
    index[0] = 0;
    j = 1;
    for(i = 1;i<=N;++i) 
    {   
        for( ; j<=E && Edge[j].x == i ; ++j);
        index[i] = j-1 ; 
    }
}

i64 dijistra()
{   
    int i,j,cv,nv,sv;
    priority_queue<qnode> q;
    for(i=1;i<=N;++i) d[i] = maxt;
    memset(vis, 0, sizeof(vis));
    d[1] = 0; vis[1]=1 ; q.push(qnode(1,0));
    for( i = 1,cv = 1 ; i< N ; ++i)
    {     
          for(nv = index[cv-1]+1 ; nv <=index[cv] ; nv++)
          {   
              sv = Edge[nv].y;
              if( d[sv] > d[cv] + Edge[nv].w )
              {    
                  d[sv] = d[cv] + Edge[nv].w;
                  q.push(qnode(sv,d[sv])); 
              }
          }
          while(!q.empty() && vis[(q.top()).x]==1) q.pop();
          if(q.empty()) break;
          cv = (q.top()).x  ;  q.pop();
          //cout<<"current point :"<<cv<<endl;
          //system("pause");
          vis[cv] = 1;
    }
    i64 ans = 0;
    for(i = 1;i<=N;++i)
    { 
          ans += d[i];
    }
    return ans;
}

void show()
{   
    int i;
    for(i=1;i<=E;++i) cout<<Edge[i].x<<"---->"<<Edge[i].y<<"  weight  "<<Edge[i].w<<endl;
}
    

int main()
{    
     int i,casen;
     i64 ans;
     scanf("%d",&casen);
     while(casen--)
     {       
             ans = 0;
             scanf("%d%d",&N,&E); 
             for(i=1;i<=E;++i) 
                  scanf("%d%d%I64d",&Edge[i].x,&Edge[i].y,&Edge[i].w);
             sort(Edge+1,Edge+E+1,cmp);
             makeindex();
             ans +=dijistra();
             
             for(i=1;i<=E;++i)  swap(Edge[i].x, Edge[i].y);
             
             sort(Edge+1,Edge+E+1,cmp);
             makeindex();
             ans +=dijistra();
             printf("%I64d\n",ans);
     }
     return 0;
}     



