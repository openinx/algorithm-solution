#include<stdio.h>
#define _max_size 30000

typedef __int64 i64;

const i64 MOD = 9901;
i64 prime[_max_size],prime_size;
bool visit[_max_size];
i64 p[100],p_size,cnt[100];
i64 A,B;

i64 gcd(i64 a,i64 b) 
{   return b==0 ? a:gcd(b,a%b);}

void init()
{    i64 i,j;
     for(i=0;i<_max_size;++i)  visit[i]=true;
     for(i=2;i<_max_size;++i)
        if(visit[i])
          for(j=i+i;j<_max_size;j+=i)
               visit[j]=false;
     for(prime_size=0,i=2;i<_max_size;++i)
         if(visit[i]) prime[prime_size++]=i;
}

void split(i64 n)
{    p_size=0;
     i64 i=0,j;
     while(n!=1)
     {     for(j=n,i=0;(i<prime_size)&&(prime[i]*prime[i]<=n);++i)
              if(n%prime[i]==0) {j=prime[i]; break;}
           cnt[p_size]=0;
           while(n%j==0) {n/=j;  cnt[p_size]++;}
           p[p_size++]=j;
     }
}

i64 pow_mod(i64 a,i64 b,i64 c)
{   i64 res=1,t;
    while(b)
    {     t=a%c;
          if(b&1)  res=res*t%c;
          a=t*t%c;
          b>>=1;
    }
    return res;
}
           

i64 solve()
{   i64 i,j,ans=1,pz,tp;
    if(A==0)  return 0;
    if(A==1)  return 1;
    split(A);
    for(i=0;i<p_size;++i) cnt[i]*=B;
    for(i=0;i<p_size;++i)
    {    
         if(gcd(p[i]-1,MOD)!=1) 
         {   
             ans=ans*(cnt[i]%MOD+1)%MOD;
         }
         else 
         {   pz=(pow_mod(p[i],cnt[i]+1,MOD)-1+MOD)%MOD;
             for(j=0;j<MOD;++j)
                 if((p[i]-1)%MOD*j%MOD==pz) 
                 {      ans=ans*j%MOD;
                        break;
                 }
             
         }
    }
    return ans;
}    
    
     
    
     

int main()
{    
     init();
     while(scanf("%I64d%I64d",&A,&B)!=EOF)
        printf("%I64d\n",solve());
     return 0;
}
      
