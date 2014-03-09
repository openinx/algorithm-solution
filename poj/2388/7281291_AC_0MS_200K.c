#include<stdio.h>
#define maxn 10005

int c[maxn],n;
void Qsort(int *a,int l,int r)
{    
     int i,j,x,t;
     if(l>=r) return ;
     x = a[l] , i = l,j = r+1;
     while(1)
     {   
          while((i<r) && a[++i]<x);
          while(a[--j] > x);
          if(i>=j) break;
          t = a[i] , a[i] = a[j] , a[j] = t;
     }
     a[l] = a[j] , a[j] = x;
     Qsort(a,l,j-1);
     Qsort(a,j+1,r);
}

int main()
{   
    int i;
    scanf("%d",&n);
    for(i = 1;i<=n;++i) scanf("%d",&c[i]);
    Qsort(c,1,n);
    printf("%d\n",c[ (1+n)/2 ]);
    return 0;
}
      
    
