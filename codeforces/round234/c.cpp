#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std; 

int main(){
    int n , m , x , y , z, p , px[100001], py[100001], tx , ty;
    while(cin >> n >> m >> x >> y >> z >> p){
        for(int i = 0 ; i < p ; ++ i){  
           cin >> px[i] >> py[i] ; 
           px[i] -- ; py[i] -- ;
        } 
        x %= 4 ;  y %= 2 ; z %= 4 ;
        for(int i = 0 ; i < p ; ++ i){
            tx = px[i] ; ty = py[i] ; 
            if(x == 1){
                px[i] = ty ; py[i] = n - 1 - tx ; 
            }else if(x == 2){
                px[i] = n - 1 - tx ; py[i] =  m - 1 - ty ;
            }else if (x == 3){
                px[i] = m - 1 - ty ; py[i] = tx ;
            }
            tx = px[i] ; ty = py[i] ; 
            if(y == 1){
                px[i] = tx ; py[i] = m - 1 - ty ; 
            }
            tx = px[i] ; ty = py[i] ; 
            if(z == 3){
                px[i] = ty ; py[i] = n - 1 - tx ; 
            }else if (z == 2){
                px[i] = n - 1 - tx ; py[i] =  m - 1 - ty ;
            }else if (z == 1){
                px[i] = m - 1 - ty ; py[i] = tx ;
            }
        }
        for(int i = 0 ; i < p ; ++ i ){
            printf("%d %d\n", px[i] + 1, py[i] + 1);
        }
    }
    return 0 ;
}
