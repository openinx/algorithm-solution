#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std ;
const int maxn = 100005 ; 
typedef __int64 lld ;
lld a[maxn] ; 
lld b[maxn] ; 

inline int lowbit(int x) { return x&(-x) ; }

void update(lld *arr , int x ,int d){
     for( ; x<maxn ; x+=lowbit(x))  arr[x]+=d ;
}

lld getsum(lld *arr , int x ){
     lld res = 0 ;
     for( ; x>0 ; x-=lowbit(x))  res += arr[x] ;
     return res ;
}

int getkth(lld *arr , int k){
     lld ans = 0 , cnt = 0 ;
     for(int i = 20 ; i >= 0 ; --i){
          ans += 1<<i ;
          if(ans >= maxn || cnt+arr[ans]>=k) ans-=1<<i ;
          else cnt+=arr[ans] ;
     }
     return ans+1 ;
}

double average(int x ,int y){
       double totscore = 0.0 , totn = y-x + 1 , t0 , t1 ; 
       lld vx = getkth(a , x) , vy = getkth(a , y) ;
       t0= vx*(x - getsum(a , vx-1)-1) + vy * (getsum(a , vy) - y) ;
       t1= getsum(b , vy) -  getsum(b , vx-1);
       totscore = t1 - t0 ;
       return totscore/totn ; 
}

int main(){
    int acase , n , cmd , x , y , gs ;
    double totscore ,  totn ;
    scanf("%d" ,&acase);
    while(acase--){
         scanf("%d" ,&n);
         gs = 0 ; 
         memset(a ,0 , sizeof(a));  
         memset(b ,0 , sizeof(b));
         while(n--){
               scanf("%d" ,&cmd);  //printf("girls : %d \n" , gs );
               switch(cmd){
                   case 0 : scanf("%d" , &x);  
                            update(a , x , 1 ) ; update(b , x , x) ;  ++ gs ;  
                        break ;
                   case 1 : scanf("%d" , &x);  
                            update(a , x , -1) ; update(b , x ,-x) ;  -- gs ;  
                        break ;
                   case 2 : scanf("%d" , &x);  
                            printf("%I64d\n" , getsum(a , x)-getsum(a , x-1));    
                        break ; 
                   case 3 : scanf("%d" , &x);  
                            printf("%d\n" , getkth(a , gs-x+1));               
                        break ;
                   case 4 : scanf("%d%d" , &x , &y);  
                            printf("%I64d\n" , getsum(a ,y)-getsum(a ,x-1)); 
                        break ;
                   case 5 : scanf("%d%d" , &x , &y);
                            printf("%0.3lf\n" ,average(gs-x+1 , gs-y+1));
                        break ; 
                   case 6 : printf("%d\n" , gs);
                        break ;
               }
         }
    }
    system("pause");
    return  0 ;
}
