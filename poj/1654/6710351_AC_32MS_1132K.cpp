#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define _max_size 1000005
int dx[10]={0,-1,0,1,-1,0,1,-1,0,1};
int dy[10]={0,-1,-1,-1,0,0,0,1,1,1};
typedef struct 
{     long x,y;
}node;
long cross(node b,node a,node c)
{    node ab,ac;
     ab.x=b.x-a.x;
     ab.y=b.y-a.y;
     ac.x=c.x-a.x;
     ac.y=c.y-a.y;
     return (ab.x*ac.y-ab.y*ac.x);
}
int main()
{   long  i,len,testcase,id;
    __int64 area;
    char str[_max_size];
    node stp,cur,nbr;
    scanf("%ld",&testcase);
    while(testcase--)
    {              scanf("%s",str);
                   len=strlen(str);
                   if(len<4) { printf("0\n");continue;}
                   area=stp.x=stp.y=0;
                   id=str[0]-'0';
                   cur.x=stp.x+dx[id];
                   cur.y=stp.y+dy[id];
                   for(i=1;i<=len-2;++i)
                   {   // printf("pos:%ld %ld\n",cur.x,cur.y);
                        id=str[i]-'0';
                        nbr.x=cur.x+dx[id];
                        nbr.y=cur.y+dy[id];
                        area+=(__int64)cross(cur,stp,nbr);
                        cur.x=nbr.x;
                        cur.y=nbr.y;
                   }
                   area= area>0 ? area :-area;
                   //printf("area:%ld\n",area);
                   if(area%2==0) printf("%I64d\n",area/2);
                   else printf("%I64d.5\n",area/2);
    }
    //system("pause");
    return 0;
}                         
     
     
