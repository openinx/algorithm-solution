#include<stdio.h>

typedef __int64 i64;
const i64 _size = 65;
i64 MOD,N,K;

struct matrix
{      i64 n;
       i64 u[_size][_size];
};

matrix A,I;
    
matrix init(int n)
{      matrix c;
       c.n=n;
       i64 i,j;
       for(i=1;i<=c.n;++i)
         for(j=1;j<=c.n;++j)
         c.u[i][j]=0;
       for(i=1;i<=c.n;++i) c.u[i][i]=1;
       return c;
}
    
/*matrix operator + (matrix a,matrix b)
{      matrix c;
       i64 i,j;
       c.n=a.n;
       for(i=1;i<=a.n;++i)
         for(j=1;j<=a.n;++j)
         c.u[i][j]=(a.u[i][j]+b.u[i][j])%MOD;
       return c;
}*/

matrix operator * (matrix a,matrix b)
{    matrix c;
     i64 i,j,k;
     c.n=a.n;
     for(i=1;i<=c.n;++i)
        for(j=1;j<=c.n;++j)
        {    c.u[i][j]=0;
             for(k=1;k<=c.n;++k)
             c.u[i][j]=(c.u[i][j]+(a.u[i][k]*b.u[k][j])%MOD)%MOD;
        }
     return c;
}
matrix pow_mod(matrix a,i64 n)
{      matrix c=init(a.n);
       while(n)
       {     if(n&1) c=c*a;
             a=a*a;
             n>>=1;
       }
       return c;
}

matrix copy(matrix c)
{      matrix ans;
       ans.n=c.n;
       i64 i,j;
       for(i=1;i<=c.n;++i)
          for(j=1;j<=c.n;++j)
       ans.u[i][j]=c.u[i][j];
       return ans;
}

void solve()
{    
     matrix W,ans;
     i64 i,j,k,i1,j1;
     W.n=2*N;
     for(i=1;i<=N;++i)
        for(j=1;j<=N;++j) W.u[i][j]=A.u[i][j];
     for(i=1,i1=1;i<=N;++i,++i1)
        for(j=N+1,j1=1;j<=2*N;++j,++j1)  W.u[i][j]=I.u[i1][j1];
     for(i=N+1,i1=1;i<=2*N;++i,++i1)
        for(j=N+1,j1=1;j<=2*N;++j,++j1)      W.u[i][j]=I.u[i1][j1];
     for(i=N+1;i<=2*N;++i)
        for(j=1;j<=N;++j)                W.u[i][j]=0;
     W=pow_mod(W,K);
     ans.n=N;
     for(i=1,i1=1;i<=N;++i,++i1)
        for(j=N+1,j1=1;j<=2*N;++j,++j1) ans.u[i1][j1]=W.u[i][j];
     ans=ans*A;
     for(i=1;i<=ans.n;++i)
     {  
          for(j=1;j<=ans.n;++j)
          printf("%I64d ",ans.u[i][j]);
          printf("\n");
     }
}
     
int main()
{    
    i64 i,j;
    I=init(64);
    while(scanf("%I64d%I64d%I64d",&N,&K,&MOD)!=EOF)
    {      A.n=N;
           for(i=1;i<=A.n;++i)
             for(j=1;j<=A.n;++j) 
           scanf("%I64d",&A.u[i][j]);
           solve();
    }
    return 0;
}
