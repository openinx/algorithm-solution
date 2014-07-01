
//  liuzhe  

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 200005

int readdata()
{
    int ans=0;
    char c;
    
    while(!isdigit(c=getchar()));
    ans=c-'0';
    while(isdigit(c=getchar()))
    ans=ans*10+c-'0';
    
    return ans;
}

int a[N],b[N],c[N],n;

int lowbit(int x)
{
    return x&(-x);
}

void add(int a[N],int pos,int data)
{
     for(;pos<=N-1;pos+=lowbit(pos))a[pos]+=data;
}

int sum(int a[N],int pos)
{
    int ans=0;
    for(;pos>=1;pos-=lowbit(pos))ans+=a[pos];
    return ans;
}

void build()
{
     int i,j;
     scanf("%d",&n);
     
     memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     
     for(i=1;i<=n;i++)
     {
         //scanf("%d",&c[i]);
         c[i]=readdata();
         c[i]++;
         add(b,c[i],1);
     }
}

void solve()
{     
     int i,j;
     __int64 ans=0;
     for(i=1;i<=n;i++)
     {
         int L=sum(a,c[i]-1);
         int R=sum(b,N-1)-sum(b,c[i]);
         
         add(a,c[i],1);
         add(b,c[i],-1);
         
         ans+=1ll*L*R;
         
         //printf("%lld %lld %lld\n",L,R,ans);
     }
     printf("%I64d\n",ans);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         build();
         solve();
    }
