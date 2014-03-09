#include<stdio.h>
int  main()
{   int  n,i;
      float R,C;
   while (scanf("%s%d",R,n)!=EOF);
   C=R;
   for(i=0;i<=n;i++)
   C=R*C;
   printf("%s\n",C);
  return 0;
}