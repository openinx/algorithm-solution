#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define inf 1000000.0
#define swap(a,b,c){c=a;a=b;b=c;}
typedef struct node{
double x1,y1,x2,y2;
}Node;
Node N[110];
void INSERT(double *Line_x,int &len,double x)
{  int i,j;
   double t;
   for(i=1;i<=len;i++)
   if(Line_x[i]==x) return;
   Line_x[++len]=x;
   j=len;
   for(i=len-1;i>=1;i--)
   if(Line_x[i]>Line_x[j]) 
   { swap(Line_x[i],Line_x[j],t);j=i;}
   else return;
}   
int main()
{  int i,j,k,T,lenx,leny,test_case=0;
   double cx,cy,qx,qy,px,py,*Line_x,*Line_y,xx[220],yy[220],area;
   Line_x=xx;
   Line_y=yy;
   while(scanf("%d",&T)!=EOF&&T)
   {  lenx=leny=0;
      area=0;
      for(i=1;i<=T;i++)
      { scanf("%lf%lf%lf%lf",&N[i].x1,&N[i].y1,&N[i].x2,&N[i].y2);
        INSERT(Line_x,lenx,N[i].x1);
        INSERT(Line_y,leny,N[i].y1);
        INSERT(Line_x,lenx,N[i].x2);
        INSERT(Line_y,leny,N[i].y2);
      }
     for(j=1;j<leny;j++)
      for(i=1;i<lenx;i++)
      {  px=Line_x[i];
         py=Line_y[j];
         qx=Line_x[i+1];
         qy=Line_y[j+1];
         //printf("%0.2f %0.2f %0.2f %0.2f\n",px,py,qx,qy);
         cx=(px+qx)/2;
         cy=(py+qy)/2;
         bool check=false;
         for(k=1;k<=T;k++)
         if(cx>=N[k].x1&&cx<=N[k].x2&&cy>=N[k].y1&&cy<=N[k].y2) 
         {check=true;break;}
         if(check)  area+=fabs(qx-px)*fabs(qy-py);
      }
    printf("Test case #%d\n",++test_case);
    printf("Total explored area: %0.2f\n\n",area);
   }
   //system("pause");
   return 0;
}   
          
      
       

   
