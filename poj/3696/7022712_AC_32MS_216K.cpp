#include<stdio.h>
#include<math.h>
#define i64 __int64
#define _max_size 50000

i64 prime[_max_size],prime_size;
i64 p[_max_size],p_size;
bool visit[_max_size];


void init_prime()
{    i64 i,j;
     for(i=1;i<_max_size;++i)  visit[i]=true;
     for(i=2;i<_max_size;++i)
        if(visit[i])
           for(j=i+i;j<_max_size;j+=i)
              visit[j]=false;
     for(prime_size=0,i=2;i<_max_size;++i)
        if(visit[i])  prime[prime_size++]=i;
}//end

i64 gcd(i64 a,i64 b)
{   return b==0 ?  a: gcd(b,a%b); }  //end

void split(i64 n)
{    p_size=0;
     i64 i,j;
     while(n!=1)
     {      for(j=n,i=0;(i<prime_size)&&(prime[i]*prime[i]<=n);++i)
               if(n%prime[i]==0) {j=prime[i]; break;}
            p[p_size++]=j;
            while(n%j==0) n/=j;
     }
}

i64 phi(i64 n)
{        split(n);
         i64 i,tot=n;
         for(i=0;i<p_size;++i)
           tot=tot-tot/p[i];
         return tot;
}//end

i64 mod(i64 a,i64 b,i64 c)  // a*b%c
{   i64 res=0;
    while(b)
    {          if(b&1)   
               {      
                      res+=a;
                      if(res>=c)  res-=c;
               }
               a+=a;
               if(a>=c)   a-=c;
               b=b/2;
    }
    return res;
}//end

i64 pow_mod(i64 a,i64 b,i64 c)
{   i64 res=1;
    while(b)
    {        if(b&1)  res=mod(res,a,c);
             a=mod(a,a,c);
             b=b/2;
    }
    return res;
}//end
i64 solve(i64 n)
{   if(n==1)     return 1;
    i64 M=9*n/gcd(n,8),euler,i,check;
    if(gcd(M,10)!=1)  return 0;
    euler=phi(M);  
    split(euler);
    for(i=0;i<p_size;++i)
    {       check=pow_mod(10,euler,M);
            while(euler%p[i]==0&&check==1)
            {       euler/=p[i];
                    check=pow_mod(10,euler,M);
                    if(check!=1)  euler*=p[i];
            }
            
    }
    return euler;
}
    
int main()
{       i64 n,tc=0;
        init_prime();
        while(1)
        {        scanf("%I64d",&n);
                 if(n==0) break;
                 printf("Case %I64d: %I64d\n",++tc,solve(n));
        }
        return 0;
}
        




     
     

         



