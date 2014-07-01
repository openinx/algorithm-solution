#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std ;

char Month[][30]={"January" , "February" , "March" , "April" , "May" , "June" ,"July" , "August" , "September" ,"October" , "November" , "December" } ; 

int main(){
    
    //freopen("2.std.in" ,"r" , stdin);  freopen("2.std.out" ,"w" ,stdout);
    
    char  now[30] , next[30] ;
    int i , k , id ;
    while(scanf("%s%d" , now, &k)!=EOF){

         for(i = 0 ; i < 12 ;++ i)
            if(!strcmp(Month[i] , now))
                break ;
         printf("%s\n" , Month[(i+k)%12]);
            
    }
    
    //fclose(stdin);  fclose(stdout); 
    
    return 0 ;    
}
