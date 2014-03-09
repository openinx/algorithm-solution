#include<stdio.h>
int main()
{   int test,tc,a,b;
    scanf("%d",&test);
    for(tc=0;tc<test;++tc)
    {   scanf("%d%d",&a,&b);
        if(a>=b)  printf("MMM BRAINS\n");
         else printf("NO BRAINS\n");
    }
    //while(1);
    return 0;
}          
