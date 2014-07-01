#include<iostream>
#include<cstring>
using namespace std;
int C[200005];
__int64 sum[200005];
int lowbit(int x)
{
    return x&(-x);
}
void ADD(int x,int value)
{
    while(x<=200000)
    {
        C[x]+=value;
        x+=lowbit(x);
    }
}
void ADD1(int x,int value)
{
    while(x<=200000)
    {
        sum[x]+=value;
        x+=lowbit(x);
    }
}
int SUM(int x)
{
    int sum=0;
    while(x)
    {
        sum+=C[x];
        x-=lowbit(x);
    }
    return sum;
}
__int64 SUM1(int x)//最后一位小于或等于x的二元组个数 
{
    __int64 s=0;
    while(x)
    {
        s+=sum[x];
        x-=lowbit(x);
    }
    return s;
}
int N;
int S[100005];

int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<=200001;i++)C[i]=0;
        for(i=0;i<=200001;i++)sum[i]=0;
        scanf("%d",&N);
        __int64 res=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&S[i]);
            S[i]++;
            res+=SUM1(S[i]-1);
            ADD1(S[i],SUM(S[i]-1));
            ADD(S[i],1);
        }
        printf("%I64d\n",res);
    }
    return 0;
}

