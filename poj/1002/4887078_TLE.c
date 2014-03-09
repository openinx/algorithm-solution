#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define yes '1'
#define no '0'
#define same 1
#define difference 0
#define Type char
#define Bool int
int main()
  {  Type** InitList(int n);
     Type** Begain(Type**p,int n);
     Bool COMPARE(Type*m,Type*n);
     char translate(char k);
     void vist(Type **p,int n);
     void PRINT(Type*a);
     int n;
     Type**p,**pk;
     while(scanf("%d",&n)!=0);
     p=InitList(n);
     pk=Begain(p,n);
     vist(pk,n);
     return 0;
}
  Type** InitList(int n)
{ Type**p=malloc(n*sizeof(Type*));
  int i;
  for(i=0;i<n;i++)
  p[i]=malloc(10*sizeof(Type));
  return p;
 }
 Type** Begain(Type**p,int n)
{ int i,j;
  char k;
  for(i=0;i<n;i++)
{    j=0;
  while((k=getchar())!='\0'&&j<8)
  { 
   if(j==4)p[i][j++]='-';  
   if(k=='-') continue;
  else if((k<='Y'&&k>='A')||(k<='9'&&k>='0')) 
       p[i][j++]=translate(k);
  }
   p[i][8]='\0';
   p[i][9]=no;
} 
  return p;
}  
  Bool COMPARE(Type*m,Type*n)
{ int i,j,e;
  for(i=0;i<8;i++)
    if(m[i]!=n[i]){ break; return difference;}
  return same;
} 
 void vist(Type**p,int n)
{  int i,j,k,*a;
   a=malloc(n*sizeof(int));
   for(i=0;i<n;i++) a[i]=0;
   for(i=0;i<n;i++) 
 {  if(p[i][9]==yes) break;
     for(j=i+1;j<n;j++)
    if(COMPARE(p[i],p[j])==same){
    p[j][9]=yes;
    a[i]++;}
  }
 for(i=0;i<n;i++)
  {  if(p[i][9]==no) {PRINT(p[i]); printf("%d\n",a[i]);}
       else continue;
  }
}
 void PRINT(Type*a)
{  int i;
  for(i=0;i<8;i++) printf("%d",a[i]);
  printf("  ");
}
char translate(Type k)
{  int i;
  if(k<='9'||k>='0') return k;
  if(k=='A'||k=='B'||k=='C')  return '2';
  if(k=='D'||k=='E'||k=='F')  return '3';
  if(k=='G'||k=='H'||k=='I')  return '4';
  if(k=='J'||k=='K'||k=='L')  return '5';
  if(k=='M'||k=='N'||k=='O')  return '6';
  if(k=='P'||k=='R'||k=='S')  return '7';
  if(k=='T'||k=='U'||k=='V')  return '8';
  if(k=='W'||k=='X'||k=='Y')  return '9';
}