#include<stdio.h>
#include<stdlib.h>
#define _MAX_ 60000
#define MAX(x,y) x>y? x:y
char s[201][11];
long n,m,BIG;
long f[_MAX_],d[_MAX_];
long ww[11],*w,*N,NU[11],qq[11],*qc;
void Translate(long *wi,long t)
{  long i,j=0;
   for(i=0;i<10;i++) wi[i]=0;
   while(t){wi[j++]=t%3;t=t/3;}
}
void ComeBack(long *wi,long &t)
{   long i,c=1;
    t=0;
    for(i=0;i<10;i++)
    {  t+=wi[i]*c;
       c*=3;
    }
}     
bool IsInBorad(long x)
{  if(x<0||x>=m) return false;
   return true;
}   
void DFS(long t,long x,long p)
{  long i,j,k,c;
   if(t>=m)
   {  k=0;
      for(i=0;i<m;i++) if(N[i]==2) ++k;
      ComeBack(N,c);
      d[c]=MAX(d[c],k+f[x]);           
      return;     
   }
   if(qc[t]==1) N[t]=1;
   else if(qc[t]>=2) N[t]=0;
   DFS(t+1,x,p);
   if(qc[t]==3)
    if(!IsInBorad(t-1)||N[t-1]!=2)
     if(!IsInBorad(t-2)||N[t-2]!=2)
      if(s[p][t]=='P')
      {  N[t]=2;
         DFS(t+1,x,p); 
         N[t]=0;
      }
}        
void Max_PH()
{   long i,j,k,p;
    for(i=0;i<BIG;i++) f[i]=d[i]=-1;
    f[0]=0;
    for(p=0;p<n;p++)
    {  for(i=0;i<BIG;i++)
       if(f[i]!=-1)
       {   Translate(w,i);
           for(j=0;j<10;j++) qc[j]=1;
           for(j=0;j<m;j++)  qc[j]=3-w[j];   
           DFS(0,i,p);
       }
       for(i=0;i<BIG;i++) 
       {  f[i]=d[i];
          d[i]=-1;
       }
    }
    long max=0;
    for(i=0;i<BIG;i++)
    { if(f[i]==-1) continue;
      max=MAX(max,f[i]);
    }   
    printf("%ld\n",max);    
}                  
int main()
{  long i;
   w=ww;
   qc=qq;
   N=NU;
   while(scanf("%ld%ld",&n,&m)!=EOF)
   {  for(i=0;i<n;i++)
      scanf("%s",s[i]);
      BIG=1;
      for(i=0;i<m;i++) BIG=BIG*3;
      Max_PH();
   }
   //system("pause");
   return 0;
}     
   
