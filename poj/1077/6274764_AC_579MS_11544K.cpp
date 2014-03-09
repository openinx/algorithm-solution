#include<stdio.h>
#include<stdlib.h>
#define _MAX_ 362885
#define swap(a,b,c){c=a;a=b;b=c;}
typedef struct state
{  long ope;
   long parent;
   long step;
}STATE;

STATE T[_MAX_];
long Q[_MAX_][10],ff,hh;
long prime[10];
long dx[4]={1,0,-1,0},
     dy[4]={0,-1,0,1};
     
void InitQ()
{  ff=hh=0;}
bool IsEmtpy()
{   return (ff==hh ? true:false);}
void Push(long *cur)
{   long i;
    for(i=0;i<10;i++)
    Q[ff][i]=cur[i];
    ff=(ff+1)%_MAX_;
}
void Pop(long *cur)
{  long i;
   for(i=0;i<10;i++)
   cur[i]=Q[hh][i];
   hh=(hh+1)%_MAX_;
}       

void Init_Prime()
{  long i;
   prime[0]=1;
   for(i=1;i<10;i++)
   prime[i]=i*prime[i-1];
}
void Search(long *a,long &pos)
{  long i,j,c;
   pos=0;
   for(i=1;i<=9;i++)
   {  c=0;
      for(j=i+1;j<=9;j++)
      if(a[j]<a[i])++c;
      pos+=c*prime[9-i];
   }
}
bool IsOutOfBound(long x,long y)
{  if(x<1||y<1) return true;
   if(x>3||y>3) return true;
   return false;
}   
void BFS()
{  long *a,aa[10],*cur,curr[10],i,j,k,depth;
   long cx,cy,sx,sy,sign,pos_cur,pos_son,ok,x_pos;
   Init_Prime();
   a=aa;
   cur=curr;
   for(i=0;i<_MAX_;i++)  T[i].ope=T[i].parent=T[i].step=-1;
   a[0]=9;
   cur[0]=-1;
   for(i=1;i<=9;++i) { a[i]=i; cur[i]=-1;}
   InitQ();
   Push(a);
   Push(cur);
   T[0].ope=T[0].parent=T[0].step=0;
   depth=1;
   while(true)
   {   Pop(cur);
       if(cur[0]==-1)
       {  if(IsEmtpy()) return;          
          ++depth;
          Push(cur);
          Pop(cur);
       }
       Search(cur,pos_cur);
       cx=(cur[0]-1)%3+1;
       cy=(cur[0]-1)/3+1;
       x_pos=cur[0];
       for(i=0;i<4;i++)
       {  
          sx=cx+dx[i];
          sy=cy+dy[i];
          if(IsOutOfBound(sx,sy)) continue;
          sign=(sy-1)*3+sx;
          swap(cur[sign],cur[x_pos],ok);
          cur[0]=sign;
          Search(cur,pos_son);
          if(T[pos_son].ope==-1)
          {   T[pos_son].ope=i;
              T[pos_son].parent=pos_cur;
              T[pos_son].step=depth;
              Push(cur);
          }
          swap(cur[sign],cur[x_pos],ok);
          cur[0]=x_pos;
       }
   } 
}          
void Convert(long ope,char &ch)
{  
    switch(ope)
    {  
      case 0:ch='l';break;
      case 1:ch='d';break;
      case 2:ch='r';break;
      case 3:ch='u';break;
      default:break;
    }
}
int main()
{  BFS();
   char str[4],ch;
   long i,j,num,pos,*cur,curr[10];
   long data[35],step;
   cur=curr;
     for(i=1;i<10;i++)
     {  scanf("%s",str);
        if(str[0]=='x') cur[i]=9;
        else cur[i]=str[0]-'0';
     }   
      Search(cur,pos);
      if(T[pos].ope==-1) 
      {  
         printf("unsolvable\n");
         return 0;
      }
      step=T[pos].step;
      j=0;
      while(T[pos].step)
      {  data[j++]=T[pos].ope;
         pos=T[pos].parent;
      }
      for(i=0;i<j;++i)
      {  Convert(data[i],ch);
         printf("%c",ch);
      }
      printf("\n");
      return 0;
}            
         
         
                
          
          
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
                
