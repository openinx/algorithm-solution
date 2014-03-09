#include <iostream>
#include <queue>

using namespace std;

const int maxN=201;

static int edge[maxN][maxN];
bool visited[maxN];
int father[maxN];
int N, M; //边数,顶点数
int ans; //结果
void Ford_Fulkerson( )
{
    while(1)
    {
        //一次大循环,找到一条可能的增广路径
        queue <int> q;
        memset(visited, 0, sizeof(visited));
        memset(father, -1, sizeof(father));
        int now;
        visited[0] = true;
        q.push(0);
        while(!q.empty())//广度优先
        {
            now = q.front();
            q.pop();
            if(now == M-1) break;
            for(int i=0; i<M; i++)
            {
                //每次父亲节点都要更新,权值减为0的边就不算了.
                if(edge[now][i] && !visited[i])
                {
                    father[i] = now;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        //可能的增广路不存在了
        if(!visited[M-1]) break;
        int u, min = 0xFFFF;
        for(u=M-1; u; u=father[u])//找出权值最小的边
        {
            if(edge[father[u]][u] < min)
                min = edge[father[u]][u];
        }
        //减去最小权值
        for(u=M-1; u; u=father[u])
        {
            //前向弧减去
            edge[father[u]][u] -= min;
            //后向弧加上
            //存在圆环,这句话关键
            edge[u][father[u]] += min;
        }
        //当前增广路径增加的流
        ans+=min;
    }
}

int main()
{
    int s, e, w;
    while(cin >> N >> M)
    {
        ans=0;
        memset(edge, 0, sizeof(edge));
        for(int i=0; i<N; i++)
        {
            cin>>s>>e>>w;
            edge[s-1][e-1]+=w;
        }
        Ford_Fulkerson();
        cout << ans << endl;
    }
    return 0;
}
