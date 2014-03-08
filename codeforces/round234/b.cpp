#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;

#define  PII pair<int, int>

int main(){
    int n , m, no_ans, i, j;
    char bd[1001][1001];
    vector<PII> vec ;
    int flag[1001];

    while(scanf("%d%d", &n, &m)!=EOF){

        for(i = 0 ; i < n ;  ++ i)
            scanf("%s", bd[i]);

        no_ans = 0 ; 
        vec.clear();

        memset(flag, 0 , sizeof(flag)) ;

        for(i = 0 ; i < n && !no_ans; ++ i)
        {
            int cnt = -1 ; 
            for(j = 0 ; j <m && !no_ans ; ++ j)
                if(bd[i][j] == 'G') {
                    cnt = 0 ;  
                    vec.push_back(PII(i, j));
                }else  if (bd[i][j] == 'S') {
                    if(cnt ==-1)
                        no_ans = 1 ; 
                }
        }
        if(no_ans){
            printf("-1\n") ;
            continue; 
        }

        int ans = 0 ; 
        bool finished = 1 ;
        do{
            finished = 1;
            bool touch = 0 ;
            for(i = 0 ; i < vec.size() ; ++ i)
                if (!flag[i]){
                    finished = 0;
                    if( ++vec[i].second >= m || bd[vec[i].first][vec[i].second] == 'S') {
                        flag[i] = 1;
                        touch = 1 ;
                    }
                }
            if(touch)
                ans ++ ;
            if(finished) break; 
        }while(1) ;
        printf("%d\n", ans) ;
    }
    return 0 ;
}

