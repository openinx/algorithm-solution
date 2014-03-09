#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

const int MAXN = 100005 ;

struct node{
     int id , next ;
};
int head[ MAXN ] , hid ;
node nd[ MAXN ] ;

void add_edge(int x ,int y ){
     nd[ hid ].id = y ;
     nd[ hid ].next = head[ x ] ;
     head[ x ] = hid ++ ;
}

int n , visit[ MAXN ] , value[ MAXN ]  ; 

int dfs(int r ){
     int k , s , scnt = 1 , t ;
     visit[r] = 1 ;
     value[r] = 0 ; 
     for(k = head[r] ; k != -1 ; k = nd[k].next ){
           s = nd[k].id  ; 
           if( visit[s] ) continue ;
           t = dfs(s) ;  //cout << "t :" << t << endl ;
           scnt += t ;
           value[r] = max(value[r] , t) ;
     }
     value[r] = max( value[r] , n - scnt ) ; 
     return scnt ;
}

int main(){
    int i , answer , x , y ;
    while(scanf("%d" ,&n)!=EOF){
        hid = 0 ; 
        memset(head , -1 ,sizeof(head));
        for(i = 2 ; i <= n ; ++ i){
            scanf("%d%d" ,&x , &y);
            add_edge(x , y);
            add_edge(y , x);
        }
        fill(visit , visit + n + 1 , 0) ;
        fill(value , value + n + 1 , 0) ;  
        dfs(1);
        answer = 0x7fffffff ; 
        for(i = 1 ; i <= n ; ++ i) 
           answer = min(answer , value[i]);
        bool is_first = true ; 
        for(i = 1 ; i <= n ; ++ i)
           if( answer == value[i] ){
                if( is_first ){
                      is_first = false ; 
                      cout << i ; 
                }else{
                      cout <<" " << i ;
                }
           }
        cout << endl ;    
    }
    //system("pause");
    return 0 ;
}
