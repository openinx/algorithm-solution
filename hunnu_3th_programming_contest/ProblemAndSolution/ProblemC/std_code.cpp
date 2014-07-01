#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>

using namespace std ;

const double SIN_60_DGR = sqrt(3.0) * 0.5 ;  

double Area(double a , double b){
       return a * b * SIN_60_DGR * 0.5 ; 
}

int main(){
    
    freopen("1.std.in" , "r" , stdin);
    freopen("1.std.out", "w" , stdout);
    
    int caseNumber ; 
    double ans , land1 , land2 , land3 ; 
    cin >> caseNumber ; 
    while(caseNumber -- ){
          cin >> land1 >> land2 >> land3 ;
          ans = Area(1 , 1);
          ans -= Area(1.0/(land3+1) , land1/(land1+1)) ;
          ans -= Area(1.0/(land1+1) , land2/(land2+1)) ;
          ans -= Area(1.0/(land2+1) , land3/(land3+1)) ; 
          printf("%0.4f\n" , ans);
    }
    //system("pause");
    return 0 ;
}
