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

const int fac[]={1 , 1 , 2 ,6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800};
const int MAXN = 363000 ;
const int dx[] = {-1 , 0 , 1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1};

int move[MAXN] , pid[MAXN] , visited[MAXN] ;
int forward , backward , mid ;
int start[9] , finish[9] ={1 ,2 ,3 ,4 , 5 , 6 , 7 , 8 , 0 } ;

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

int extends(int *now , int i ){
    int k , xpos , x , y , nextState = -1; 
    for( k = 0 ; k < 9 && now[k] ; ++ k) ; xpos = k ;
    
    //cout << "x:=" << xpos << endl ;
    
    x = xpos / 3 + dx[i] ;  y = xpos % 3 + dy[i] ;
    
    //cout << "x:=" << x << "  " << "y:=" << y << endl ;
    
    if(!(x<0||y<0||x>2||y>2)){
          swap(now[xpos] , now[ 3*x+y ]);
          nextState = encode(now , 9 );
          swap(now[xpos] , now[ 3*x+y ]);
    }
    return nextState ;
}


void  showState(int x){
      int a[9] , i , j; 
      decode(x , a , 9);
      
      cout << "code is:" << x << endl ;
      
      for(i = 0 ; i < 3 ; ++ i){
        for(j = 0 ; j < 3 ; ++ j)
             cout << " " << a[3*i+j]  ;
            cout << endl; 
      }
      cout << endl ;
}

int dbfs(){
    int i , j , step[2] , begin , end , idx , cnt , nowState , nextState , now[9] , next[9]; 
    
    queue<int> Q[2] ;
    memset(pid , -1 ,sizeof(pid));
    memset(visited , -1 , sizeof(visited));
    
    begin = encode(start  , 9);  
    end = encode(finish , 9);
    if(begin == end ) return 0 ;
    
    Q[0].push(begin) ;  visited[ begin ] = 0 ; step[0] = 0 ;   //showState(begin) ; 
    Q[1].push(end)   ;  visited[ end ] = 1   ; step[1] = 0 ;   //showState(end) ;
    
    
    
    
    
    while(!Q[0].empty() || !Q[1].empty()){
         idx = (step[0] + step[1]) & 1 ;  step[idx] ++ ;
         cnt = Q[idx].size() ;
         while(cnt -- ){
              nowState = Q[idx].front() ; Q[idx].pop() ;
              decode(nowState , now , 9);
              
              
              //cout << "previous:" << endl ;showState(nowState); system("pause");
              
              for(i = 0 ; i < 4 ; ++ i){
                      nextState = extends(now , i );
                      
                      if(nextState == -1 || visited[ nextState ] == idx )
                         continue ;
                      
                       //cout << "extends["<<i<<"]" << endl ; showState(nextState); system("pause");
                      //cout << "visited["<<nextState<<"]=" << visited[nextState] << endl ;
                      //cout << visited [92327] << endl ;
                      if(visited[ nextState ] == (idx^1) ){
                                  //cout << (idx^1) << endl ;
                           //cout <<"strange:" << endl ; showState(nextState)  ; system("pause");
                           
                           if(idx == 0 ){
                              forward = nowState  ;  mid = i ;  
                              backward = nextState ;
                           } else {
                              forward = nextState ;  mid = (i+2)%2 ; 
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
int main(){
    
    //int x[] = {2 , 4 , 1 , 5 , 8 , 7 , 6, 0 } , y[] = {2 , 3 , 4 , 1 , 5 , 0 , 7 , 6 , 8};
    //cout << (encode(x , 9)) << endl ;
    //cout << (encode(y , 9)) << endl ;
    
    //showState(encode(finish , 9));
    //int x = extends(finish , 0) ;
    //showState(x) ; 
    
    
    int i ; 
    char wd[2] , CHAR[]  = "urdl" ;
    for(i = 0 ; i < 9 ; ++ i){
         scanf("%s" ,wd);
         start[i]  = (wd[0]=='x' ? 0 : wd[0]-'0') ; 
    }
    
    //showState(encode(start , 9));
    //showState(encode(finish,9));
    
    
    int res = dbfs();
    if(res !=-1 ){
        ans.clear() ;
        while(pid[ forward ] != -1 ){
             ans.push_back(move[ forward ]);
             forward = pid[ forward ] ;
        }
        //showState(forward);
        //cout << "size:" << ans.size() << endl ;
        
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
    //system("pause");
    return 0 ;
}
