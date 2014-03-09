#include<stdio.h>   
#include<set>
using namespace std;

typedef struct
{   long x,y;
}node;


bool operator < (node a,node b)
{    return a.y < b.y ;  }

int main()
{      set <node> s;
       long cmd;
       node e;
       while(scanf("%d",&cmd)!=EOF)
       {       if(cmd==0)  break;
               if(cmd==1)
               {       scanf("%ld%ld",&e.x,&e.y); 
                       s.insert(e);
               }
               if(cmd==2)
               {       if(s.empty())  printf("0\n");
                       else 
                       {      e.x=(*s.rbegin()).x;
                              e.y=(*s.rbegin()).y;
                              printf("%ld\n",e.x);
                              s.erase(e);
                       }
               }
               if(cmd==3) 
               {       if(s.empty()) printf("0\n");
                       else 
                       {      e.x=(*s.begin()).x;
                              e.y=(*s.begin()).y;
                              printf("%d\n",e.x);
                              s.erase(e);
                       }
               }
       }
      // while(1);
       //getchar();
       return 0;
}
       
       
