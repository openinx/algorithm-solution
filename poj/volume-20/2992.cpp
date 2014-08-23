#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long lld;
typedef vector<lld> fac;
#define MAXN 432
#define PSIZ 100


bool b[MAXN];
lld prime[MAXN], psiz, hash[MAXN];

void getPrime(){
    memset(b, 0 , sizeof(b));
    memset(hash, 0 , sizeof(hash));

    psiz = 0 ;
    for(int i = 2 ; i < MAXN; ++ i)
        if(b[i] == 0 ){
            hash[i] = psiz;
            prime[psiz++] = (lld)i;
            for(int j = i + i ; j < MAXN; j+= i)
                b[j] = 1 ; 
        }
}

void getFac(lld n, fac &f){
    f.clear(); f.resize(PSIZ);
    while(n > 1 ){
        lld small = n, cnt = 0;
        for(lld i = 0 ; i < psiz && prime[i] * prime[i] <=n ; i++)
            if(n % prime[i] ==  0){
                small = prime[i];
                break;
            }
        while(n % small == 0){
            ++cnt;
            n /= small;
        }
        //cout << "hash[small]" << hash[small] << endl;
        f[ hash[small] ] = cnt;
    }
}

void add(fac &a, fac &b){
    for(int i =  0 ; i < PSIZ; ++ i)
        a[i] = a[i] + b[i];
}

void sub(fac &a, fac &b){
    for(int i =  0 ; i < PSIZ; ++ i)
        a[i] = a[i] - b[i];
}

void copy(fac &a, fac &b){
    a.clear(); a.resize(PSIZ);
    for(int i =  0 ; i < PSIZ; ++ i)
        a[i] = b[i];
}

void initFac(fac &f){
    f.resize(PSIZ);
    fill(f.begin(), f.end(), (lld)0 );
}

int main(){
    lld n, k;

    getPrime();

    fac farr[MAXN];
    initFac(farr[0]);
    for(lld i = 1 ; i < MAXN; ++ i){
        initFac(farr[i]);
        getFac(i, farr[i]);
        add(farr[i], farr[i-1]);
    }
    while(scanf("%lld%lld", &n, &k) != EOF ){
        fac result;
        initFac(result);
        add(result, farr[n]);
        sub(result, farr[k]);
        sub(result, farr[n-k]);
        lld ans = 1;
        for(int i = 0 ; i < PSIZ; ++ i)
            ans = ans * (result[i] + 1 ) ;
        printf("%lld\n", ans);
    }
    return 0 ;
}

