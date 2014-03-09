#include<iostream>
using namespace std;
const int maxn = 41;
int n,m,ht[maxn],s[maxn];

bool dfs(int lvl )
{    
     if(lvl > n)  return true;
     int ml = maxn , mi , i , j , check ;
     for(i = 1 ;i<=m ; ++i)
       if(ml > ht[i])
       { 
          ml = ht[i] , mi = i;      
       }
     bool vis[maxn]; for(i = 0 ;i<maxn;++i) vis[i] = 1;
     for(i = lvl ; i<=n ; ++i)
     {     
           if(vis[ s[i] ]==0) continue;
           swap(s[i] , s[lvl]);
           check = 1 ;
           if(s[lvl] + mi - 1 > m) check = 0;
           for( j = mi ; j<= s[ lvl ] + mi -1 && check ; ++j) 
              if(ht[j] !=  ml ) check = 0 ;
           if(ml + s[lvl] > m) check = 0;
           if(check)
           {    
             for( j = mi ; j<mi + s[lvl] ; ++j)  
               ht[j] += s[lvl];
             if(dfs(lvl + 1)) 
                return true;
             for(j = mi ; j<mi + s[lvl] ; ++j)
               ht[j] -= s[lvl];  
           }
           swap(s[i],s[lvl]);  
           vis[ s[i] ] = 0;
     }
     return false;
}

int main()
{    
     int i,j,cas,sum = 0;
     scanf("%d",&cas);
     while(cas--)
     {
        scanf("%d%d",&m,&n);
        memset(ht,0,sizeof(ht));
        sum = 0;
        for(i = 1;i<=n;++i)
        { 
              scanf("%d",&s[i]);
              sum += s[i] * s[i];
        }
        
        if(sum== m*m && dfs(1))
           printf("KHOOOOB!\n");
        else
           printf("HUTUTU!\n");
     }
     return 0;
}

