#include<iostream>

using namespace std ;

typedef __int64 lld  ;
const int maxn = 505 ; 
const lld P[] = {990631 , 3000251 } , Q[] = {1000081 , 10000019 } ;

struct node{
       lld code ;
       int x , y , next  ;
}; 

node  e[maxn*maxn] ;
int   es , Hash[1000082] ;

void initHash(){
     es = 0 ;
     memset(Hash , -1 ,sizeof(Hash));  
}

void ins(lld code0 , lld code1 , int x, int y){
     e[es].x = x , e[es].y = y , e[es].code = code1 ;  
     e[es].next = Hash[code0] ;  Hash[code0] = es ++ ;  
}

int sch(lld code0 , lld code1){ 
     for(int i = Hash[code0] ; i!=-1 ; i= e[i].next)
        if(code1 == e[i].code )  
            return i ;
     return -1 ;
}

char ch[maxn][maxn] ;
lld  code[maxn][maxn][2] ;
int  row , col , ax , ay , bx , by;

bool isOK(int M){
     int i , j , k ;
     lld  pow[2] , val[2] ;
     
     initHash();
     
     pow[0] = pow[1] = 1 ;
     for(j = 0 ; j < col ; ++ j) code[0][j][0] = code[0][j][1] = 0 ; 
     for(i = M ; i >= 1 ; -- i){
           for(j = 0 ; j < col ; ++ j)
                 for(k = 0 ; k < 2 ; ++ k)
                     code[0][j][k] = (code[0][j][k] + ch[i-1][j]*pow[k] ) % Q[k] ;
           pow[0] = pow[0] * P[0] % Q[0] ; 
           pow[1] = pow[1] * P[0] % Q[1] ;
     }
     
     for(i = 1 ; i + M <= row ; ++ i){
           for(j = 0 ; j < col ; ++ j){
                for(k = 0 ; k < 2 ;++ k){
                     code[i][j][k] = (code[i-1][j][k]*P[0] - ch[i-1][j]*pow[k] + ch[i+M-1][j]) % Q[k] ;
                     code[i][j][k] = (code[i][j][k] + Q[k]) % Q[k] ;
                }
           }
     }
     
     for(i = 0 ; i + M <= row ; ++ i){
             pow[0] = pow[1] = 1 ;
             for(k = 0 ; k < 2 ; ++ k)  val[k] = 0 ;
             for(j = M ; j >= 1 ; --j){  
                  for(k = 0 ; k < 2 ; ++k)
                     val[k] = (val[k] + code[i][j-1][k] * pow[k]) % Q[k] ;
                  pow[0] = pow[0] * P[1] % Q[0] ;
                  pow[1] = pow[1] * P[1] % Q[1] ;
             }  
             
             int pos = sch(val[0] , val[1]);
             if(pos == -1){
                  ins(val[0] ,val[1] , i , 0 );    
             }else{
                  ax = i , ay = 0 ,  bx = e[pos].x , by = e[pos].y ;
                  return true ; 
             }
             
             for(j = 1 ; j + M <= col ; ++ j){
                   for(k = 0 ; k < 2 ; ++ k){
                       val[k] = (val[k]* P[1] - code[i][j-1][k] * pow[k] + code[i][j+M-1][k]) % Q[k] ;
                       val[k] = (val[k] + Q[k]) % Q[k] ;
                   }
                   pos = sch(val[0] , val[1]);
                   if(pos == -1){
                      ins(val[0] , val[1] , i , j );
                   }else{
                      ax = i , ay = j , bx = e[pos].x , by = e[pos].y ;
                      return true ;
                   }
             }
     }
     
     return false ;
}

void run(){
     int l = 1 , r = min(row , col) , mid , ans ; 
     ans = 0 ;
     while(l <= r){
           mid = (l + r)/2 ;
           if(isOK(mid)){
                ans = mid ,  l = mid + 1 ;
           }else{
                r = mid - 1 ;  
           }
     }
     printf("%d\n" ,ans);
     /*
     if(ans !=0 ){
          printf("%d\n" , ans);
          printf("%d %d\n" , ax+1 , ay+1);
          printf("%d %d\n" , bx+1 , by+1);
     }else{
          printf("0\n");
     }
     */
}

void solve(){
    scanf("%d%d" , &row , &col);
    for(int i = 0 ; i < row ; ++ i)
          scanf("%s" , ch[i]);
    run();   
}

int main(){
    
    //freopen("1.std.in" ,"r" ,stdin);  freopen("1.std.out" ,"w" ,stdout);
    
    //clock_t start , end ; 
    //start = clock() ;
    
    int testCase ; 
    scanf("%d" , &testCase);
    while(testCase--){
        solve();
    }
    
    //end = clock();
    //printf("time: %d ms\n" , (int)(end - start));
    
    //fclose(stdin); fclose(stdout);
    
    return 0 ;
}


