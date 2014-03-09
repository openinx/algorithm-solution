#include<iostream>
#include<stdlib.h>
using namespace std;

const int maxn = 100005;
int l[maxn] ,r[maxn] , h[maxn] ;

int main()
{    
     int n,i;
     while(scanf("%d",&n)!=EOF && n)
     {     
            for(i = 1 ; i<=n; ++i)  scanf("%d",&h[i]);
            for(i = 1 ; i<=n; ++i)  r[i] = l[i] = i;
            h[0] = h[n +1] = -1;
            for(i = 1 ; i<=n; ++i)
                while( h[i] <= h[ l[i] - 1 ] ) l[i] = l[ l[i] - 1 ];
            for(i = n ; i>= 1 ; --i)
                while( h[i] <= h[ r[i] + 1 ] )  r[i] =r[ r[i] + 1 ];
            __int64 ans = 0;
            for( i = 1 ; i<=n; ++i)
               ans  = max( ans , (__int64)(r[i] - l[i] + 1 ) * (__int64)h[i] );
            printf("%I64d\n",ans);
     }
     return 0;
}
