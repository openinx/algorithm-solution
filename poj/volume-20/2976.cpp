#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define MAXN 1001

int a[MAXN], b[MAXN], n , k ;
double c[MAXN];

bool check(double t){
    for(int i = 0 ; i < n ; ++ i)
        c[i] = b[i] * t  -  100 * a[i];
    sort(c, c + n);
    double sum = 0 ;
    for(int i = 0 ; i < n - k ; ++ i)
        sum += c[i];
    return sum >= 0;
}

double calc(){
    double l = 0 , r = 100.0, mid = 0;
    for(int i = 0 ; i < 100 ; ++ i){
        mid = (l + r) / 2.0;
        if(check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    return mid;
}

int main(){
    while(scanf("%d%d", &n, &k)!= EOF && (n|k)){
        for(int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 0 ;i < n ; ++ i){
            scanf("%d", &b[i]);
        }
        printf("%d\n", int(calc() + 0.5));
    }
    return 0 ;
}

