#include <stdio.h>
#include<stdlib.h>
int main()
{
    float t=0,a[12];
    int i;
    for(i=0;i<12;i++)
      scanf("%f",&a[i]);
    for(i=0;i<12;i++)
    {
    t+=a[i];
    }
    printf("$%0.2f\n",t/(float)12);
//    system("pause");
    return 0;
}
