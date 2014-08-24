#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 105

char s[MAXN];
int dp[MAXN][MAXN], n ;

int main(){
    int i , j, t, k; 
    while(scanf("%s", s) != EOF && strcmp(s, "end")){
        n = strlen(s);
        memset(dp, 0 , sizeof(dp));
        for(i = 0 ; i < n; ++ i) 
            dp[i][i] = 0 ;
        for(t = 1 ; t < n ; ++ t){
            for(i = 0 ; i + t < n ; ++ i){
                j = i + t;
                if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']'){
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
                }
                for(k = i + 1 ; k <= j ; ++ k){
                    dp[i][j] = max( dp[i][j], dp[i][k-1] + dp[k][j] ) ;
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
