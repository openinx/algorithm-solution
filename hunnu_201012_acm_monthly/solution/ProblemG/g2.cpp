#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<time.h>
typedef long long LL;
const int maxn=510;
const LL p1=999983,p2=999979;
const LL q1=444443,q2=444461;
int n,m,tot,h[q2],next[q2];
LL a[maxn][maxn],b[maxn][maxn],p1_p[maxn],p2_p[maxn];
char s[maxn][maxn];
struct matrix
{
    int x,y;
}c[maxn*maxn],a1,a2;
int min(int& a,int& b)
{
    if (a > b)  return b;
    return a;
}
void insert(int x,matrix& t)
{
    c[++tot]=t;
    next[tot]=h[x];
    h[x]=tot;
}
bool cmp(int x,int l)
{
    for (x=h[x];x;x=next[x])
    {
        a2=c[x];
        bool flag=true;
        for (int i=0;(i<l)&&flag;++i)
            for (int j=0;(j<l)&&flag;++j)
                if (s[a1.y+i][a1.x+j] != s[a2.y+i][a2.x+j])
                    flag=false;
        if (flag)  return true;
    }
    return false;
}
bool check(int x,LL& pow1,LL& pow2)
{
    memset(h,0,sizeof(h));
    for (int i=1;i<=n;++i)
    {
        a[i][1]=0;
        for (int j=1;j<=x;++j)
            a[i][1]=(a[i][1]*p1+s[i][j])%q1;
        for (int j=2;j<=m-x+1;++j)
            a[i][j]=((a[i][j-1]-s[i][j-1]*pow1%q1+q1)*p1+s[i][j+x-1])%q1;
    }
    for (int i=1;i<=m-x+1;++i)
    {
        b[1][i]=0;
        for (int j=1;j<=x;++j)
            b[1][i]=(b[1][i]*p2+a[j][i])%q2;
        for (int j=2;j<=n-x+1;++j)
            b[j][i]=((b[j-1][i]-a[j-1][i]*pow2%q2+q2)*p2+a[j+x-1][i])%q2;
    }
    tot=0;
    for (int i=1;i<=n-x+1;++i)
        for (int j=1;j<=m-x+1;++j)
        {
            if (cmp(b[a1.y=i][a1.x=j],x))  return true;
            insert(b[i][j],a1);
        }
    return false;
}
int solve()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%s",&s[i][1]);
    p1_p[1]=p2_p[1]=1;
    for (int i=2;i<=n;++i)  p1_p[i]=p1_p[i-1]*p1%q1;
    for (int i=2;i<=m;++i)  p2_p[i]=p2_p[i-1]*p2%q2;
    int l=0,r=min(n,m);
    while (l <= r)
    {
        int mid=(l+r>>1);
        if (!check(mid,p1_p[mid],p2_p[mid]))  r=mid-1;
        else  l=mid+1;
    }
    while (l && (!check(l,p1_p[l],p2_p[l])))  --l;
    if (l)
    {
        printf("%d\n",l);
        //printf("%d %d\n",a1.y,a1.x);
        //printf("%d %d\n",a2.y,a2.x);
    }
    else  printf("0\n");
    return 0;
}


int main(){
    
    //freopen("1.std.in" ,"r" ,stdin);  freopen("code1.std.out" ,"w" , stdout);
    
    //clock_t start , end ; 
    //start = clock();
    
    int testCase ; 
    scanf("%d"  , &testCase);
    while(testCase--)  solve();

    //end = clock();
    //printf("time : %d ms\n" , (int)(end - start));
    
    //fclose(stdin) ; fclose(stdout);
 
    return 0 ;   
}
