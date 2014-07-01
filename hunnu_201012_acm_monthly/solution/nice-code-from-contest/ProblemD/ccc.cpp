#include<iostream>
#include<cstring>
#define MAX 100000
using namespace std;
int N,M,K;
char maze[105][105];
struct node{int x,y,step;};
node Ts,Js;
node Q[MAX];
int head,tail;
int next[4][2]={1,0,0,1,-1,0,0,-1};
int memo[105][105][105];
int mm;
node JJ[10000];
int bfs()
{
    Ts.step=0;
    head=tail=0;
    node ns,tmp;
    Q[tail++]=Ts;
    memo[Ts.x][Ts.y][0]=++mm;
    if(Ts.x==Js.x&&Ts.y==Js.y)
        return 1;
    int i;
    while(head!=tail)
    {
        ns=Q[head++];
        if(head==MAX)head=0;
        for(i=0;i<4;i++)
        {
            tmp.x=ns.x+next[i][0];
            tmp.y=ns.y+next[i][1];
            if(tmp.x<0||tmp.y<0||tmp.x>=N||tmp.y>=M)
                continue;
            if(maze[tmp.x][tmp.y]=='*')
                continue;
            tmp.step=ns.step+1;
            if(memo[tmp.x][tmp.y][tmp.step]==mm)
                continue;
            memo[tmp.x][tmp.y][tmp.step]=mm;
            if(tmp.x==JJ[tmp.step].x&&tmp.y==JJ[tmp.step].y)
                return 1;
            if(tmp.step<K)
            {
                Q[tail++]=tmp;
                if(tail==MAX)tail=0;
            }
        }
    }
    return 0;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                scanf(" %c",&maze[i][j]);
                if(maze[i][j]=='T')
                    Ts.x=i,Ts.y=j;
                if(maze[i][j]=='J')
                    Js.x=i,Js.y=j;
            }
        }
        //cout<<"over"<<endl;
        JJ[0]=Js;
        int d;
        for(i=1;i<=K;i++)
        {
            scanf("%d",&d);
            JJ[i].x=JJ[i-1].x+next[d][0];
            JJ[i].y=JJ[i-1].y+next[d][1];
            if(JJ[i].x<0||JJ[i].y<0||JJ[i].x>=N||JJ[i].y>=M)
                JJ[i]=JJ[i-1];
            if(maze[JJ[i].x][JJ[i].y]=='*')
                JJ[i]=JJ[i-1];
        }
        if(bfs())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

