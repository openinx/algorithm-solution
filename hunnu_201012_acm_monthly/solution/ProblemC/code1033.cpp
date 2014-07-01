#include<iostream>
#include<math.h>
using namespace std ;
typedef __int64 lld ;

int main(){
    
    //freopen("1.std.in" , "r" , stdin);  freopen("1.std.out" ,"w" ,stdout);
    
    lld n , t , ans;
    int testCase ; 
    scanf("%d" , &testCase);
    while(testCase--){
              scanf("%I64d" , &n);
              t = (lld) floor(sqrt((double)n)) - 1 ;
              ans = t * (t+1) * (2*t+1)/3 +  t*(t+1)/2 + (t+1)*(n - (t+1) * (t+1) + 1) ; 
              printf("%I64d\n" , ans);
    } 
    
    //fclose(stdin);  fclose(stdout);
    
    return 0 ;
} 
