#include<iostream>
using namespace std ;

const int MAXN = 16000004 ;
char  s[MAXN] ;
bool  table[MAXN] = {0} ; 
int   pos[300] ;

int main(){
    int  x ,ans , N , NC ,i ,j , slength , base ;
    scanf("%d%d" , &N ,&NC);  
    scanf("%s" ,s); 
    slength = strlen(s);
    memset(pos , -1 , sizeof(pos));
    for(i =j=0 ; i < slength ;++ i)  
       if(pos[s[i]]==-1)  pos[s[i]] = j++;

    //for(i = 0 ; i < slength ; ++i)  cout<<"value : "<<pos[s[i]]<<endl;
    
    base = 1 ; ans = x = 0 ;
    for(i = N-1 ; i>=0 ; --i){
          x += pos[s[i]]*base ; 
          base *= NC ;
          //cout<<"Hash :"<<x<<endl;
    } 
    table[x] = 1 ;  ++ ans ;
    for(i = 1 ; i + N <= slength ; ++i){
         x = x*NC - pos[s[i-1]]*base + pos[s[i+N-1]] ;
         if(table[x]==0){
              ++ ans ;   table[x] = 1 ;
         }
         //cout<<"Hash :"<<x<<endl;
    }
    printf("%d\n" , ans);
    //while(getchar());
    return 0 ;
}
