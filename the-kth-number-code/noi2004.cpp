#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std ;
const int D = 100005 ;
const int maxn = 5*D ; 

int n , addpay , minpay , arr[maxn] , h[maxn] ,hs ; 

inline int lowbit(int x){  return x&(-x) ;}

void update(int x ,int d){
     for( ; x < maxn ; x+=lowbit(x))  arr[x]+=d ;
}

void up(int i){
     int temp , x ; 
     while(i>1){
          x = i/2 ;
          if(h[i]<h[x]){
             temp = h[i] ; h[i] = h[x] ; h[x] = temp ;  
          }else  break ;
          i=x ;
     }
}

void down(int i){
     int temp , x ;
     while(2*i<=hs){
           x = 2*i ; 
           if(x+1<=hs && h[x+1] < h[x]) ++x ;
           if(h[x]<h[i]){
               temp = h[x] ; h[x] = h[i] ; h[i] = temp ; 
           }else break ;
           i = x ;
     }
}

int main(){
    int temp , i ,l , r , k , mid , ans , t0 ,t1 , rank , leave = 0  ;
    char cmd[3] ;
    scanf("%d%d" ,&n ,&minpay);  
    hs = addpay = 0 ;   memset(arr , 0 ,sizeof(arr));
    while(n--){
           scanf("%s%d" , cmd , &k);
           if(cmd[0]=='I'){
                if(k >= minpay){
                      k = k - addpay ;  h[++hs] = k ;  up(hs) ; 
                      update(k+D , 1) ;
                }
           }else if(cmd[0]=='A'){
                addpay += k ;
           }else if(cmd[0]=='S'){
                addpay -= k ;
                while(hs>=1 && (h[1]+addpay < minpay)){
                        temp = h[1] ; h[1] = h[hs] ; h[hs] = temp ; --hs ;  down(1);
                        update(temp+D , -1);    leave ++ ; 
                }
           }else if(cmd[0]=='F'){
                if(hs < k )  { printf("-1\n"); continue ;}
                int cnt = 0 , ans = 0 ;  rank = hs - k + 1 ;
                for(i = 20 ; i>= 0 ; --i){
                   ans += (1<<i) ;
                   if(ans>=maxn || cnt + arr[ans]>=rank)  ans-=(1<<i) ;
                   else cnt+=arr[ans] ;
                }
                printf("%d\n" , ans+1-D+addpay);
           }
    }
    printf("%d\n" , leave);
    //system("pause"); 
    return 0 ;
}
