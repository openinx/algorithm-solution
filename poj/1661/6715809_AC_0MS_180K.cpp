#include<stdio.h>
#include<algorithm>
#define _max_size 1005
#define maxint 10000000
#define MIN(a,b) ((a)<(b)   ? (a):(b))
using namespace std;
long sx,sy,MAXH,n;
typedef struct 
{        long x1,x2,y;
         long w1,w2;
}node;
node p[_max_size];
bool cmp(node a,node b)
{    return a.y<b.y;  }
void solve()
{     long i,j,idl,idr,cost=0;
      sort(p+1,p+n+1,cmp);
      p[0].y=0;
      p[0].x1=-maxint;
      p[0].x2=maxint;
      p[0].w1=p[0].w2=0;
      p[1].w1=p[1].w2=p[1].y;
      for(i=2;i<=n;++i)
      {     idl=idr=-1;
            for(j=i-1;(j>=0)&&(p[i].y-p[j].y<=MAXH);j--)
                 if((p[i].x1>=p[j].x1)&&(p[i].x1<=p[j].x2))
                 {   idl=j;
                     break;
                 }
             if(idl==0)  p[i].w1=p[i].y-p[idl].y;
              else  if(idl==-1) p[i].w1=maxint;
                  else p[i].w1=p[i].y-p[idl].y+MIN(p[i].x1-p[idl].x1+p[idl].w1,p[idl].x2-p[i].x1+p[idl].w2);
            for(j=i-1;(j>=0)&&(p[i].y-p[j].y<=MAXH);j--)
                 if((p[i].x2<=p[j].x2)&&(p[i].x2>=p[j].x1))
                 {   idr=j;
                     break;
                 }
            if(idr==0) p[i].w2=p[i].y-p[idr].y;
               else if(idr==-1) p[i].w2=maxint;
                  else p[i].w2=p[i].y-p[idr].y+MIN(p[i].x2-p[idr].x1+p[idr].w1,p[idr].x2-p[i].x2+p[idr].w2);
      }
      for(i=n;i>=0;i--)
        if((p[i].x1<=sx)&&(p[i].x2>=sx))  break;
      if(i==0) cost=sy;
        else cost=sy-p[i].y+MIN(sx-p[i].x1+p[i].w1,p[i].x2-sx+p[i].w2);
      printf("%ld\n",cost);
}                         
int main()
{    long i,testcase;
     scanf("%ld",&testcase);
     while(testcase--)
     {     scanf("%ld%ld%ld%ld",&n,&sx,&sy,&MAXH);
           for(i=1;i<=n;++i)
               scanf("%ld%ld%ld",&p[i].x1,&p[i].x2,&p[i].y);
           solve();
     }
     //system("pause");
     return 0;
}           
