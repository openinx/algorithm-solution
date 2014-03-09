#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 65
#define swap(x,y,z){z=x;x=y;y=z;}
bool IsSame(int *a,int *b,int n)
{  int i,j,t;
   bool check=false;
   for(i=0;i<n;i++)
   {  check=true;
      for(j=i,t=0;j<=n+i-1;j++,t++)
      if(a[t]!=b[j%n]) {check=false;break;}
      if(check) return true;
   }
   return false;
}
bool IsCircle(int *a,int *b,int *c,int n,int lenb)
{  int i,j,t,u;
   bool check=true;
   for(i=2;i<=n;i++)
   {  for(j=0;j<size;j++) c[j]=0;
      for(j=0;j<lenb;j++) c[j]=b[j]*i;
      for(j=0;j<size-1;j++)
      { t=c[j];
        c[j]=t%10;
        c[j+1]+=t/10;
      }
      for(j=n-1,t=0;t<j;t++,j--) swap(c[j],c[t],u); 
      if(!IsSame(a,c,n)) return false;
   }
   return true;
}       
int main()
{ int i,j,t,n,lenb,aa[size],bb[size],cc[size],*a,*b,*c;
  char s[size];
  bool check;
  a=aa;b=bb;c=cc;
  while(scanf("%s",s)!=EOF)
  {  n=strlen(s);
     check=true;
     for(i=0;i<n;i++)
     {  a[i]=s[i]-'0';
        if(a[i]) check=false;
     }
     if(check) {printf("%s is cyclic\n",s);continue;}    
     for(i=0;i<n;i++) if(a[i]) break;
     for(j=0;j<size;j++) b[j]=0;
     for(j=n-1,t=0;j>=i;j--,t++) b[t]=a[j];
     lenb=n-i;
     check=IsCircle(a,b,c,n,lenb);
     if(check) printf("%s is cyclic\n",s);
     else printf("%s is not cyclic\n",s);
  }
  //system("pause"); 
  return 0;
}        
                
