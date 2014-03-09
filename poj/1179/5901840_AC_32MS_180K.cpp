#include<stdio.h>
#include<stdlib.h>
#define size 55
int v[size],n;
char e[size];
int m[size][size][2];
int min(int a,int b)
{ return ((a<b)? a:b);}
int max(int a,int b)
{ return ((a>b)? a:b);}
int circur(int start)
{  int vv[size],i,j,k,p,q,a,b,c,d,maxt,mint;
   char ee[size];
   for(i=0;i<n;i++)
   { j=(start+i)%n;
     vv[i]=v[j];
     ee[i+1]=e[(j+1)%n];
   }
  //for(i=0;i<n-1;i++) printf("%d%c",vv[i],ee[i+1]);
  //printf("%d",vv[n-1]);
  // printf("\n");
   for(i=0;i<n;i++) m[i][i][0]=m[i][i][1]=vv[i];
   for(i=n-2;i>=0;i--)
     for(j=i+1;j<=n-1;j++)
      { maxt=-20000;
        mint=20000;
        for(k=i;k<j;k++)
        { a=m[i][k][0];
          b=m[i][k][1];
          c=m[k+1][j][0];
          d=m[k+1][j][1];
          if(ee[k+1]=='t')
          { if(maxt<b+d)
            { m[i][j][1]=b+d;
              maxt=b+d;
            }
            if(mint>c+a)
            {  m[i][j][0]=c+a;
               mint=m[i][j][0];
            }
          }      
          else 
          {  p=max(a*c,a*d);
             q=max(b*c,b*d);
             if(maxt<max(p,q))  maxt=m[i][j][1]=max(p,q);   
             p=min(a*c,a*d);
             q=min(b*c,b*d);
             if(mint>min(p,q)) mint=m[i][j][0]=min(p,q);
          
          }
       }
     }  
  return m[0][n-1][1];     
}             
void Max_score()
{  int i,b[size],temp;
   for(i=0;i<n;i++)
   b[i]=circur(i);
   temp=b[0];
  // for(i=0;i<n;i++)
  // printf("%d ",b[i]);
  // printf("\n");
   for(i=1;i<n;i++)
   if(temp<b[i]) temp=b[i];
   printf("%d\n",temp);
   for(i=0;i<n;i++)
   if(temp==b[i])printf("%d ",i+1);
   printf("\n");
} 
int main()
{  int i;
   char c;
   while(scanf("%d",&n)!=EOF)
   { getchar();
     for(i=0;i<n;i++)
     { while((c=getchar())==' ');
       e[i]=c;
       scanf("%d",&v[i]);
     }  
    Max_score();
   }
   //system("pause");
   return 0;
}     
