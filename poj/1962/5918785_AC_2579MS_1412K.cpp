#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define size 20002
typedef struct node{
long ID;
struct node *next;
}Node; 
typedef struct {
long center;
long distance;
Node *corp;
Node *end;
}Enprise;
Enprise e[size];
long num;
void InitEnprise()
{  long i;
   Node *p;
   for(i=1;i<=num;i++)
   { p=new Node;
     p->ID=i;
     p->next=NULL;
     e[i].corp=p;
     e[i].end=p;
     e[i].center=i;
     e[i].distance=0;
   } 
}
void Answer(int v)
{  printf("%ld\n",e[v].distance);}
void Add_new(int t,int v)
{  Node *p;
   long dist=abs(t-v)%1000+e[v].distance;
   p=e[t].corp;
   while(p!=NULL)
   {   e[p->ID].distance+=dist;
       e[p->ID].center=e[v].center;
       p=p->next; 
   }
   e[e[v].center].end->next=e[t].corp;
   e[e[v].center].end=e[t].end;
   e[t].end=NULL;
   e[t].corp=NULL;
}
int main()
{  long test;
   long v,t;
   char cm[2];
   scanf("%ld",&test);
   while(test--)
   { scanf("%d",&num);
     InitEnprise();
     scanf("%s",cm);
     while(cm[0]!='O')
     {   if(cm[0]=='E')
         { scanf("%ld",&v);
           Answer(v);
         }
         else if(cm[0]=='I')
         {  scanf("%ld%ld",&t,&v);
            Add_new(t,v);
         }
      scanf("%s",cm);
    }
  }  
    //system("pause");
    return 0;
}              
            
   
   

   
    
