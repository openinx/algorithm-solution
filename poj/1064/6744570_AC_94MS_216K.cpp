#include<stdio.h>
int a[11000],left,right,mid;
int N,M;
int check(int value)
{
 int cnt=0,i;
 for(i=1;i<=N;++i)
  cnt+=a[i]/value; 
 if(cnt>=M)
  return 1;
 return 0;
}
int main()
{
 int i;double value;
 while(EOF!=scanf("%d %d",&N,&M))
 {
  left=1,right=0;
  for(i=1;i<=N;++i)
  {
   scanf("%lf",&value);
   a[i]=int(100*value);
   if(a[i]>right)
    right=a[i];
  }
     while(left<=right)
  {
           mid=(left+right)/2;
     if(check(mid))//成立
                left=mid+1;
     else
       right=mid-1;
  }
  printf("%.2lf\n",right*0.01);   
 }
 return 0;
}
