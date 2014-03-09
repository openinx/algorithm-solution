#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std ;

typedef pair<int ,int> PII ;

const int dx[] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
const int dy[] = {1  , 2  , 2 , 1 ,-1 ,-2 , -2 , -1};

int M[2][305][305];

int n ;
PII start , end ;


bool isOut(PII a){
     return a.first<0||a.second<0||a.first>=n||a.second>=n ;
}

int dbfs(){
    
    if(start == end) return 0 ;
    
    queue<PII> Q[2] ; 
    PII now , next ;
    int step[2] ,idx , cnt ; 
    
    memset(M , -1 ,sizeof(M));

    Q[0].push(start);  M[0][start.first][start.second] = 0 ;
    Q[1].push(end)  ;  M[1][end.first  ][end.second  ] = 0 ;
    step[0] = step[1] = 0 ;
    
    while(!Q[0].empty() || !Q[1].empty()){
            idx = (step[0]+step[1]) & 1 ;  step[idx] ++ ;
            cnt = Q[idx].size() ;
            while(cnt -- ){
                 now = Q[idx].front() ; Q[idx].pop() ;
                 for(int i = 0 ; i < 8 ; ++ i){
                       next = PII(now.first + dx[i] , now.second + dy[i]);
                       if(isOut(next) || M[idx][next.first][next.second] != -1) 
                             continue ;
                       if(M[idx^1][next.first][next.second] != -1 ){      
                             return step[idx] + M[idx^1][next.first][next.second] ;
                       }else{
                             M[idx][ next.first ][ next.second ] = step[idx] ;
                             Q[idx].push(next);
                       }
                 }
            }
    }
}

int main(){
    int acase ;
    scanf("%d" , &acase);
    while(acase -- ){
           scanf("%d" , &n);
           scanf("%d%d" , &start.first , &start.second);
           scanf("%d%d" , &end.first   , &end.second);
           int res = dbfs();
           printf("%d\n" ,res);
    }
    //system("pause");
    return 0 ;
}
