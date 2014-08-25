#include <iostream>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAXN 100005

int n ; 
double a[MAXN][5] ;

int main(){
    int x , y, check;
    double l , r , mid;
    scanf("%d", &n);
    srand(time(NULL));
    for(int i = 0 ; i < n ; ++ i){
        for(int j = 0 ; j < 5 ; ++ j)
            scanf("%lf", &a[i][j]);
    }
    l = 0.0 ; r = 1e20;
    for(int i = 0 ; i < 100 ; ++ i){
        mid = (l + r ) / 2.0;
        check = true;
        for(int k = 0 ; check && k < 100000 ; ++ k){
            x = rand() % n ; 
            y = rand() % n ; 
            double sum = 0 ; 
            for(int j = 0 ; j < 5 ; ++j)
                sum +=  fabs(a[x][j] - a[y][j]);
            if(sum > mid){
                check = false;
            }
        }
        if(check){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%0.2lf\n", mid);
    return 0;
}
