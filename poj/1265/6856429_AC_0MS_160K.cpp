#include<stdio.h>
#include<stdlib.h>
#define _abs(a)  ((a)>0 ? (a):-(a))
#define MAX(a,b) ((a)>(b) ?(a):(b))
#define MIN(a,b) ((a)<(b) ?(a):(b))
typedef struct
{       int x,y;
}point;
point  u[150];
int n,I,E;
double area;

point operator - (point a,point b)
{     point tp;
      tp.x=a.x-b.x;
      tp.y=a.y-b.y;
      return tp;
}

int operator ^ (point a,point b)
{   return a.x*b.y-a.y*b.x;     }

int gcd(int a,int b)
{   int tp;
    while(a%b!=0) { tp=a%b;  a=b; b=tp;}
    return b;
}

int edge(point a,point b)
{   point tp;
    tp=a-b;
    tp.x=_abs(tp.x);
    tp.y=_abs(tp.y);
    if((tp.x==tp.y)||(tp.x==0)||(tp.y==0))
       return MAX(tp.x,tp.y)-1;
    return gcd(MAX(tp.x,tp.y),MIN(tp.x,tp.y))-1;
}

void solve()
{    int i,j;
     E=I=0;
     area=0.0;
     for(i=1;i<=n-2;++i)
        area+=double((u[i+1]-u[0])^(u[i]-u[0]));
     area=_abs(area)/2;
     E+=edge(u[0],u[n-1])+n;
     for(i=1;i<=n-1;++i)  E+=edge(u[i],u[i-1]);
     I=(int)area-E/2+1;
}

int main()
{         int tc,test,i,x,y;
          scanf("%d",&test);
          for(tc=1;tc<=test;++tc)
          {                scanf("%d",&n);
                           x=y=u[0].x=u[0].y=0;
                           for(i=1;i<n+1;++i)
                           {    scanf("%d%d",&u[i].x,&u[i].y);
                                x+=u[i].x;
                                y+=u[i].y;
                                u[i].x=x;
                                u[i].y=y;
                           }
                           n++;   
                           solve();
                           printf("Scenario #%d:\n",tc);
                           printf("%d %d %0.1lf\n\n",I,E,area);  
          }
          //system("pause");
          return 0;
}   
