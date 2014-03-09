#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define maxn  30
typedef struct node {
        char e;
        struct node *lchild,*rchild;
};
typedef node*  Node;

char prev[maxn],in[maxn];


void build(Node &T ,int ps,int pt,int is,int it)
{    
     if(ps > pt) { T = NULL;return ;}
     if(ps==pt) 
     {  
         T = new node;
         T->lchild = T->rchild = NULL;
         T->e = prev[ps];
         return;
     }  
     int i,lens;
     for(i = is ; i<=it ;++i) if(in[i] == prev[ps]) break;
     T = new node;
     T->lchild = T->rchild = NULL;  
     T->e = prev[ps];
     lens =  i - is;
     if(i==is)
     { 
       T->lchild=NULL;
       build(T->rchild,ps+1,pt,is+1,it);
       return;
     }
     if(i==it)
     {  
       T->rchild = NULL;
       build(T->lchild, ps+1,pt,is,it-1);
       return ;
     }
     build(T->lchild,ps+1,ps+lens,is,i-1);
     build(T->rchild,ps+lens+1,pt,i+1,it);
}

void last(Node T)
{     
     if(T){
             last(T->lchild);
             last(T->rchild);
             printf("%c",T->e);
             delete T ;
     }
}

int main()
{     
      int lens;
      while(scanf("%s%s",prev,in)!=EOF)
      {     
            Node T = NULL;
            lens = strlen(prev);
            build(T,0,lens-1,0,lens-1);
            last(T); printf("\n");            
      }
      return 0;
}
      

