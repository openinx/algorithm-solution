#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
int x[510],ans[510],a[3][510][510];

bool check(int n)
{
    int i,j,k,s[510],t = 3;
    while(t--)//多次测试减少错误的概率
    {
        memset(ans,0,sizeof(ans));
        memset(s,0,sizeof(s));
        for(i=1;i<=n;++i)
            x[i] = rand()%101;//设置x矩阵的元素
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                ans[i] += x[j]*a[2][j][i];
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                s[i] += x[j]*a[0][j][i];
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                ans[i] -= s[j]*a[1][j][i];
        for(i=1;i<=n;++i)
            if(ans[i]!=0)
                return 0;
    }
    return 1;
}

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(k=0;k<3;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                scanf("%d",&a[k][i][j]);
    srand(time(NULL));//设置种子
    if(check(n))printf("YES\n");
    else printf("NO\n");
    return 0;
}
