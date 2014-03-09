#include<stdio.h>

int n;

struct node
{      int a[2][2];
};
  
node opt;
  
node  mod(node & a,node b,int c)
{     opt.a[0][0]=(a.a[0][0]*b.a[0][0]+a.a[0][1]*b.a[1][0])%c;
      opt.a[0][1]=(a.a[0][0]*b.a[0][1]+a.a[0][1]*b.a[1][1])%c;
      opt.a[1][0]=(a.a[1][0]*b.a[0][0]+a.a[1][1]*b.a[1][0])%c;
      opt.a[1][1]=(a.a[1][0]*b.a[0][1]+a.a[1][1]*b.a[1][1])%c;
      return opt;
}

        
int solve()
{    node res,tp;
     res.a[0][0]=tp.a[0][0]=1;
     res.a[0][1]=tp.a[0][1]=1;
     res.a[1][0]=tp.a[1][0]=1;
     res.a[1][1]=tp.a[1][1]=0;
     while(n)
     {        if(n&1)
                   res=mod(res,tp,10000);
              tp=mod(tp,tp,10000);
              n>>=1;
     }
     return res.a[1][1];
} 
      

int main()
{   
    while(scanf("%d",&n)!=EOF&&n>=0)
        printf("%d\n",solve());
    return 0;
}
         
