#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>


using namespace std ; 

typedef long long lld ; 

#define MAXN 100000
#define BIG_PRIME 1000000007


lld primer[MAXN], is[MAXN], size;

void init_primer(){
    lld i , j ; 
    size = 0 ; 
    memset(is, 0 ,sizeof(is));
    primer[size++] = 2 ; 
    for(i = 3 ; i < MAXN; i += 2)
        if(is[i] == 0 ){
            primer[size ++ ] = i ; 
            for(lld j = i ; j < MAXN; j += i ) is[j] = 1 ; 
        }
//for(i = 0 ; i < size ; ++ i) printf("%lld\n", primer[i]);
}


void print_map(map<lld, lld> m ){
    map<lld, lld>::iterator it ;
    for(it = m.begin(); it!=m.end(); it ++ ){
        printf("##(%lld, %lld)\n", it->first, it->second);
    }
}


map<lld, lld> divide_number(lld big){ 
    map<lld, lld> m ; 
    lld i , fac, cnt = 0 ; 
    while(big > 1){
        for(i = 0, fac=big; i < size; ++ i)
            if(big % primer[i] == 0){
                fac = primer[i]; break; 
            }
        cnt = 0 ; 
        while(big % fac == 0 )  { cnt ++ ;  big /= fac ; } 
        //printf("%lld-%lld\n", fac, cnt);
        m[fac] = cnt ;
    }
//print_map(m);
    return m ; 
}

lld combination(lld x, lld y){
    //  return C(x, y)
    lld i, j, result  = 1, n = max(y, x - y) ; 

    map<lld, lld> ret ; 
    map<lld, lld>::iterator it ;

    for(i = n + 1 ; i <= x ; ++ i){
        map<lld, lld> m = divide_number(i);
        for(it = m.begin(); it != m.end(); it ++ )
            ret[it->first] = ret[it->first] + (it->second) ; 
    }

    //print_map(ret);

    for(i = 2 ;  i<= x -n  ; ++ i){
        map<lld, lld> m = divide_number(i);
        //printf("------------------------\n");
        //print_map(m);
        for(it = m.begin(); it!=m.end(); it++)
            ret[it->first] = ret[it->first] - it->second ;
    }


    //printf("===========================divide==========================\n");

    //print_map(ret);

    for(it = ret.begin(); it != ret.end(); it ++ ){
        lld p = it->first, a = it->second;
        for(i = 0 ; i < a ; ++i)
            result = (result * p ) % BIG_PRIME ;
    }

    return result;
}


int main(){
    lld n , number ;
    init_primer();

    //print_map(divide_number(2));

    //printf("%lld\n", combination(2, 1));
    //printf("%lld\n", combination(6, 2));
    //printf("%lld\n", combination(500, 29));

    while( scanf("%lld", &n) !=EOF )
    {
        map<lld, lld>  ret ; 
        map<lld, lld>::iterator it;
        for(lld i = 0 ; i < n ; ++ i){
            scanf("%lld", &number);
            map<lld, lld> m = divide_number(number);
            for(it = m.begin(); it != m.end(); it ++ ){
                ret[it->first] = ret[it->first] + it->second ;
            }
        }
        //for(it = m.begin(); it != m.end(); it++ ) printf("##%lld-%lld\n", it->first, it->second);
        lld result = 1 ; 
        for(it = ret.begin(); it != ret.end(); it++ )
        {
            lld m_value = it->second ;
            result =  ( result * combination(n + m_value - 1 ,  m_value ) )  % BIG_PRIME ;
        }
        printf("%lld\n", result);
    }
    return 0 ;
}
