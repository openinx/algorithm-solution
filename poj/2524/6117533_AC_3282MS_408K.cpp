#include<stdio.h>
#include<stdlib.h>
#define size 50002
long s[size];
bool u[size];
long n,m;
void Init()
{  long i;
   for(i=1;i<=n;i++)
   { s[i]=i;
     u[i]=false;
   }  
}
long find_parent(long k)
{  while(k!=s[k]) k=s[k];
   return k;
}        
int main()
{  long i,j,x,y,stu1,stu2,test=0;
   scanf("%ld%ld",&n,&m);
   while(n&&m)
   {  Init();
      for(i=1;i<=m;i++)
      { scanf("%ld%ld",&stu1,&stu2);
        x=find_parent(stu1);
        y=find_parent(stu2);
        if(x==y) continue;
        s[x]=s[y];
        for(j=1;j<=n;j++)
        if(s[j]==x) s[j]=y;
      }
      //for(i=1;i<=n;i++) printf("%ld ",s[i]);
     //printf("\n");
      for(i=1;i<=n;i++)
      u[s[i]]=true;
      j=0;
      for(i=1;i<=n;i++)
      if(u[i]) j++;
      printf("Case %ld: %ld\n",++test,j);
      scanf("%ld%ld",&n,&m);
   }
   //system("pause");
   return 0;
}      
        
        
