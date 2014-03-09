#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std ;

const int MAXLINE = 1005 ; 
const int MAXCHAR = 200  ;

int lines ;
char line[MAXLINE][MAXCHAR] , wd[100] ;

vector<string> lwd[MAXLINE] ;
int pos[MAXLINE] , ps  ; 

int main(){
    int i , j ;
    
    lines = 0 ;  ps = 0 ; 
    while(gets(line[lines]) != NULL && strcmp(line[lines] ,"###"))  lines ++ ;
    
    for(i = 0 ; i < lines ; ++ i)  lwd[i].clear();
    
    for(i = 0 ; i < lines ; ++ i){
          char *s = line[i] ; 
          while(*s){
                while(*s==' ') s ++ ; 
                sscanf(s , "%s" , wd) ;
                lwd[i].push_back(string(wd));
                s += strlen(wd);
                while(*s==' ') s ++ ; 
          }
          ps = max((int)lwd[i].size() , ps );
    }
    
    pos[0] = 0 ;  
    for(i = 0 ; i < ps ; ++ i){
          int mx = 0 ; 
          for(j = 0 ; j < lines ; ++ j)  
             if(lwd[j].size() > i )  mx = max((int)lwd[j][i].length() , mx );
          pos[i+1] = pos[i] + mx + 1 ;
    }
    
    //for(i = 0 ; i <= ps ; ++ i) cout << pos[i] << endl ;
    
    
    int now = 0 ;
    for(i = 0 ; i < lines ; ++ i){
          now = 0 ;
          for(j = 0 ; j < lwd[i].size() ; ++ j){
               while(now < pos[j])  putchar(' ') , now ++ ;
               cout << lwd[i][j] ; 
               now += (int)lwd[i][j].length() ; 
          }
          cout << endl ;
    }
    
    //system("pause");
    return 0 ;
}
