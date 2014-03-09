#include<iostream>
using namespace std ;

int main(){
    int  n ,  testCase  ; 
    scanf("%d" , &testCase);
    while(testCase--){
          scanf("%d" , &n);
          int cnt = 0 , five = 5 ;
          while(five <= n){
                cnt += n / five ; 
                five *= 5 ;
          } 
          printf("%d\n" , cnt);
    }
    return 0 ;
}
