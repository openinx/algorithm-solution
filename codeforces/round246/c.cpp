#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<map>
#include<algorithm>

using namespace std ;


#define MAXN 100001

typedef pair<int, int> PII;

int p[MAXN], p_size = 0, is[MAXN] ;

int val[MAXN], ret[5 * MAXN][2], ret_size ;


map< int, int > mp; 


int get_primes(){
    p_size = 0 ;
    memset(is, 0 , sizeof(is));
    for(int i = 2 ; i < MAXN;  i += 1)
        if(is[i] == 0){
            for(int j = i + i ; j  < MAXN; j += i )
                is[j] = 1 ; 
            p[p_size ++ ] = i ; 
        }
}


int my_swap(int idx1, int idx2){
    int v1 = val[idx1], v2 = val[idx2];
    map<int, int>::iterator it ;
    mp[idx1] = v2; mp[idx2] = v1;
    swap(val[idx1], val[idx2]);
}

/*
int find_prime(int v){
    int m , l = 0 , r = p_size;
    while(l + 1 < r){
        m = (l + r) >> 1;
        if(p[m] == v)
            return p[m];
        if (p[m] < v)
            l = m ;
        else
            r = m - 1; 
    }
    return p[l];
}*/


int find_prime(int v){
    int t = p[0] ; 
    for(int i = 0 ; i < v ; ++ i){
        if(p[i] > v) break; 
        t = p[i];
    }
    return t;
}


void print_operation(int x, int y){
    while(x < y ){
        int d = y - x + 1 ; 
        int v = find_prime(d);
        ret[ret_size][0] = x ; ret[ret_size][1] = y ; ret_size ++ ;
        printf("=========> %d (x,y,d) = (%d,%d, %d)\n" , v, x, x + v - 1 , d);
//printf("%d %d\n", x ,  x + (*v) - 1);
        my_swap(val[x], val[x + v - 1]) ;
        x = x + v - 1 ; 
    }
}


int main(){
    int n ; 
    get_primes();
    while(scanf("%d", &n) !=EOF ){
        mp.clear();
        for(int i = 1 ; i <= n ; ++ i){
            scanf("%d", &val[i]);
            mp[ val[i] ] = i ; 
        }
        int start_idx, end_idx ; 
        ret_size = 0 ; 
        for(int i = 1 ; i <= n ; ++ i){
            map<int, int>::iterator it = mp.begin();
            start_idx = i ; end_idx = it->second ; 
            int min_value = it->first;
            print_operation(start_idx, end_idx);
            it = mp.find(min_value);
            mp.erase(it);
        }
        printf("%d\n", ret_size);
        for(int i = 0 ; i < ret_size ; ++ i)
            printf("%d %d\n", ret[i][0], ret[i][1]);
    }
    return 0 ; 
}


