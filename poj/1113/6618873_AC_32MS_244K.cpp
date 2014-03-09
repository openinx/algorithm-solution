#include<stdio.h>
#include<math.h>
#define PI 3.1415926
#define size 1005
#define swap(x,y,z){(z)=(x);(x)=(y);(y)=(z);}
long n,Rr;
typedef struct {
long x,y;
double cos;
}point;
point p[size],min_ld;
long s[size];  
bool read()
{   if(scanf("%ld%ld",&n,&Rr)==EOF) return false;
    long i;
    for(i=0;i<n;++i)
    scanf("%ld%ld",&p[i].x,&p[i].y);
    return true;   
}   
double distance(point a,point b)
{      double x,y;
       x=(double)(a.x-b.x);
       y=(double)(a.y-b.y);
       return sqrt(x*x+y*y);
} 
bool cmp(point a,point b) // a<b return true;else return false;
{   if(fabs(a.cos-b.cos)<1e-8)  return abs(a.x-min_ld.x)<abs(b.x-min_ld.x);
    else return a.cos-b.cos>1e-8;
}           
void sort(long st,long ed)
{    if(st<ed)
     {   long i=st,j=ed+1;
         point temp,x=p[st];
         while(true)
         {   while(cmp(p[++i],x));
             while(cmp(x,p[--j]));
             if(i>=j) break;
             swap(p[i],p[j],temp);
         }
         p[st]=p[j];
         p[j]=x;
         sort(st,j-1);
         sort(j+1,ed);
     }
}         
              
         
bool TurnLeft(point a,point b,point c)
{    point ab,bc;
     ab.x=b.x-a.x;
     ab.y=b.y-a.y;
     bc.x=c.x-b.x;
     bc.y=c.y-b.y;
     if(ab.x*bc.y-ab.y*bc.x>0) return true;
     return false;
}      
double solve()
{    long i,j,tmp=0;
     double d1,d2,circle;
     point p1,p2;
     for(i=1; i<n ; ++i)
         if((p[i].y<p[tmp].y)||(p[i].y==p[tmp].y&&p[i].x>p[tmp].x))  tmp=i;
     swap(p[0],p[tmp],p1);
     p[0].cos=1;
     for(i=1;i<n;++i)
     {    d1=distance(p[0],p[i]);
          p[i].cos=((double)(p[i].x-p[0].x))/d1;
     }    
     min_ld=p[0];
     sort(0,n-1);
     long top=1;
     s[0]=0;
     s[1]=1; 
     for(i=2;i<n;++i)
     {    while((top>0)&&(!TurnLeft(p[s[top-1]],p[s[top]],p[i])))
          --top;
          s[++top]=i;
     }
     circle=0.00;
     circle+=2*PI*((double)Rr);
     if(top==0)  return circle;
     if(top==1)  
     {   circle+=2*distance(p[s[0]],p[s[1]]);
         return circle;
     }
     for(i=0;i<top;++i)
        circle+=distance(p[s[i]],p[s[i+1]]);
     circle+=distance(p[s[0]],p[s[top]]);
     return circle;       
}     
int main()
{   while(read()) printf("%0.lf",solve());
    return 0;
}     
