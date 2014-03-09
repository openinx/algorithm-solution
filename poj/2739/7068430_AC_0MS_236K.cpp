#include<iostream>
using namespace std;

const int _size = 10001;
bool visit[_size];
int prime[_size],ps;

void InitPrime()
{    int i,j;
     memset(visit,true,sizeof(visit));
     for(i=2;i<_size;++i)
       if(visit[i])
            for(j=i+i;j<_size;j+=i)
              visit[j]=false;
     for(i=2,ps=0;i<_size;++i)
        if(visit[i])  prime[ps++]=i;
}

int main()
{   
    InitPrime();
    int  n,i,j,ans,tp;
    while(cin>>n&&n)
    {    
         ans=0;
         for(i=0;(i<ps)&&(prime[i]<=n);++i)
         {  
              tp=prime[i];
              for(j=i+1;(j<ps)&&(tp<n);++j) tp+=prime[j];
              if(tp==n)    ++ans;
         }
         cout<<ans<<endl;
    }
    return 0;
}
              
              
