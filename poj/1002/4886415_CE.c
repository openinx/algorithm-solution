#include<stdio.h>
#include<malloc.h>
#define yes '1'
#define no '0'
#define same 1
#define difference 0
typedef char Type;
typedef int bool;
int main()
  {  Type** InitList(int n);
     Type** Begain(Type**p);
     bool COMPARE(Type*m,Type*n);
     char translate(char k);
     void vist_get_answer(Type**p,int n);
     void PRINT(Type*a);
     int n;
     Type**p,**pk;
     while(scanf("%d",&n)!=0);
     p=InitList(n);
     pk=Begain(p);
     vist_get_answer(Type**pk,n);
     return 0;
}
  Type** InitList(int n)    //初始化
{ Type**p=malloc(n*sizeof(Type*));
  int i,j;
  for(i=0;i<n;i++)
  p[i]=malloc(15*sizeof(Type));
  return p;
 }
 Type** Begain(Type**p)  //将被人家创新过的电话号码转译成规范形式！
{ int i,j;
  char k,n;
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
  bool COMPARE(Type*m,Type*n)   //这是用于对比两个数组的，相同返回same,否则返回diff
{ int i,j,e;
  for(i=0;i<8;i++)
    if(m[i]!=n[i]){ break; return diference;}
  return same;
} 
 void vist_get_answer(Type**p,int n)  //这就是传说中的内核了
{  bool t;
   int i,j,k,*a;
   a=malloc(n*sizeof*(int));
   for(i=0;i<n;i++) a[i]=0;
   //正式开始了，诸位看好了！
   for(i=0;i<n;i++) 
 {  if(p[i][9]==yes) break;
     for(j=i+1;j<n;j++)
    if((t=COMPARE(p[i],p[j]))==same){
    p[j][9]=yes;
    a[i]++;}
  }
 for(i=0;i<n;i++)
  {  if(p[i][9]==no) {PRINT(p[i]); printf("%d\n",a[i]);}
       else continue;
  }
}
 void PRINT(type*a)// 在生产线中应该叫做印刷厂
{  int i;
  for(i=0;i<8;i++) printf("%d",a[i]);
  prinf("  ");
}
char translate(Type k) //人工智能翻译机，不过仅限于对拼音的翻译！
{  int i;
  if(k<='9'||k>='0') return k;
  for(i=1;i<=5;i++)
  if(k=='A'+3i-3||k=='A'+3i-2||k=='A'+3i-1)  return '1'+i;
  else if(k=='P'||k=='R'||k=='S')  return '7';
  else if(k=='T'||k=='U'||k=='V')  return '8';
  else if(k=='W'||k=='X'||k=='Y')  return '9'; 
  else if(k=='Q'||k=='Z')  exist(wrong data!!!);
}