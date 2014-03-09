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

const int fac[]={1 , 1 , 2 ,6 , 24 , 120 , 720 , 5040 , 40320 , 362880};
const int MAXN = 363000 ;
const int dx[] = {-1 , 0 , 1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1};
const char CHAR[] = "urdl" ;

int move[MAXN] , pid[MAXN] , visited[MAXN] ;
int forward , backward , mid ;
int start[9] , finish[9] ={1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 0 } ;

/*
* 把任意排列压缩成一个数字，这个数字就只该排列在全排列中的位置。
* 位置从0开始。 
*/ 
int encode(int *a , int n){
    int sum = 0 , cnt , i , j; 
    for(i = 0 ; i < n ; ++ i){
        cnt = 0 ;
        for(j = i + 1 ; j < n ; ++ j)
           cnt += (a[j]<a[i]) ;
        sum += cnt * fac[n-i-1];
    }
    return sum ;
}

/*
* 根据序列号，找到对应的排列。 
*/ 
void decode(int x , int *a , int n){
     int sum = 0 , is[9] = {0} , i , j;
     for(i = 0 ; i < n ; ++ i){
         for(j = 0 ; j < n ; ++ j)
            if(!is[j]){
                   if(sum + fac[n-i-1] > x) break ;
                   sum += fac[n-i-1] ;
            }
         is[j] = 1 ; a[i] = j ;
     }
}

/*
* 沿着四个方向拓展节点 
*/
int extends(int *now , int i ){
    int k , xpos , x , y , nextState = -1; 
    for( k = 0 ; k < 9 && now[k] ; ++ k) ; xpos = k ;
    x = xpos / 3 + dx[i] ;  y = xpos % 3 + dy[i] ;
    if(!(x<0||y<0||x>2||y>2)){
          swap(now[xpos] , now[ 3*x+y ]);
          nextState = encode(now , 9 );
          swap(now[xpos] , now[ 3*x+y ]);
    }
    return nextState ;
}

/*
* 双向广度优先搜索 
*/
int dbfs(){
    int i , j , step[2] , begin , end , idx , cnt , nowState , nextState , now[9] , next[9]; 
    
    queue<int> Q[2] ;
    memset(pid , -1 ,sizeof(pid));
    memset(visited , -1 , sizeof(visited));
    
    begin = encode(start  , 9);  
    end = encode(finish , 9);
    if(begin == end ) return 0 ;
    
    Q[0].push(begin) ;  visited[ begin ] = 0 ; step[0] = 0 ;  
    Q[1].push(end)   ;  visited[ end ] = 1   ; step[1] = 0 ;  
    
    while(!Q[0].empty() || !Q[1].empty()){
         idx = (step[0] + step[1]) & 1 ;  step[idx] ++ ;
         cnt = Q[idx].size() ;
         while(cnt -- ){
              nowState = Q[idx].front() ; Q[idx].pop() ;
              decode(nowState , now , 9);
              for(i = 0 ; i < 4 ; ++ i){
                      nextState = extends(now , i );
                      if(nextState == -1 || visited[ nextState ] == idx )
                         continue ;
                      if(visited[ nextState ] == (idx^1) ){
                           if(idx == 0 ){
                              forward = nowState  ;  mid = i ;  
                              backward = nextState ;
                           } else {
                              forward = nextState ;  mid = (i+2)%4 ; 
                              backward = nowState ;
                           }
                           return 0 ;
                      }else{
                           visited[ nextState ] = idx ; 
                           pid[ nextState ] = nowState ; 
                           move[ nextState ] = ( idx==0 ? i : (i+2)%4 ) ;
                           Q[idx].push(nextState);
                      }
              }
         }
    }
    return -1 ;
}

vector<int> ans ;

/*
* 双向广度优先搜索构造解比较麻烦。 
* 从相遇点开始，往两边拓展，直到找到两端的源即可。 
*/
void solve(){
    int res = dbfs() , i;
    if(res !=-1 ){
        ans.clear() ;
        while(pid[ forward ] != -1 ){
             ans.push_back(move[ forward ]);
             forward = pid[ forward ] ;
        }
        reverse(ans.begin() , ans.end());
        ans.push_back(mid);
        while(pid[ backward ]!= -1 ){
             ans.push_back( move[ backward ]);
             backward = pid[ backward ];
        }
        
        for(i = 0 ; i < ans.size() ; ++ i)  
            printf("%c" , CHAR[ ans[i] ]);
        printf("\n");
    }else{
        cout << "unsolvable" << endl ;
    }
}

int main(){
    int i ; 
    char wd[2] ;
    while(scanf("%s" , wd)!=EOF){
          start[0] = (wd[0]=='x' ? 0 : wd[0]-'0') ;
          for(i = 1 ; i < 9 ; ++ i ){
             scanf("%s" , wd);
             start[i]  = (wd[0]=='x' ? 0 : wd[0]-'0') ;
          } 
          solve();
    }
    return 0 ;
}
