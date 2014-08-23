#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
    int b[1<<15], prime[1<<15], cnt = 0, n;
    memset(b , 0, sizeof(b));
    for(int i = 2; i <(1<<15); i++){
        if(b[i] == 0){
            prime[cnt++] = i;
            for(int j = i + i ; j < (1<<15); j+=i)
                b[j] = 1;
        }    
    }
    //for(int i = 0 ; i < 20; ++ i) cout << prime[i] << endl;
    while(scanf("%d", &n) != EOF && n){
        int result = 0;
        for(int i = 0 ; i < cnt && prime[i] <= n/2;  ++ i){
            if(b[n - prime[i]] == 0)
                result += 1;
        }
        printf("%d\n", result);
    }
}
