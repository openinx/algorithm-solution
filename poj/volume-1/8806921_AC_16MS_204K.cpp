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
#define  LLD  "%lld"
using namespace std ;

typedef long long lld ;

const int MAXN = 2005 ;

int a[MAXN] , b[MAXN] , c[MAXN] , d[MAXN] , as , bs , cs , ds ;

int main(){
    int acase , i , j , k;
    scanf("%d" , &acase);
    while(acase--){
        fill(a , a + MAXN , 0 ); 
        fill(b , b + MAXN , 0 );
        fill(c , c + MAXN , 0 );
        fill(d , d + MAXN , 0 );
        scanf("%d" , &as);  for(i = as-1 ; i >= 0 ; --i) scanf("%d" , &a[i]);
        scanf("%d" , &bs);  for(i = bs-1 ; i >= 0 ; --i) scanf("%d" , &b[i]);
        scanf("%d" , &cs);  for(i = cs-1 ; i >= 0 ; --i) scanf("%d" , &c[i]);
        for(i = 0 ; i < as ; ++ i)
           for(j = 0 ; j < bs ; ++ j)
             d[i+j] = (d[i+j] + a[i] * b[j])&1 ;
        for(i = MAXN-1 ; i>= cs-1 ; --i)
           if(d[i]) 
              for(j = cs-1 , k = i ; j>=0 ; --j , --k)
                  d[k]^= c[j] ;
        ds = MAXN ; 
        while(!d[ds-1] && ds) -- ds ;
        printf("%d" , ds); 
        for(i = ds-1 ; i>=0 ; --i) printf(" %d" , d[i]);
        printf("\n");
    }
    //system("pause");
    return 0 ;
}
