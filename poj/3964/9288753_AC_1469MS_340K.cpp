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

const int MAXN = 10008  ;
const int MAXM = 1231   ;
int Prime[MAXN] , is[MAXN] , ps ;

void initPrime(){
     memset(is , 0 , sizeof(is));
     ps = 0 ;
     for(int i = 2 ; i < MAXN ; ++ i)
       if(!is[i]){
          Prime[ps ++ ] = i ; 
          for(int j = i + i ; j < MAXN ; j += i)
             is[j] = 1 ; 
     }
     //cout << is[10007] << endl ;
     //cout << ps << endl ; 
}

void getStanderSplit(int n , int *PrimeExp ){
     int i ;
     memset(PrimeExp , 0 , sizeof(int) * MAXM ) ;      
     for(i = 0 ; i < ps && Prime[i] <= n ; ++ i){
            int MyP = Prime[i] ;
            while(MyP <= n ){
               PrimeExp[i] += n / MyP ;
               MyP *= Prime[i] ; 
            } 
     }
}

struct node{
     int Exp[MAXM] ; 
     void init(int *_exp){
          for(int i = 0 ; i < MAXM ; ++ i)  
             Exp[i] = _exp[i] ; 
     }
     node add(const node &that)const{
          node res ; 
          for(int i = 0 ; i < MAXM ;++ i)
             res.Exp[i] = Exp[i] + that.Exp[i] ; 
          return res ;
     }
     node subtract(const node &that)const{
          node res ; 
          for(int i = 0 ; i < MAXM ; ++i)
             res.Exp[i] = Exp[i] - that.Exp[i] ; 
          return res ;
     }
     bool largerThan(const node &that)const{
          for(int i = 0 ; i < MAXM ; ++ i)
              if(!(Exp[i]>=that.Exp[i])) return false ; 
          return true ;
     }
     int getMaxFactorial()const{
         node c ; 
         int l = 1 , r = 10008 , mid , ans = 1;
         while(l <= r ){
               mid = (l + r) >> 1 ; 
               getStanderSplit(mid , c.Exp);
               if((*this).largerThan(c)){
                     ans = mid ; l = mid + 1 ;
               }else{
                     r = mid - 1 ;
               }
         }
         return ans ; 
     } 
     int getMaxMulitply(int n){
         node that ; 
         getStanderSplit(n , that.Exp);
         int k = 0x7FFFFFFF , i  ; 
         for(i = 0 ; i < MAXM ; ++ i)
           if(that.Exp[i] > 0 )
              k = min(k , Exp[i] / that.Exp[i]);
         for(i = 0 ; i < MAXM ; ++ i)
            Exp[i] -= k * that.Exp[i] ; 
         return k ;
     }
     void out(){
          for(int i = 0 ; i < MAXM ; ++ i )
              if(Exp[i]) printf("#%d\n" , Exp[i]);
          printf("\n");
     }
};

void test(){
    node a , b , c ; 
    getStanderSplit(1500 , a.Exp);
    getStanderSplit(1000 , b.Exp);
    c = a.subtract(b) ; 
    int x = c.getMaxFactorial() , k ;
    k = c.getMaxMulitply(100) ; 
    cout << "n!=" << x << " and k=" << k << endl ;
}

int pi , qi ;
node P , Q , Pi , Qi ; 

vector< pair<int , int> >  ans ;

int main(){
    initPrime();
    int n , m , i ; 
    while(scanf("%d%d" , &n ,&m)!=EOF){
          memset(P.Exp , 0 , sizeof(int)*MAXM);
          memset(Q.Exp , 0 , sizeof(int)*MAXM);
          for(i = 0 ; i < n ; ++ i)  scanf("%d" , &pi) , getStanderSplit(pi , Pi.Exp) , P = P.add(Pi) ;
          for(i = 0 ; i < m ; ++ i)  scanf("%d" , &qi) , getStanderSplit(qi , Qi.Exp) , Q = Q.add(Qi) ;
          //P.out() ;
          if(!P.largerThan(Q)){
                printf("-1\n"); continue ;
          }
          P = P.subtract(Q) ;
          ans.clear(); 
          while(1){
                int r , s;
                r = P.getMaxFactorial() ;
                s = P.getMaxMulitply(r) ; 
                if(r == 1 ) break ;
                ans.push_back(pair<int,int>(r , s));
          }
          printf("%d\n" , ans.size());
          for(i = 0 ; i < ans.size() ; ++ i)
            printf("%d %d\n" , ans[i].first , ans[i].second);
    }
    //system("pause");
    return 0 ;
}
