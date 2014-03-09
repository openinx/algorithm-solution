#include<iostream>
#include<algorithm>
using namespace std ; 

typedef __int64 lld ;
const lld P[] = {1000001 , 999999} ; 
const lld Q[] = {1000003 , 2000003};
const lld MAXN = 100005 ; 

struct node{
       lld  y , next ;
};

node e[100010];
lld  es , hd[1000010] , alength , blength;
char a[MAXN] , b[MAXN] ;

void ins(lld x, lld y){
	  e[es].y = y , e[es].next = hd[x] , hd[x] = es ++ ;
}

bool sch(lld x, lld y){
     lld i ; 
	 for(i = hd[x] ; i!=-1 ; i =e[i].next)
		   if(e[i].y == y)  return 1 ;
     return 0 ;
}

bool isOK(lld len){
	 lld base0 , base1 , x , y , i ; 

	 es = 0 ;  memset(hd , -1 , sizeof(hd));

	 base0 = base1 = 1 ;  x = y = 0 ;
	 for(i = len -1 ; i>=0 ; --i){
	        x = (x + a[i] * base0) % Q[0] ; 
			y = (y + a[i] * base1) % Q[1] ; 
			base0 = base0 * P[0] % Q[0] ; 
			base1 = base1 * P[1] % Q[1] ;
	 }
	 ins(x , y);

	 for(i = 1 ; i+ len <= alength ; ++i ){
	        x = (x*P[0] - a[i-1]*base0 + a[i+len-1]) % Q[0] ; 
			y = (y*P[1] - a[i-1]*base1 + a[i+len-1]) % Q[1] ;
			x = (x + Q[0]) % Q[0] ;  
			y = (y + Q[1]) % Q[1]  ; 
			if(!sch(x,y))
				  ins(x , y);
	 }

	 base0 = base1 = 1 ; x = y = 0 ;
	 for(i = len-1 ; i>=0 ; --i){
	        x = (x + b[i] * base0 ) % Q[0] ; 
			y = (y + b[i] * base1 ) % Q[1] ; 
			base0 = base0 * P[0] % Q[0] ; 
			base1 = base1 * P[1] % Q[1] ;
	 }
	 if(sch(x,y))  return true ;

	 for(i = 1 ; i + len <= blength ; ++i){
	       x = (x * P[0]  - b[i-1]*base0 + b[i+len-1]) % Q[0] ; 
		   y = (y * P[1]  - b[i-1]*base1 + b[i+len-1]) % Q[1] ; 
		   x = (x + Q[0]) % Q[0] ;  
		   y = (y + Q[1]) % Q[1] ; 
		   if(sch(x,y))  return true ;
	 }

    return false ;
}

int main(){

	scanf("%s%s" , a ,b);
	
    alength = strlen(a) ; 
	blength = strlen(b) ; 

	int len = 0 , l = 1 , r = alength > blength ? blength : alength ; 

	while(l <= r){
	       int mid = (l + r)/2 ;
		   if(isOK(mid)){
		     len = mid ;    l = mid + 1;  //cout<<"LOOP"<<endl;
		   }else{
		        r = mid - 1;
		   }

	}
    
	printf("%d\n" , len);
    //system("pause");

	return 0 ;
}
