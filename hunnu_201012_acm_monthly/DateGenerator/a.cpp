#include<iostream>
using namespace std ;

char Month[][30]={"January" , "February" , "March" , "April" , "May" , "June" ,"July" , "August" , "September" ,"October" , "November" , "December" } ; 

void random_case(){
     int id = rand()%12 , K = rand()%101; 
     
     printf("%s\n" , Month[id]);
     printf("%d\n" , K);
     
}

int main(){
    
    //freopen("1.std.in" ,"w" , stdout);
          
    srand((int)time(NULL));
    int testCase = 500 ;
    while(testCase--){
         random_case();
    }
    
    //fclose(stdout);
    
    return 0 ;
    
}
