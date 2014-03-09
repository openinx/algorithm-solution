#include <iostream>

using namespace std;

const int Max = 50002;
int n,k;
int fa[Max],r[Max];

int find(int x)
{
   if(fa[x] == x) return(x);
   int tmp = fa[x];
   fa[x] = find(fa[x]);
   r[x] = (r[tmp] + r[x]) % 3;
   return(fa[x]);
}

void connect(int x, int y, int k)
{
   int a = find(x), b = find(y);
   fa[a] = b;
   r[a] = (r[y] - r[x] + k + 3) % 3;
}

int main()
{
    scanf("%d%d",&n,&k);
       for(int i = 1; i <= n; i++) { fa[i] = i;  r[i] = 0; }
       int ans = 0;
       for(int i = 1; i <= k; i++)
       {
          int d,j,k1;
          scanf("%d%d%d",&d,&j,&k1);
          if(j > n || k1 > n) ans ++;
          else
          {
             if(d == 1)
             {
                if(find(j) == find(k1) && r[j] != r[k1]) ans ++;
                else connect(j,k1,0);
             }
             else
             {
                if(find(j) == find(k1) && r[j] != (r[k1] + 1 ) % 3) ans ++;
                else connect(j,k1,1);
             }
          }
       }
       printf("%d\n",ans);
    return(0);
}


