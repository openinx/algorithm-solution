#include<stdio.h>
#include<string.h>
#define min(a,b) ( (a)<(b) ? (a):(b))
const int maxn = 105;
char s[maxn];
int n,opt[maxn][maxn];

void print(int i,int j)
{    
     int k;
     if(i==j)
     {    
          if(s[i]=='(' || s[i] ==')')  printf("()");
          else  printf("[]");
          return ;
     } 
     for(k=i;k<j;++k)
       if(opt[i][j] == opt[i][k] + opt[k+1][j]){
                   print(i,k) ; 
                   print(k+1,j);
                   return ;
       }
     if(opt[i][j]== opt[i+1][j] + 1)
     {       
             switch(s[i])
             {   
                 case '(': printf("(");  print(i+1,j); printf(")");return;
                 case ')': printf("()"); print(i+1,j); return ;
                 case ']': printf("[]"); print(i+1,j); return ;
                 case '[': printf("[");  print(i+1,j); printf("]");return;
             }
     }
     if(opt[i][j] == opt[i][j-1] + 1)
     {
            switch(s[j])
            {    
                 case '(':   print(i,j-1); printf("()"); return ;
                 case ')':   printf("(");  print(i,j-1); printf(")"); return;
                 case '[':   print(i,j-1); printf("[]"); return ;
                 case ']':   printf("[");  print(i,j-1); printf("]"); return ;
            }
     }
     switch(s[i])
     {    
          case '(':  printf("(");  print(i+1,j-1); printf(")"); return;
          case '[':  printf("[");  print(i+1,j-1); printf("]"); return ;
     }    
}



bool can()
{   
    int i,j,k,del;
    if(scanf("%s",s)==EOF) return 0;
    n = strlen(s);
    for(i = n+1 ;i>=1;i--) s[i] = s[i-1];
    for(i=1;i<=n;++i) opt[i][i] = 1;
    for(i=1;i<=n-1;++i) opt[i+1][i] = 0;
    for(del = 1 ; del < n; ++del)
    {
         for(i = 1 ; i+del <=n;++i)
         {
               j = i + del;
               opt[i][j] = min( opt[i][j-1] + 1, opt[i+1][j] + 1);
               if( (s[i]=='(' && s[j] == ')' ) || ( s[i]=='[' && s[j] == ']' ) )
                   opt[i][j] = min(opt[i][j],opt[i+1][j-1]);
               for(k=i ; k<j;++k)
                   opt[i][j] = min(opt[i][j],opt[i][k]+opt[k+1][j]);
         }
    }
    print(1,n);
    return 1;
}

int main()
{   
    while(can());
    return 0;
}

