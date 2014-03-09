#include<stdio.h>
#include<math.h>
#define _max_size 50000
#define _max_len 100


typedef __int64 i64;

const i64 MOD=9901;
i64 prime[_max_size],prime_size;
bool visit[_max_size];
i64 p[_max_len],p_size;
i64 cnt[_max_len],A,B;


void init_prime()
{    i64 i,j;
     for(i=1;i<_max_size;++i)  visit[i]=true;
     for(i=2;i<_max_size;++i)
         if(visit[i])
           for(j=i<<1;j<_max_size;j+=i)
              visit[j]=false;
     for(prime_size=0,i=2;i<_max_size;++i)
         if(visit[i])  prime[prime_size++]=i;
}
void split(i64 n)
{    i64 i,j;
     p_size=0;
     while(n!=1)
     {       for(j=n,i=0;(i<prime_size)&&(prime[i]*prime[i]<=n);++i)
                  if(n%prime[i]==0)  {j=prime[i]; break;}
             cnt[p_size]=0;
             while(n%j==0) {cnt[p_size]++; n/=j;}
             p[p_size++]=j;
     }
}
i64 pow_mod(i64 a,i64 b)// a^b%MOD
{    i64 res=1;
     while(b)
     {      if(b&1)   res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
     }
     return res;
}

i64 mod_exp(i64 n,i64 x)  // 1+x+x^2+x^3+x^4...+x^n
{    if(n==0)  return 1%MOD;
     if(n==1)  return (x+1)%MOD;
     i64 p,ans=0;
     if(n%2==1)
            p=n/2; 
     else     
     {   
         p=(n-1)/2; 
         ans+=pow_mod(x,n);
     }
     ans+=mod_exp(p,x)*(1+pow_mod(x,p+1))%MOD;
     ans=ans%MOD;
     return ans;
}

i64 solve()
{   split(A);
    i64 i,ans=1;
    for(i=0;i<p_size;++i)  cnt[i]=cnt[i]*B;
    for(i=0;i<p_size;++i)
       ans=ans*mod_exp(cnt[i],p[i])%MOD;
    return ans%MOD;
}


         
int main()
{        init_prime();
         while(scanf("%I64d%I64d",&A,&B)!=EOF)
                      printf("%I64d\n",solve());
         return 0;
}






 


