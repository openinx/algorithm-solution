#include<stdio.h>
int main()
{   double e=2.5,jie=2;
    printf("n e\n- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int i=3;i<=9;i++)
    {   jie*=i;
        e+=1/(double)jie;
        printf("%d %0.9lf\n",i,e);
    }
    //while(1);
    return 0;
}        
