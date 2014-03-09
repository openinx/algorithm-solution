#include<iostream>
using namespace std;

int ipow(int n,int k)
{   int ret=1;
    while(k)
    {   if(k&1)  ret=ret*n;
        n*=n;
        k>>=1;
    }
    return ret;
}

inline int _abs(int v) {return v>0 ? v:-v;}

int main()
{   int n,m,i,j,ans,min,tp;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0&&m!=0))
    {     if(m==1) {printf("%d\n",n); continue;}
          for(i=1,min=10000000;(tp=ipow(i,m))<=2*n;++i)
             if(_abs(tp-n)<min)
             {    min=_abs(tp-n);
                  ans=i;
             }
          printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}
    

