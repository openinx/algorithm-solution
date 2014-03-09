#include <iostream>
using namespace std ;

const int MaxSize=1000000+2 ;
__int64 phi[MaxSize] ;

/*==================================================*\
|递推求欧拉函数phi(i)
\*==================================================*/
void getphi(){
    int i, j ;
    for (i = 2; i <= MaxSize; i++)
        phi[i] = i;
    for (i = 2; i <= MaxSize; i += 2)
        phi[i] /= 2;
    for (i = 3; i <= MaxSize; i += 2){
        if(phi[i] == i) {
            for (j = i; j <= MaxSize; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void init()
{
    int i ;
    for( i=2; i<MaxSize; ++i ){
        phi[i] += phi[i-1] ;
    }
}

int main()
{
    
    getphi() ;
    init() ;
    int n ;
    while( scanf("%d", &n), n ){
        printf("%I64d\n", phi[n] ) ;
    }
    return 0 ;
}

