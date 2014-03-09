#include<iostream>
#include<queue>
using namespace std;

const int maxn = 1<<17;
char s[10][10];
int start,white,black;
int status[maxn];
int del[4]={1,-4,-1,4};

int NextStatus(int cur,int pos)
{   
    int i,np,son=cur;
    for(i = 0 ; i < 4; ++i)
    {   
        np = pos + del[i];
        if((np<0||np>=16)) continue;
        if(i==0||i==2) 
           if(np/4!=pos/4) continue;
        cur = cur ^ (1<<np);
    }
    cur = cur ^ (1<<pos);             
    return cur;
}

int solve()
{   
    int i,j,x,next,cur,son;
    if(start==black||start==white) return 0;
    queue<int> q;
    memset(status,-1,sizeof(status));
    status[start]=0;
    q.push(start);
    while(!q.empty())
    {     
          cur = q.front();  q.pop();
          for(i=0;i<16;++i)
          {      
              son=NextStatus(cur,i);
              if(status[son]!=-1) continue;
              status[son] = status[cur] + 1;
              if(son == black || son == white) return status[son];
              q.push(son);
          }
    }
    return -1;
}
int main()
{    
     int i,j;
     start=0;
     black=(1<<16)-1;   white=0;
     for(i=0;i<4;++i)   scanf("%s",s[i]);
     for(i=0;i<4;++i)  
          for(j=0;j<4;++j)
          if(s[i][j]=='w')  start+=(1<<(4*i+j)); 
    int ans=solve();
    if(ans==-1) printf("Impossible\n");
    else  printf("%d\n",ans);
    return 0;
}
     
     
