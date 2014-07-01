#include<stdio.h>
#define  MAXN 210
int a[MAXN] , b[MAXN] ;


int bit( int x , int i){
    return (x)&(1<<i) ? 1 : 0 ;
}

int f(int x ,int y){
    int i , cnt = 0 ;
    for(i = 0 ; i < 30 ; ++ i)
        if(bit(x ,i) != bit(y , i))  ++ cnt ;
    return cnt ;
}

int main(){
    
    //freopen("2.std.in" ,"r"  ,stdin);  freopen("2.std.out" , "w" ,stdout);
    
    int n, m , test , ans , val , tr , i , j ;
    scanf("%d" ,&test);
    while(test -- ){
             scanf("%d%d" , &n , &m);
             for(i = 0 ; i < n ; ++ i)  scanf("%d" , &a[i]);
             for(i = 0 ; i < m ; ++ i)  scanf("%d" , &b[i]);
             for(j = 0 ; j < m ; ++ j){
                   val = 1000009 ;  ans = 100 ;
                   for(i = 0 ; i < n ; ++ i)
                   {
                       tr = f(a[i] , b[j]);
                       if(tr < ans ){
                         ans = tr ;  val =  a[i] ;
                       }else if(tr == ans){
                         val =  val < a[i] ? val : a[i] ;
                       }
                   }
                   printf("%d\n" , val);
             }
    }
    
    //fclose(stdin);  fclose(stdout);
    
    return 0 ;
}
