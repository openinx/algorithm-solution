#  include<cstdio>
#  include<cstring>
#  include<cstdlib>
#include<time.h>
 
#define Min(a,b) (a<b?a:b)
struct arr
{
       int x,y;
}hash[250008],a1,a2;
int  p=4877;
int n,m,f[505][505],ans,x1,x2,y1,y2,a[505][505],g[505][505],b[250008],next[250008],start[530000],tot;
long long s[505];
 
void  Init()
{
      int i,j;
      char c , car[505][505];
      scanf("%d%d",&n,&m);
      
      for(i = 0 ; i < n ; ++ i)   scanf("%s" , car[i]);
      
      for  (i=1;i<=n;i++)
      {
           for  (j=1;j<=m;j++)
           {
                //scanf("%c",&a[i][j]);
                a[i][j]= car[i-1][j-1] - 97;
           }     
           //scanf("%*c");
      }
      s[0]=1;
      for  (i=1;i<=n;i++) s[i]=(p*s[i-1])&524287;
}
 
void  Insert(int x,arr t)//将HASH值x插入链表 
{
      hash[++tot]=t;
      next[tot]=start[x];
      start[x]=tot;
}
 
bool  Cmp(int x,int l)//比较HASH值为X的相同矩阵是否出现过 
{
      int i,j;
      for  (int g=start[x];g;g=next[g])
      {
           a2=hash[g];j=l;
           for  (i=0;i<l&&j>=l;i++)   
               if  (f[a1.x][a1.y-i]!=f[a2.x][a2.y-i]) break;
           if  (i>=l) 
           {
               if  (l>ans) ans=l,x1=a1.x,y1=a1.y,x2=a2.x,y2=a2.y;
               return true;
           }
      }
      return false;
}
 
void  Work()
{
      int i,j,k,l,r;
      r=Min(n,m);l=1;
      while  (l<=r)
      {
             k=l+r>>1;
             for  (i=1;i<=n;i++)
                  for  (j=1;j<=m;j++)
                  {
                       if  (i<k) f[i][j]=f[i-1][j]*p+a[i][j]&524287;
                       else  f[i][j]=((f[i-1][j]-a[i-k][j]*s[k-1]&524287)+524288&524287)*p+a[i][j]&524287;//减去最高位，加上最低位 
 
                  }//f[i][j]存下第j列第i行往上长度为k的串的HASH值 
             memset(start,0,sizeof(start));tot=0;
             for  (j=1;j<=m&&i>n;j++)
                  for  (i=k;i<=n;i++)
                  {
                       if  (j<k) g[i][j]=g[i][j-1]*p+f[i][j]&524287;
                       else 
                       {
                            g[i][j]=((g[i][j-1]-f[i][j-k]*s[k-1]&524287)+524288&524287)*p+f[i][j]&524287;
                            if  (Cmp(g[a1.x=i][a1.y=j],k))   break;
                            Insert(g[i][j],a1);
                       }
                  }//g[i][j]存下右下角为第i行第j列长度为k的矩阵的HASH值 
             if  (j<=m) l=k+1;else r=k-1;
 
      }
      /*
      if  (ans)  printf("%d\n%d %d\n%d %d\n",ans,x1-ans+1,y1-ans+1,x2-ans+1,y2-ans+1);
      else  printf("0\n");
      */
      printf("%d\n" , ans );
}
 
void solve(){
     Init();
     Work();
}
 
 
int  main()
{
     //freopen("1.std.in" ,"r" , stdin);  freopen("code2.std.out" ,"w" ,stdout);
     
     //clock_t start , end ; 
     //start = clock();
     
     int testCase ; 
     scanf("%d" ,&testCase);
     while(testCase--) 
     solve();
     
     //end = clock();
     //printf("time : %d ms\n" , (int)(end - start));
     
     //fclose(stdin) ; fclose(stdout);
     
     return 0;
}
