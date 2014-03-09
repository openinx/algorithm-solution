#include<iostream>
#include<queue>
using namespace std;
const int maxn = 30005;
int main()
{
    int i,j,M,N,a[maxn],u[maxn];
    scanf("%d%d",&M,&N);
    for(i=1;i<=M;++i)   scanf("%d",&a[i]);
    for(i=1;i<=N;++i)   scanf("%d",&u[i]);
    priority_queue<int ,vector<int>,less<int> >Q1;
    priority_queue<int ,vector<int>,greater<int> >Q2;
    int as=0,e,x;
    for(i=1;i<=N;++i)
    {   
        while((Q1.size()+Q2.size())<u[i])
        {  
              e = a[++as];
              Q1.push(e);
              if(Q1.size()> i-1) 
              {  
                  x = Q1.top();  Q1.pop();
                  Q2.push(x);
              }
        }
        e = Q2.top();
        Q2.pop();
        Q1.push(e);
        printf("%d\n",e);
        
    }
    return 0;
}
    
