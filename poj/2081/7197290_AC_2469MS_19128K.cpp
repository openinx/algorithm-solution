#include<iostream>
#include<set>
using namespace std;
const int maxn = 500005;
int a[maxn];
void Init()
{    
     set<int> s;
     int i,j;
     a[0]=0;
     for(i=1;i<maxn;++i)
     { 
          a[i]=a[i-1]-i;
          if((a[i]>0)&&(s.find(a[i])==s.end())){ s.insert(a[i]);continue;}
          a[i]=a[i-1]+i;
          s.insert(a[i]);
     }
}
     

int main()
{  
    Init();
    int x;
    while(scanf("%d",&x)!=EOF&&x!=-1)
       printf("%d\n",a[x]);
    return 0;
}
           
