#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

string multi(string x,string y)
{
    char a[60],b[60],c[120];
    int lenx=x.length();int leny=y.length();
    int i,j;
    for(i=0;i<lenx;i++)a[i]=x[lenx-i-1]-'0';
    for(i=0;i<leny;i++)b[i]=y[leny-i-1]-'0';
    for(i=0;i<120;i++)c[i]=0;
    for(i=0;i<lenx;i++)
    {
        for(j=0;j<leny;j++)
        {
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    string ans="";
    for(i=119;i>=0&&c[i]==0;i--);
	for(;i>=0;i--)
		ans+=c[i]+'0';
    return ans;
}
string get(string x,string y,int swaps)
{
    int len=x.length();int i;
    int equal=0;i=0;
    while(x[i]==y[i])i++;
    if(i>0)equal=1;
    if(x[i]<y[i])swap(x[i],y[i]),swaps--;
    if(swaps==0)
        return multi(x,y);
    for(i=i+1;i<len;i++)
    {
        if(x[i]==y[i])
        {
            equal=1;
            continue;
        }
        if(x[i]>y[i])
        {
            swap(x[i],y[i]);
            swaps--;
            if(swaps==0)
                break;
        }
    }
    if(equal==1||(swaps&1)==0)
        return multi(x,y);
    swap(x[len-1],y[len-1]);
    return multi(x,y);
}
string narutoacm(string x,string y,int swaps)
{
    string res;
    if(swaps==0||x==y)return multi(x,y);
    string a=get(x,y,swaps);
    string b=get(y,x,swaps);
    if(a.length()>b.length())
        return a;
    else if(a.length()<b.length())
        return b;
    else
        res = a > b ? a : b;
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("myout.txt","w",stdout);
    char x[60],y[60];
    int swaps;
    while(scanf(" %s %s %d",x,y,&swaps)==3)
    {
        string sx=x;
        string sy=y;
        cout<<narutoacm(sx,sy,swaps)<<endl;
    }
    return 0;
}
