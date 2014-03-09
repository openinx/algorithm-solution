#include<iostream>
#include<queue>
using namespace std;

const int maxn =  30;
struct MFSet {
       int s[maxn];
       void init() {  memset(s,-1,sizeof(s)); }
       int find(int v){   
           int i,j,k;
           for(i=v; s[i]>0; i = s[i] );
           for(j=v; j!=i; j= k ) {  k = s[j] ; s[j] = i;}
           return i;
       }
       void merge(int v,int w)
       {    int pv = find(v), pw = find(w);
            if(pv == pw) return ;
            if(s[pv] < s[pw]) {  s[pv] +=s[pw]; s[pw] = pv; }
            else  {  s[pw] += s[pv] ; s[pv] = pw;  }
       }
};

struct edge{
       int s,t,w;
};

bool operator < (edge a,edge b) {   return a.w > b.w ; }

int main()
{     
      char ch[3];
      edge e;
      int n,cnt,i,j,st,ed,w;
      while(scanf("%d",&n)!=EOF && n )
      {   
          //cout<<"Finided"<<endl;
          priority_queue<edge> q;
          for(i=1;i<=n-1;++i)
          {
                           scanf("%s%d",ch,&cnt);
                           st = ch[0]-'A' + 1;       
                           for(j=0;j<cnt;++j)
                           {
                                              scanf("%s%d",ch,&w);
                                              e.s = st; e.t = ch[0]-'A' + 1 ; e.w = w;
                                              q.push(e);
                           }
          }
          //cout<<"Finished!"<<endl;
          i = 1; int ans = 0;
          MFSet mfs;
          mfs.init();
          while(i < n)
          {     
                e = q.top()  ;  q.pop();
                if(mfs.find(e.s) == mfs.find(e.t)) continue;
                ans += e.w;
                mfs.merge(e.s,e.t);
                ++ i;
          }
          printf("%d\n",ans);
      }
      return 0;
}
                
                           
          

           

