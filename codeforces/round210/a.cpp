#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std ; 

#define MAXN  1000000003

int main()
{
    int n ,m, i, error, k  ;
    int delta[5001], limit[5001], raw[5001];
    int operate[5001], l[5001] , r[5001], d[i];
    while(scanf("%d%d", &n , &m) != EOF )
    {
        for(i = 1 ; i <= n; ++i )
        {
            delta[i] = 0 ; 
            limit[i] = MAXN ; 
        }
        for(i = 0; i < m; ++ i )
        {
            scanf("%d%d%d%d", &operate[i], &l[i] , &r[i], &d[i]);
            if(operate[i] == 1)
            {
                for (k = l[i] ; k <=r[i] ; ++k)
                    delta[k] += d[i] ; 
            }else if (operate[i] == 2)
            {
                for(k = l[i] ; k <=r[i] ; ++k)
                    limit[k] = min(limit[k], d[i] - delta[k]);
            }
        }
        int min_v = MAXN ; 
        for(k = 1; k <= n ; ++k)  min_v = min(limit[k], min_v);
        if (min_v == MAXN)
            min_v = 0 ; 
        for(k = 1 ; k <=n ; ++k) 
            raw[k] =  limit[k] == MAXN ? min_v : limit[k];

//for(i = 1; i<=n ; ++i) printf("DEBUG: %d\n", raw[i]);

        for(i = 1 ; i <=n ; ++i) delta[i] = raw[i] ; 

        for(i = 0 , error = false; i < m && !error ; ++i)
        {
            if(operate[i] == 1)
            {
                for(k = l[i]; k <=r[i]; ++k)
                    delta[k] += d[i];
            }else if(operate[i] == 2)
            {
                int max_v = -MAXN; 
                for(k = l[i] ;k <=r[i]; ++k)
                    max_v = max(max_v, delta[k]);
                if (max_v != d[i])
                {
                    error = true ;
                }
            }
        }
        if (error)
            printf("NO\n");
        else {
            printf("YES\n");
            for (i = 1 ; i<=n ; ++i)
                if(i == 1)
                    printf("%d", raw[i]);
                else
                    printf(" %d", raw[i]);
            printf("\n");
        }
    }
    return 0 ;
}
