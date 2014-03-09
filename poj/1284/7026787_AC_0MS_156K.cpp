#include<stdio.h>
#include<math.h>
int split(int n)
{    int i,j,ans=n;
     while(n!=1)
     {    for(j=n,i=2;i<=floor(sqrt((double)n));++i)
              if(n%i==0) { j=i;break;}
          ans=ans-ans/j;
          while(n%j==0) n/=j;
     }
     return ans;
}

int main()
{    int n;
     while(scanf("%d",&n)!=EOF)
        printf("%d\n",split(n-1));
     return 0;
}
     
