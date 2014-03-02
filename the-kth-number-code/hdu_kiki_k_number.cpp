#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std ;

const int maxn = 100005 ;

struct bit{
     int c[maxn] ; 
     void init(){
          memset(c , 0 ,sizeof(c));
     }
     int lowbit(int x){
         return x&(-x);
     }
     void add(int x ,int d){
          for( ; x < maxn ; x+=lowbit(x)) c[x]+=d ; 
     }
     int getsum(int x){ 
          int ans = 0 ;
          for( ; x>0 ; x-=lowbit(x))  ans +=c[x] ; 
          return ans ;
     }
     int getkth(int k){
          int ans = 0 , cnt = 0 , i ;
          for(i = 20 ; i>=0 ; --i){
                ans += 1<<i ;
                if(ans>=maxn||cnt+c[ans]>=k) ans-=1<<i ;
                else cnt +=c[ans] ;      
          }
          return ans+1 ; 
     }
};

int main(){
    bit fuck ;
    int OPE , cmd , x , y ;
    while(scanf("%d" ,&OPE)!=EOF){
         fuck.init() ;
         while(OPE--){
               scanf("%d" , &cmd);
               switch(cmd){
                     case 0 : 
                          scanf("%d" , &x);  fuck.add(x , 1);  
                          break ;
                     case 1 : 
                          scanf("%d" , &y);  
                          if(fuck.getsum(y)-fuck.getsum(y-1)==0){
                               printf("No Elment!\n");
                          }else {
                               fuck.add(y , -1) ;
                          }
                          break ; 
                     case 2 : 
                          scanf("%d%d" , &x ,&y);
                          if(fuck.getsum(maxn-1)-fuck.getsum(x) < y){
                                 printf("Not Find!\n");
                          }else{
                                 int k = fuck.getsum(x) + y ;
                                 printf("%d\n" , fuck.getkth(k));
                          }
                     default:
                          break ;
               }
         }
    } 
    //system("pause");
    return 0 ;
}










