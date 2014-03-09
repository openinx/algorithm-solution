#include<stdio.h>
#define size 100
#define MAX(x,y) ((x)>(y)? (x):(y))
#define MIN(x,y) ((x)<(y)? (x):(y))
char op[size];
int v[size],n,m[size][size][2];
bool read()
{    int i,str[3];
     if(scanf("%d",&n)==EOF) return false;
     for(i=1;i<=n;++i)
     {  scanf("%s%d",str,&v[i]);
        op[i]=str[0];
     }
     return true;
}
void Bound(int i,int s,int j,int &max,int &min)
{  int r=(i+s-1)%n+1;
   int e[4],u,fmax=m[i][s][1],fmin=m[i][s][0],gmax=m[r][j-s][1],gmin=m[r][j-s][0];
     //printf("fmax:%d fmin:%d gmax:%d gmin:%d\n",fmax,fmin,gmax,gmin);
     if(op[r]=='t')
     {   max=fmax+gmax;
         min=fmin+gmin;
     }
     else 
     {  e[0]=gmax*fmax;
        e[1]=gmax*fmin;
        e[2]=gmin*fmax;
        e[3]=gmin*fmin;
        max=min=e[0];
        for(u=1;u<4;++u)
        {    max=MAX(max,e[u]);  min=MIN(min,e[u]); }
     }   
}             
void output()
{    int i,j;
     for(i=1;i<=n;++i)
     {  for(j=1;j<=n;++j) printf("(%d,%d) ",m[i][j][0],m[i][j][1]);
        printf("\n");
     }
}        
void MaxScore()
{    int i,j,s,maxf,minf;
     for(i=1;i<=n;++i) m[i][1][0]=m[i][1][1]=v[i];
     for(j=2;j<=n;++j)
       for(i=1;i<=n;++i)
       {  Bound(i,1,j,maxf,minf);
          m[i][j][0]=minf;
          m[i][j][1]=maxf;
          //printf("%d %d\n",minf,maxf);
          for(s=2;s<j;++s)
          {  Bound(i,s,j,maxf,minf);
             m[i][j][0]=MIN(m[i][j][0],minf);
             m[i][j][1]=MAX(m[i][j][1],maxf);
          }                            
       }
    //output();
    maxf=m[1][n][1];
    for(i=2;i<=n;++i) maxf=MAX(maxf,m[i][n][1]);
    printf("%d\n",maxf);
    for(i=1;i<=n;++i) if(m[i][n][1]==maxf) printf("%d ",i);
}                            
int main()
{   while(read()) MaxScore();
    return 0;
}            
