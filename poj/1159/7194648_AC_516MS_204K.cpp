#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 5005;

char ch[maxn];
int s[maxn],t[maxn];

inline int Min(int a,int b) {return a<b ? a:b ;}

int main()
{    
     int i,j,len;
     scanf("%d",&len);
     scanf("%s",ch);
     t[len-1]=1;
     for(i=len-2;i>=0;--i)
     {  
           s[i]=0;
           for(j=i+1;j<len;++j)
           {
               s[j]=Min(s[j-1],t[j])+1;
               if(ch[i]==ch[j])  s[j] = Min(s[j],t[j-1]);                    
           }
           for(j=0;j<len;++j)  t[j] = s[j];
     }
     printf("%d\n",t[len-1]);
     return 0;
}

