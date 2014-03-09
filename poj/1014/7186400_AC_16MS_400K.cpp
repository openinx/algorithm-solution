#include<stdio.h>

#define maxn 70005

int d[maxn];

inline int Max(int a,int b)
{      return a > b ? a:b ;  }

int main()
{   
    int i,j,k,x[7],sum,v,c,t,cas=0;
    
    while(scanf("%d%d%d%d%d%d",&x[1],&x[2],&x[3],&x[4],&x[5],&x[6])!=EOF)
    {    
           if(!(x[1]||x[2]||x[3]||x[4]||x[5]||x[6]))  break;
           printf("Collection #%d:\n",++cas);
           for(sum = 0,i = 1; i<= 6; ++i)  sum  += i*x[i];
           if(sum%2==1)
           {   
               printf("Can't be divided.\n\n");
               continue;
           }
           for(i = 0;i <= sum/2;++i)  d[i] = 0;
           for(i=1;i<=6;++i)
           {
                 if(!x[i]) continue;
                 for(k=1,t = 0 ; (k<<1)<= x[i] ; k<<=1)
                 {       
                         t += k;
                         v = c = i*k;
                         for(j = sum /2 ; j >= c; --j)  d[j] = Max( d[j-1], Max(d[j],d[j-c] + v ) );
                 }
                 v = c = i * (x[i] - t);
                 for(j = sum /2 ; j >= c; --j)  d[j] = Max( d[j-1], Max(d[j],d[j-c] + v ) );
           }
           if(d[sum/2] == sum/2) 
              printf("Can be divided.\n\n"); 
           else 
              printf("Can't be divided.\n\n");
    }
    return 0;
}
