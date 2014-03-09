#include<stdio.h>
#include<math.h>
typedef struct{
 int x;
 int y;
 int num;
}point;
point  p[2510];       
int Max_peanuts(int c,int time)
{   int i,j,k,m,t,last_time,count=0;
    int cur_x,cur_y,back_time;
    cur_x=1;
    cur_y=p[1].y;
    last_time=time-1;
    for(i=1;i<=c;i++)
    {  t=abs(cur_x-p[i].x)+abs(cur_y-p[i].y);
       back_time=p[i].x;
       if(last_time>=(t+1+back_time))
       { count+=p[i].num;
         cur_x=p[i].x;
         cur_y=p[i].y;
         last_time-=t+1;
       }
       else break;
    }
    return count;
}     
void sort(int c)
{  int i,j;
   point e;
   for(i=1;i<c;i++)
    for(j=1;j<=c-i;j++)
     if(p[j].num<p[j+1].num)
     {  e=p[j];
        p[j]=p[j+1];
        p[j+1]=e;
     }  
    return ;
}     
int main()
{  int i,j,k,c,t,size,row,cloum,time;
   scanf("%d",&size);
   for(i=0;i<size;i++)
   {   scanf("%d%d%d",&row,&cloum,&time);
       c=0;
       for(j=1;j<=row;j++)
         for(k=1;k<=cloum;k++)
         { scanf("%d",&t);
           if(t) 
             { ++c;
               p[c].x=j;
               p[c].y=k;
               p[c].num=t;
             }
         }
      sort(c);  
      printf("%d\n",Max_peanuts(c,time));
  }
  return 0;
}                  

