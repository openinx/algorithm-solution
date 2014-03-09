#include<stdio.h>
#define Maxrow 20
#define Maxcolumn 302
int p[Maxrow][Maxcolumn];
int n,m,cr[Maxrow],cc[Maxcolumn],cur,x[Maxrow];

bool visit[Maxcolumn];
bool check()
{    int i;
     for(i=1;i<=m;++i) if(!visit[i])  return false;
     return true;
}
bool dfs(int k)
{    int i,j;
     bool ok;
     if(k>n) 
     {  if(check())  return true;
        return false;
     }
     if(check()) return true;   
     if(cur+x[k+1]>=m) 
        if(dfs(k+1))  return true; // we don't choose the row
     for(i=1;i<=m;++i)
        if(p[k][i]&&visit[i]) return false;   // check if it satisfy precondition 
     for(i=1;i<=m;++i) if(p[k][i]) visit[i]=true;
         cur+=cr[k];
          ok=false;
           if(cur+x[k+1]>=m)
              if(dfs(k+1))  return true;   // we choose this row 
         cur-=cr[k];
     for(i=1;i<=m;++i) if(p[k][i]) visit[i]=false;
     return ok;
}         
     
bool find()
{    int i,j;
     for(i=1;i<=n;++i)  cr[i]=0;  // init the visit and the count of row
     for(j=1;j<=m;++j) { cc[j]=0; visit[j]=false;}
     for(i=1;i<=n;++i)
       for(j=1;j<=m;++j)
        if(p[i][j]){ cr[i]++; cc[j]++;}
     for(i=1;i<=n;++i) if(cr[i]==m) return true;
     for(j=1;j<=m;++j) if(cc[j]==0) return false;   
     x[n+1]=0;
     for(i=n;i>=1;i--) x[i]=x[i+1]+cr[i];
     cur=0;
     return dfs(1);
}                    
int main()
{   int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {     for(i=1;i<=n;++i)
             for(j=1;j<=m;++j)
             scanf("%d",&p[i][j]);   
          if(find()) printf("Yes, I found it\n");
           else printf("It is impossible\n");
    }
    return 0;
}           
