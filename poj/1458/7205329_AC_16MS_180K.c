#include<stdio.h>
#include<string.h>
#define mxn 50005
int s[mxn],t[mxn];
char ss[mxn],tt[mxn];

int Max(int x,int y)  {  return x>y ? x:y; }

int main()
{   
    int ls,lt,i,j;
    while(scanf("%s%s",ss,tt)!=EOF)
    {   
        ls=strlen(ss);  lt = strlen(tt);
        for(i=0;i<=lt;++i) t[i]=0;
        for(i=1;i<=ls; ++i)
        {
               s[0]=0;
               for(j=1;j<=lt;++j)
               {   
                   s[j] = Max(t[j],s[j-1]);
                   if(ss[i-1]==tt[j-1])  s[j] = Max(s[j],t[j-1]+1);
               }
               for(j=0;j<=lt;++j)  t[j] = s[j];
        }
        printf("%d\n",t[lt]);
    }
    return 0;
}
        
                  
        
    
