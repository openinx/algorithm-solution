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
const int MAXN = 100 ;
const int MAXS = 30  ; 
const int MyTable[][4]={
      { 1 , -1 , 1 ,  1 },
      {-1 , -1 , 0 , -2 },
      { 1 , -2 , 1 ,  1 },
      {-1 , -1 ,-2 ,  0 }};

int H[MAXS] ;

int index(char c){
    if(c == '+' || c == '-' || c == '*')  return 0 ;
    if(c == '(')  return 1 ;
    if(c == ')')  return 2 ;
    if(c == '#')  return 3 ;
}

int cmp(char x , char y){
    int ix =  index(x) , iy = index(y) ;
    return MyTable[ix][iy];
}

int Evaluate(char *info ){
    int len = strlen(info) , idx , a , b , c  ;
    char *in = info , th ;
    stack<char> ope ;
    stack<int>  var ;
    *(in + len) = '#' ;  *(in + len + 1) = '\0' ; 
    ope.push('#') ;   while(*in==' ') in ++ ;
    while(!(*in=='#' && ope.top()=='#')){
         //cout << *in << endl ;   system("pause");
         if(isdigit(*in)){
               var.push(*in-'0') ;      ++in ; while(*in==' ') in ++ ;
         }else if(isalpha(*in)){    
               var.push(H[*in-'a']);    ++in ; while(*in==' ') in ++ ;
         }else{
               //cout << "compare("<<ope.top()<<","<<*in<<"):=" <<cmp(ope.top() , *in) << endl ;
               switch(cmp(ope.top() , *in)){
                   
                   case -1: 
                        ope.push(*in);  ++in ; while(*in==' ') in ++ ;  //cout << "hello world  " ; 
                        break ;
                   case  0: 
                        ope.pop() ;     ++in ; while(*in==' ') in ++ ;
                        break ;
                   case +1: 
                        th = ope.top() ;   ope.pop() ;
                        b  = var.top() ;   var.pop() ; 
                        a  = var.top() ;   var.pop() ;
                        if(th == '+')  c = a + b ;
                        if(th == '-')  c = a - b ;
                        if(th == '*')  c = a * b ;
                        var.push(c);
                        break ;
               }
         }
    }
    return var.top() ;
}

void keep(char *s){
     for( ; *s ; s ++) if(*s<='Z' && *s>='A')  *s = *s-'A' + 'a' ;
}

int main(){
    int acase , i , j ; 
    char  info_a[MAXN] , info_b[MAXN] ;
    scanf("%d" ,&acase);  getchar();
    while(acase--){
         gets(info_a);  keep(info_a);   //cout << info_a << endl ;
         gets(info_b);  keep(info_b);   //cout << info_b << endl ;
         bool ok = true ;
         for(i = 0 ; i < 20 ; ++ i){
               for(j = 0 ; j < MAXS ; ++ j)  H[j] = rand()%23 ;
               if(Evaluate(info_a) != Evaluate(info_b)){
                    ok = false ;  break ;
               }
         }
         if(ok){
              printf("YES\n");
         }else{
              printf("NO\n");
         }
    }
    //system("pause");
    return 0 ;
}
