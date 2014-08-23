#include<stdio.h>
#include<stdlib.h>
int xx[4]={1,0,-1,0},
    yy[4]={0,-1,0,1};
char m[12][17],str[17];
int test,test_num=0;
int visit[12][17],grid_num;
void output()
{  int i,j;
   printf("output is:\n");
   for(i=1;i<11;i++)
   { for(j=1;j<16;j++)
     if(m[i][j]=='#') printf(".");
     else printf("%c",m[i][j]);
     printf("\n");
   }
}      
void Init_Visit()
{  int i,j;
   for(i=0;i<=11;i++) 
   visit[i][0]=visit[i][16]=-1;
   for(j=0;j<=16;j++) 
   visit[0][j]=visit[11][j]=-1;
   for(i=1;i<=10;i++)
    for(j=1;j<=15;j++)
    visit[i][j]=0;
}   
void DFS(int r,int c,int &temp,char ch)
{  int i,x,y;
   visit[r][c]=grid_num;
   temp++;
   for(i=0;i<4;i++)
   { x=r+xx[i];
     y=c+yy[i];
     if(x<1||x>10) continue;
     if(y<1||y>15) continue;
     if(visit[x][y]) continue;
     if(m[x][y]==ch) DFS(x,y,temp,ch);
   }
}     
void DELETE(int sign)
{  int i,j,k;
   for(j=1;j<=15;j++)
   {  for(i=1;i<=10;i++)
      if(visit[i][j]!=sign)
      continue;
      else
      {  for(k=i-1;k>=0;k--)
         { m[k+1][j]=m[k][j];
         }  
      }
   }
   bool check;
   for(j=15;j>=1;j--)
   {  check=true;
      for(i=1;i<=10;i++) 
      if(m[i][j]!='#') 
      { check=false;
        break;
      }  
      if(!check) continue;
      for(i=1;i<=10;i++)
      {   for(k=j+1;k<=16;k++)
          { m[i][k-1]=m[i][k];
          }        
      }
   }
} 
          
void DEAL()
{  int i,j,k,maxi,maxj;
   int count,temp,max,sign,move=0;
   int final_score=0,score;
   char ch;
   printf("Game %d:\n\n",++test_num);
   grid_num=0;
   do{
      Init_Visit();
      max=0;
      for(j=1;j<=15;j++)
       for(i=10;i>=1;i--)
       {  if(visit[i][j]) continue;
          if(m[i][j]=='#') continue;
          ++grid_num;
          ch=m[i][j];
          temp=0;
          DFS(i,j,temp,ch);
          if(max<temp)
          { max=temp;
            maxi=i;
            maxj=j;
          }
       }
     if(max<2) break;
     score=(max-2)*(max-2);
     final_score+=score;
     printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points. \n",
     ++move,11-maxi,maxj,max,m[maxi][maxj],score);
     sign=visit[maxi][maxj];
     DELETE(sign); 
    // output();       
  }while(true);
  int tt=0;
  for(i=1;i<=10;i++)
   for(j=1;j<=15;j++)
   { if(m[i][j]!='#')
     tt++;
   }
  if(!tt) final_score+=1000;   
  printf("Final score: %d, with %d balls remaining. \n\n",final_score,tt);
}      
int main()
{  int i,j;
   scanf("%d",&test);
   while(test--)
   {  for(i=0;i<=11;i++) m[i][0]=m[i][16]='#';
      for(j=0;j<=16;j++) m[0][j]=m[11][j]='#';
      for(i=1;i<=10;i++)
      {  scanf("%s",str);
         for(j=1;j<=15;j++)
         m[i][j]=str[j-1];
      }
      DEAL();
      //output();
   }
   //system("pause");
   return 0;
}          
