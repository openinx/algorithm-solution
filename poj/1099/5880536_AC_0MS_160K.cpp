#include<stdio.h>
#include<stdlib.h>
#define size 12
#define sizeA 60
int a[size][size],n;
char m[sizeA][sizeA];
void next(int &ra,int &ca)
{  ca+=4;
   if(ca>4*n+1) 
   {ra+=4; ca=3;}
}   
int check(int ra,int ca)
{   int r=4*n-3,c=4*n+1;
    if(ra==1)
    { if(ca==3) return 1;
      if(ca==c-2) return 2;
      if(m[ra][ca-2]=='H') return 2;
      return 1;
    }
    if(ra==r)
    {  if(ca==3) return 3;
       if(ca==c-2) return 4;
       if(m[ra][ca-2]=='H') return 4;
       return 3;
    }
    if(ca==3)
    {  if(m[ra-2][ca]=='H') return 1;
       return 3;
    }
    if(ca==c-2)
    {  if(m[ra-2][ca]=='H') return 2;
       return 4;
    }   
    if(m[ra-2][ca]=='H')
    {  if(m[ra][ca-2]=='H') return 2;
       return 1;
    }
    if(m[ra][ca-2]=='H') return 4;
    return 3;
}       
void DEAL()
{  int i,j,r=4*n-3,c=4*n+1,ra=1,ca=3,t;
   for(i=0;i<=c+1;i++) m[0][i]=m[r+1][i]='*';
   for(i=0;i<=r+1;i++) m[i][0]=m[i][c+1]='*';
   for(i=1;i<=r;i++)
     for(j=1;j<=c;j++)
     m[i][j]=' ';
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {  m[ra][ca]='O';
        switch(a[i][j])
        {  case 1:m[ra][ca-1]='-';
                  m[ra][ca+1]='-';
                  m[ra][ca-2]='H';
                  m[ra][ca+2]='H';
                  break;
           case -1: m[ra-1][ca]=m[ra+1][ca]='|';
                    m[ra-2][ca]=m[ra+2][ca]='H';
                    break;
           case 0:t=check(ra,ca);
                  if(t==1) { m[ra][ca-1]='-';
                             m[ra+1][ca]='|';               
                             m[ra][ca-2]=m[ra+2][ca]='H';
                             break;
                            }   
                  if(t==2)
                       {  m[ra][ca+1]='-';
                          m[ra+1][ca]='|';
                          m[ra][ca+2]=m[ra+2][ca]='H';
                          break; 
                       }
                  if(t==3)
                       { m[ra][ca-1]='-';
                         m[ra-1][ca]='|';
                         m[ra][ca-2]=m[ra-2][ca]='H';
                         break; 
                       }
                  if(t==4)
                       { m[ra-1][ca]='|';
                         m[ra][ca+1]='-';
                         m[ra-2][ca]=m[ra][ca+2]='H';
                         break; 
                       }
           default:break;
        }  
      next(ra,ca);
    } 
   for(i=0;i<=r+1;i++)
   {  for(j=0;j<=c+1;j++)
      printf("%c",m[i][j]);
      printf("\n");
   }
}                       
int main()
{  int i,j,t=0;
   scanf("%d",&n);
   while(n)
   {  for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       scanf("%d",&a[i][j]);
      printf("Case %d:\n\n",++t);
      DEAL();
      printf("\n");
      scanf("%d",&n);
   }
   //system("pause");
   return 0;
}   
      
