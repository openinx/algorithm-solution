#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const static double PI = acos(-1.0);

int main(){
    int n ;
    double D, d, s ;
    cin >> n;
    while(n-- && scanf("%lf%lf%lf", &D, &d, &s)!=EOF){
        double x = PI / (asin((d+s)/(D-d)));
        printf("%.0lf\n", floor(x));
    }
    return 0;
}
