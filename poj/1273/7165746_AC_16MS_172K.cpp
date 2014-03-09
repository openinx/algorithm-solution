#include<iostream>
#include<queue>
using namespace std;

const  int   maxn = 205;
const  int   maxint = 1<<30;
inline int   Min(int x,int y ) { return x < y ? x : y ; }
inline int   Max(int x,int y ) { return x > y ? x : y ; }

struct arctype{
       int s,t;
       int flow,cap;
       int snext,tnext;
       void init(int ps,int pt,int pf,int pc){
            s    = ps;   t   = pt  ; 
            flow = pf ;  cap = pc;
       }
       int  other(int v)  {  return v == s ?  t : s   ;            }
       bool from(int  v)  {  return v == s            ;            }
       int  Rcap(int v)   {  return from(v) ?  flow : cap-flow;    }
       int  next(int v)   {  return  v == s ?  snext :  tnext ;     }
};

int  es;
arctype edge[2*maxn*maxn];

int N,E;
int first[maxn];

bool read_graph()
{    int i,as, at,acap;
     es=0;
     if(scanf("%d%d",&E,&N)==EOF)  return false;
     for(i=1;i<=N;++i) first[i]=-1;
     for(i=1;i<=E;++i)
     {       scanf("%d%d%d",&as,&at,&acap);
             edge[es].init(as,at,0,acap);
             edge[es].snext = first[as];  edge[es].tnext = first[at];
             first[as]=first[at]=es++;
     }
     return true;
}

int wt[maxn],st[maxn];
int Vs,Vt;
                         
struct  node {
        int v, w;
};

bool operator < (node a,node b)  {    return a.w > b.w;    }

bool MaxFlow()
{    priority_queue<node> Q;
     node cur;
     int i,v,it,w,cap;
     for(i=1;i<=N;++i)  wt[i]=st[i]=0;
     wt[Vs] = maxint;  st[Vs] = -1;
     cur.v = Vs ; cur.w = maxint;
     Q.push(cur);
     while(!Q.empty())
     {      cur=Q.top()   ;  Q.pop(); v = cur.v; 
            if(v == Vt)  break;
            for(it=first[v] ;  it != -1  ; it = edge[it].next(v) ) 
            {       w = edge[it].other(v);
                    cap = edge[it].Rcap(w);
                    cap = Min( cap, wt[v] ); 
                    if(cap > 0 && cap > wt[w])
                    {     wt[w] = cap ;
                          cur.v = w ;  cur.w = wt[w];
                          Q.push(cur);  
                          st[w]=it;  
                    }
            }     
     }
     return  st[Vt]==0  ?  false :  true;    
}
void show()
{    int i,it,ans=0;
     //printf("Max flow is :\n");
     //for(i=0; i<es ;++i)  
     //   printf("%d ----> %d    flow :  %d \n",edge[i].s,edge[i].t, edge[i].flow);
     for(it=first[Vs]; it !=-1 ; it=edge[it].next(Vs))
     {     if(edge[it].from(Vs))  ans+=edge[it].flow;
           else   ans-=edge[it].flow;
     }
     printf("%d\n",ans);  
}
void solve()
{       Vs=1;  Vt=N;
        int i,j,k,it,next,del,v,w;
        while(MaxFlow())
        {     del = maxint;
              for(it = st[Vt], v=Vt ; it !=-1  ;  it = st[w],v = w )
              {      w = edge[it].other(v);
                     del = Min( del , edge[it].Rcap(v));
              }
              //cout<<"Add flow is:"<<del<<endl;
              for(it = st[Vt], v=Vt ; it !=-1  ;  it = st[w], v = w)
              {      w= edge[it].other(v);
                     if(edge[it].from(v)==true)  edge[it].flow -= del;
                     else   edge[it].flow +=del;
              }                                     
        }
        show();
}
int main()
{   
      while(read_graph())   solve();
      return 0;
}
             
   
         
