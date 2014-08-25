#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define PRIME_SIZE 100000

typedef long long lld;
typedef vector<lld> vec;

bool test[PRIME_SIZE];
lld prime[PRIME_SIZE], psiz;

void makePrime(){
    lld i , j;
    psiz = 0;
    memset(test, 0 , sizeof(test));
    for(i = 2 ; i < PRIME_SIZE; ++i)
        if(test[i] == 0){
            prime[psiz++] = i ;
            for(j = i + i ; j < PRIME_SIZE; j+= i){
                test[j] = 1;
            }
        }
}

void getFac(int n , vec  &p, vec  &a){
    p.clear(); 
    a.clear();
    while(n > 1){
        int small = n ; 
        for(int i = 0 ; i < psiz && prime[i] * prime[i] <= n ; ++ i)
            if(n % prime[i] == 0){ small = prime[i]; break;}
        int cnt = 0;
        while(n % small == 0){
            cnt ++ ;
            n /= small;
        }
        p.push_back(small);
        a.push_back(cnt);
    }
}

void dfs(int dep, int cur, vec &p, vec &a, vec &ret){
    if(dep >= p.size()){
        ret.push_back(cur);
        return ;
    }
    for(int i = 0 ; i <= a[dep] ; ++ i){
        dfs(dep + 1, cur, p, a, ret);
        cur *= p[dep];
    }
}

lld gcd(lld x, lld y){
    return y == 0 ? x : gcd(y, x % y);
}

lld calc(lld n){
    lld i , j , x , y, cnt = 0;
    vec p , a, ret;
    getFac(n, p, a);
    dfs(0LL, 1LL, p, a, ret);
    for(i = 0 ; i < ret.size(); ++ i){
        x = ret[i];
        for(j = i; j < ret.size() ; ++ j){
            y = ret[j];
            if(gcd(x, y) == 1){
                ++ cnt;
            }
        }
    }
    return cnt;
}

void mytest(lld n){
    vec p , a, ret;
    getFac(n , p, a);
    dfs(0LL, 1LL, p, a , ret);
    sort(ret.begin(), ret.end());
    for(int i = 0 ; i < ret.size() ; ++ i)
        cout << ret[i] << endl;
}

int main(){
    lld tc, n, ti; 
    makePrime();
    while(scanf("%lld", &tc)!=EOF){
        for(ti = 0 ; ti < tc ; ++ ti){
            scanf("%lld", &n);
            //mytest(n);
            printf("Scenario #%lld:\n%lld\n\n", ti + 1, calc(n));
        }
    }
    return 0 ;
}

