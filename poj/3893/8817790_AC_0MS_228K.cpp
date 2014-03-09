#include<iostream>
using namespace std ;

char cmd[400000] ;
int  v[10009]   ;  

int main(){
    int index0 ,index1 , i , x , y , cn;
    memset(v , -1 ,sizeof(v));
    v[0] = 0 , v[1] = 1 ,v[2] = 2 ,v[3] = 3 ; 
    while(scanf("%d%s%d" ,&index0 , cmd ,&index1)!=EOF){
           x = v[index1] ;   cn = strlen(cmd);
           for(i = cn-1 ; i >=0 ; --i) 
              if(cmd[i]=='f')
                   x += (x%2 == 0 ? 3 : 1) ;
              else  if(cmd[i] == 'b')
                   x -= 2 ;
              else  if(cmd[i]== 'k')
                   printf("%d\n" , x);
              else  if(cmd[i]=='=')
                   printf("%c\n", v[index0] == x ? '=' : '#');
              else  
                   v[index0] = x ;
    }
    return 0 ;
}

