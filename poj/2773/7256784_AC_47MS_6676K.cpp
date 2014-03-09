#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1000005;
bool vis[maxn];
vector<int> np;
int n,k;

void find(int x)
{    
     np.clear();
     int i,j,t,tot = x;
     for(i = 1;i<=tot;++i) vis[i] = true;
     while(x!=1)
     {   
          for(i = 2 ,j = x; i * i <= x; ++i)
            if( x % i == 0 ) {  j = i; break; }
          for(t = j;t <= tot ; t += j )  vis[t] = false;
          while(x % j ==0)  x /= j;
     }
     for(i = 1;i<=tot; ++i)
       if(vis[i])  np.push_back(i);
     //for(i = 0;i<np.size();++i) printf("%d ",np[i]); printf("\n");
}      


int main()
{   
    int i,j,t,c;
    while(scanf("%d%d",&n,&k)!=EOF)
    {    
         if(n == 1) {  printf("%d\n",k ); continue; } 
         find(n);
         if(k <= np.size())
         { 
              printf("%d\n",np[k-1]);
              continue;
         }
         else 
         {
             t = (k-1) % np.size();  c = (__int64) ( (__int64)n *(__int64)((k-1)/np.size()) );
             printf("%I64d\n",c + (__int64)np[t]); 
         }
    }     
    return 0;
}
