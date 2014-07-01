#include<iostream>
using namespace std ; 

const  int maxn = 101 ;


/*
    数据格式：
    CaseNumber 
    N M K 
    ....
    ....
    ....

*/


void special_case0(){
    
    printf("\n\n");
    
    printf("3 4 3\n");
    printf("T.*.\n");
    printf("*.*.\n");
    printf("...J\n");
    printf("3 3 3\n");
}


void special_case1(){
   
   printf("\n\n");
   
   printf("5 5 4\n");
   printf("T..*.\n");
   printf("*.*..\n");
   printf("*...*\n");
   printf("..*.*\n");
   printf("**J.*\n");
   printf("1 2 2 3\n");
   
}



void random_case(int N , int M , int K , int obstacle){
     
     printf("\n\n");
     
     printf("%d %d %d\n" , N , M , K);
     
     char  bd[200][200] ;
     int i , j , x, y , tx , ty , jx , jy , cx , cy ;
     int dx[] = {1,0,-1,0} , dy[] = {0,1,0,-1};
     
     for(i = 0 ; i < N ; ++ i)
        for(j = 0 ; j < M ;++ j)
        bd[i][j] = '.' ; 
     
     for(i = 0 ; i < obstacle ; ++ i){
         x = rand() % N  ;  y = rand() % M ; 
         bd[x][y] = '*' ;
     }
     
     tx = rand() % N ;   ty = rand() % M ;   bd[tx][ty] = 'T' ; 
     
     while(1){
          jx = rand()%N ;  jy = rand()%M ;
          if(!((jx == tx )&&(jy == ty)))  
              break ; 
     }
     bd[jx][jy] = 'J' ; 
     
     for(i = 0 ; i < N ; ++ i){
         for(j = 0 ; j < M ; ++ j)  printf("%c" , bd[i][j]);
         printf("\n");
     }
     
     
     for(int step = 0 ; step < K ; ++ step){
        
           int d ;
           while(1){
                 d = rand() % 4 ;
                 cx = jx + dx[d]  , cy = jy + dy[d] ; 
                 if((cx<0||cy<0||cx>=N||cy>=M)|| bd[cx][cy] == '*')   continue ;
                 break ; 
           } 
           
           jx = cx , jy = cy ;
           
           printf("%d " , d );
           
     }
     
     printf("\n");
}


int main(){
    
    //freopen("1.std.in", "w" , stdout);
    
    srand((int)time(NULL));

    printf("%d\n" , 10); 

    special_case0();  
    special_case1();  
    
    random_case(20 , 20 , 45 , 145);
    random_case(30 , 30 , 100, 560);
    random_case(100 , 100 , 100 , 1000);
    random_case(100 , 100 , 100 , 2000);
    random_case(10 , 10 , 70 , 56);
    random_case(35 , 78 , 100 , 700 );
    random_case(100 , 100 , 100 , 5000);
    random_case(5 , 5 , 14 , 15);

    //fclose(stdout);  
    
    return 0 ;
}
