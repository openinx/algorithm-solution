#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std; 


int main(int argc, char **args)
{
    int n , k, a[100001] ; 
    while(scanf("%d%d", &n, &k)!=EOF)
    {
        for(int i = 1 ; i <= 2*n ; ++i)
        {
            a[i] = i ; 
        }
        for (int i = 0 ; i < k ; ++ i)
        {
            int x = 4 * i + 3 ; 
            int y = 4 * i + 4 ; 
            swap(a[x], a[y]);
        }
        for(int i = 1; i <= 2*n ; ++ i)
        {
            if (i == 1 ) 
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0 ; 
}
