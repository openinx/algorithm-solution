#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct Point{
    int x , y;
};

bool isCross(int x, Point a, Point b){
    if(a.x == b.x){
        return false;
    }else{
        return x >= min(a.x, b.x)  && x <= max(a.x, b.x);
    }
}

void getCrossPoint(int x , Point a, Point b , double *miny, double *maxy){
    double y ; 
    if(a.y == b.y){
        y = a.y ;
    }else{
        y = (double)(b.y - a.y) / (double)(b.x - a.x ) * (x - a.x) + a.y;
    }
    *miny = min(*miny, y);
    *maxy = max(*maxy, y);
}

bool eq(double x, double y){
    return fabs(x - y) < 1e-8;
}

int calc(double miny, double maxy){
    if(miny >= maxy ) return 0;
    double y2 = floor(maxy);
    double y1 = ceil(miny);
    y2 = eq(y2, maxy) ? y2-1: y2;
    y1 = eq(y1, miny) ? y1+1: y1;
    return (int)y2 - (int)y1 + 1 ;
}

int main(){
    int result  = 0 ; 
    Point a , b , c ;
    double miny, maxy;
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y){
        if((a.x|a.y|b.x|b.y|c.x|c.y) == 0){
            break;
        }
        result = 0 ; 
        int minx = min(c.x, min(a.x, b.x));
        int maxx = max(c.x, max(a.x, b.x));
        for(int i = minx + 1 ; i < maxx ; ++ i){
            miny = 1e100;
            maxy = -1e100;
            if(isCross(i, a, b)){
                getCrossPoint(i, a, b, &miny, &maxy);
            }
            if(isCross(i, b, c)){
                getCrossPoint(i, b, c, &miny, &maxy);
            }
            if(isCross(i, a, c)){
                getCrossPoint(i, a, c, &miny, &maxy);
            }
            result += calc(miny, maxy);
        }
        cout << result << endl;
    }
    return 0;
}

