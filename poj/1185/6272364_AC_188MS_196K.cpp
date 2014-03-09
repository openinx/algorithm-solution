#include<stdio.h>
#include<stdlib.h>
#define MAX(x,y) x>y? x:y
int f1[61][61],f2[61][61],d[61][2],u[105];
int n,m,len;
void DP()
{  int i,j,k,p,v;
   for(i=0;i<61;i++)
     for(j=0;j<61;j++)
     f1[i][j]=f2[i][j]=-1;
   f1[0][0]=0;
   for(p=0;p<n;p++)
   {  
      for(i=0;i<61;i++)
       for(j=0;j<61;j++)
          if(f1[i][j]!=-1)
          {  v=d[i][0]|d[j][0];
             for(k=0;k<len;++k)
             if(!(d[k][0]&v||d[k][0]&u[p]))
             f2[j][k]=MAX(f2[j][k],d[k][1]+f1[i][j]);
          }
      for(i=0;i<61;i++)
        for(j=0;j<61;j++)
        { f1[i][j]=f2[i][j];
          f2[i][j]=-1;
        }
   }
   int max=0;
   for(i=0;i<61;i++)
     for(j=0;j<61;j++)
     max=MAX(max,f1[i][j]);
   printf("%d\n",max);
}              
int main()
{  int i,j,k,t,max;
   char s[11];
   while(scanf("%d%d",&n,&m)!=EOF)
   {  
      len=0;
      max=1<<m;
      for(i=0;i<max;i++)
        if(!(i<<1&i||i>>1&i||i<<2&i||i>>2&i)) 
        {   d[len][0]=i;
            d[len][1]=0;
            for(j=0;j<m;j++)
            if(1<<j&i) d[len][1]++;
            ++len;
        }    
      for(i=0;i<n;i++)
      { 
         scanf("%s",s);
         u[i]=0;
         for(j=m-1,t=0;j>=0;--j,++t)
         if(s[j]=='H')  u[i]+=1<<t;
      }
      DP();
   }
   //system("pause");
   return 0;
}        
         
   
