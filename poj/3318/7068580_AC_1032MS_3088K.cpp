#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

const int _size = 501;
int n,A[_size][_size],B[_size][_size],C[_size][_size];
int X[_size],Y[_size],Z[_size];

bool solve()
{    
     int pt,i,j;   
          for(i=0;i<n;++i)  X[i]=i+1;
          for(i=0;i<n;++i)
          {   
              Y[i]=0;
              for(j=0;j<n;++j)  Y[i]+=B[i][j]*X[j];
          }
          for(i=0;i<n;++i)
          {   
              Z[i]=0;
              for(j=0;j<n;++j)  Z[i]+=C[i][j]*X[j];
          }
          for(i=0;i<n;++i)
          {  
             X[i]=0;
             for(j=0;j<n;++j)  X[i]+=A[i][j]*Y[j];
          }
          for(i=0;i<n;++i)  
            if(Z[i]!=X[i])  return false;
     return true;
}
          

int main()
{    
     int i,j;
     scanf("%d",&n);
     for(i=0;i<n;++i)
       for(j=0;j<n;++j)
       scanf("%d",&A[i][j]);
     for(i=0;i<n;++i)
       for(j=0;j<n;++j)
       scanf("%d",&B[i][j]);
     for(i=0;i<n;++i)
       for(j=0;j<n;++j)
       scanf("%d",&C[i][j]);
     if(solve())  printf("YES\n");
     else  printf("NO\n");
     return 0;
}

 

