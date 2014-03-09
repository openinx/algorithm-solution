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
#include<sstream>
using namespace std ;

const int MAXN = 210 ;
const int INF = 100000000 ; 
int dp[ MAXN ][ MAXN ] , value[ MAXN ] , n , m , isRoot[ MAXN ];
vector<int>  tree[ MAXN ] ; 

/*
  我为什么不相信自己呢？
  当我仔细设计的程序WA了之后，我一直找不到bug,果断去找BLOG,但是又觉得自己的思路没有错。
  原来dp[r][i] = min(dp[r][i] , dp[r][i-1] + value[r]) 这里写成而来valur[i]。
  当我认为是对的时候，一定要坚持自己的想法。 
*/

/*
   树形DP  
   dp[r][i]表示以r为根节点的子树选取i个节点的最小值。
   首先不考虑选取根节点，假设i全部用来选取r的子节点,这就是个经典的背包问题。
     先递归求子节点的状态，然后用滚动数组求背包问题。
   再考虑选取根节点的情况即可。 
   
   复杂度分析：
   对节点 root , 假设有 son(root)个子节点，那么求 root的所有状态耗时 son(root)*n*n . 
   sigma( son(root) *n * n) = O(n^3). 
*/

int dfs(int r){
     int k , s , i ,  j , sc = 1 ; 
     fill(dp[r] , dp[r]+n+1 , INF ) ;
     dp[r][0] = 0 ; 
//cout << "node :" << r << endl ;
     for(k = 0 ; k < tree[r].size() ; ++ k){
          s = tree[r][k] ; 
          sc += dfs(s) ;
          for(i = n ; i>=0 ; --i)
             for(j = 0 ; j <= i ; ++ j)
                dp[r][i] = min(dp[r][i] , dp[r][i-j] + dp[s][j]);
     }
     for(i = n ; i>sc  ; --i)
       dp[r][i] = min(dp[r][i] , dp[r][i-1] + value[r]);
     for(i = 1 ; i <= sc ; ++i)
       dp[r][i] = min(dp[r][i] , value[r]);
     return sc ; 
} 

int main(){
    int i , j , id , parent , children , answer ; 
    map<string ,int> country  ;
    string ss , name ;  
    while(getline(cin , ss) && ss.compare("#")){
        istringstream issm (ss) ;
        issm >> n >> m ;  
        country.clear() ; 
        fill(isRoot , isRoot + MAXN , true ) ;
        for(i = 0 ; i <= n ; ++ i)  
          tree[i].clear() ;
        id = 0 ; 
        for(i = 0 ; i < n ; ++ i){
             getline(cin , ss );
             istringstream iss(ss) ;
             iss >> name ; 
             if( country[ name ] == 0 )  
                country[ name ] = ++id ; 
             parent = country[ name ] ; 
             iss >> value[ parent ] ;
             while( iss >> name ){
                 if( country[ name ] == 0 )
                    country[ name ] = ++ id ;
                 children = country[ name ] ;
                 tree[ parent ].push_back( children ) ;  
                 isRoot[ children ] = false ; 
             }
        }
//cout << "ID : " << id << endl ;
        value[0] = INF ; 
        for(i = 1 ; i <= n ; ++ i)
           if(isRoot[i])
               tree[0].push_back(i) ;
        dfs(0);
        answer = INF ; 
        for(i = m ; i <= n ; ++ i)  
           answer = min(answer , dp[0][i]) ;
        cout << answer << endl ;
    }
//system("pause");
    return 0 ;
}
