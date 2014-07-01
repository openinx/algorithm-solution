#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>

using namespace std ;

int n , caseNumber , c[1001] ,  cnt , ans[1001] ;

typedef struct node{
     int id  ; 
     struct node *next ;
}Node , *LinkNode ;

Node First ;
LinkNode head , PRE ; 

LinkNode getNext(LinkNode LN){
         if(LN->next == NULL ){
              PRE = head ;   
              return head->next ;
         }else{
              PRE = LN ; 
              return LN->next ;
         } 
}

void solve(){
     LinkNode LN , FRE ; 
     head = &First ; head->next = NULL ; 
     for(int i = n ; i >=1 ; -- i ){
           LN = new Node ; 
           LN->id = i ; LN->next = head->next ;
           head->next = LN ;  
     }
     LN = getNext(head) ; 
     for(int i = 1 ; i <= n ; ++ i){
           cnt = 1 ; 
           while(cnt < i ){
               LN = getNext(LN);  ++ cnt ; 
           }
           ans[ LN->id ] = i ; 
           PRE->next = LN->next ;  FRE = LN ; LN = getNext(LN) ; 
           delete FRE ; 
     }
}

int main(){
    
    //freopen("1.std.in" , "r" , stdin);
    //freopen("1.std.out" , "w" , stdout);
    
    int  i ;
    cin >> caseNumber ; 
    while(caseNumber--){
          cin >> n ; 
          for(i = 1 ; i <= n ; ++ i)  cin >> c[i] ; 
          memset(ans , 0 , sizeof(ans));
          solve();
          cout << c[ ans[1] ] ; 
          for(i = 2 ; i <= n ; ++ i) 
             cout << " " << c[ ans[i] ] ;
          cout << endl ; 
    }     
    //system("pause");
    return 0 ;
}
