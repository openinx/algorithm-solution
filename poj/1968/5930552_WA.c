#include<stdio.h>
#include<stdlib.h>
#define size 3001
long page[size],ok[size];
int school,special,booket;
void Merg(int left,int middle,int right)
{  int i,j,k;
   k=i=left;
   j=middle+1;
   while((i<=middle)&&(j<=right))
   if(page[i]<page[j]) ok[k++]=page[i++];
   else ok[k++]=page[j++];
   while(i<=middle) ok[k++]=page[i++];
   while(j<=right)ok[k++]=page[j++];
   for(i=left;i<=right;i++) page[i]=ok[i];
}      
void Qsort(int left,int right)
{  int middle;
   if(left<right)
   {  middle=(left+right)/2;
      Qsort(left,middle);
      Qsort(middle+1,right);
      Merg(left,middle,right);
   }
}
int main()
{  int i,uip,vip,start;
   while(scanf("%d%d%d",&school,&special,&booket)!=EOF)
   {  for(i=1;i<=booket;i++)
      scanf("%ld",&page[i]);
      Qsort(1,booket); // from large to the less
      //for(i=1;i<=booket;i++)
      //printf("%ld ",page[i]);
      //printf("\n");
      vip=booket/school;
      uip=vip+booket%school;
      if(!special)
      printf("%ld\n",page[1]);
      else{ start=uip+(special-1)*vip+1;
            printf("%ld\n",page[start]);
          }
  }
  //system("pause");
  return 0;
}           
           
      
