#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long lld;

int main(){
    lld cases, n , m ;
    while(scanf("%lld", &cases) !=EOF ){
        for(lld i = 1 ; i <= cases; ++ i){
            scanf("%lld%lld", &n, &m);
            if((n + m) & 1)
                printf("Scenario #%lld:\n%lld\n\n", i, (m - n + 1)/2 * (n+m));
            else
                printf("Scenario #%lld:\n%lld\n\n", i, (m - n + 1) * (n+m)/2);
        }
    }
    return 0;
}
