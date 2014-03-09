#include<iostream>
#include<vector>
using namespace std;

const int MAX=10001;
int f[MAX];
int r[MAX];
int indegree[MAX];//保存每个节点的入度
int visit[MAX];
vector<int> tree[MAX],Qes[MAX];
int ancestor[MAX];


void init(int n)
{
    for(int i=1;i<=n;i++)
    {

        r[i]=1;
        f[i]=i;
        indegree[i]=0;
        visit[i]=0;
        ancestor[i]=0;
        tree[i].clear();
        Qes[i].clear();
    }

}

int find(int n)
{
    if(f[n]==n)
        return n;
    else
        f[n]=find(f[n]);
    return f[n];
}//查找函数，并压缩路径

int Union(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b)
        return 0;
    //相等的话,x向y合并
    else if(r[a]<=r[b])
    {
        f[a]=b;
        r[b]+=r[a];
    }
    else
    {
        f[b]=a;
        r[a]+=r[b];
    }
    return 1;

}//合并函数，如果属于同一分支则返回0，成功合并返回1


void LCA(int u)
{
    ancestor[u]=u;
    int size = tree[u].size();
    for(int i=0;i<size;i++)
    {
        LCA(tree[u][i]);
        Union(u,tree[u][i]);
        ancestor[find(u)]=u;
    }
    visit[u]=1;
    size = Qes[u].size();
    for(int i=0;i<size;i++)
    {
        //如果已经访问了问题节点,就可以返回结果了.
        if(visit[Qes[u][i]]==1)
        {
            cout<<ancestor[find(Qes[u][i])]<<endl;
            return;
        }
    }
}


int main()
{
    int cnt;
    int n;
    cin>>cnt;
    while(cnt--)
    {
        cin>>n;;
        init(n);
        int s,t;
        for(int i=1;i<n;i++)
        {
            cin>>s>>t;
            tree[s].push_back(t);
            indegree[t]++;
        }
        //这里可以输入多组询问
        cin>>s>>t;
        //相当于询问两次
        Qes[s].push_back(t);
        Qes[t].push_back(s);
        for(int i=1;i<=n;i++)
        {
            //寻找根节点
            if(indegree[i]==0)
            {
                LCA(i);
                break;
            }
        }
    }
    return 0;
}
