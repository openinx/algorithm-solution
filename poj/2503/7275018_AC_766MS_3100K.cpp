#include<iostream>
#include<algorithm>
using namespace std;
struct node {
       char s[15],u[15];
};

node ST[100005];
int  ST_size;

bool cmp(node a,node b)
{    
     return strcmp(a.u,b.u) < 0 ;
}

int bbs(char *s)
{   
    int l = 0, r = ST_size-1 , mid;
    while( l <= r )
    {   
          mid = ( l + r ) >> 1;
          int t = strcmp(s,ST[mid].u);
          if( t==0)  return mid;
          else  if(t<0) r = mid - 1;
          else  l = mid + 1;
    }
    return -1;
}


int main()
{   
    int i,j,t;
    char s[13],u[13];
    ST_size = 0;
    while(1)
    {    
        char c = getchar();
        if(c=='\n') break;
        for(i = 0 , s[i] = c ; (c=getchar())!=' ' ; ++i,s[i]=c); s[i+1]='\0';
        for(c = getchar(),i= 0; c!='\n'; u[i++]=c,c=getchar()) ; u[i]='\0';
        strcpy(ST[ST_size].s , s);
        strcpy(ST[ST_size].u , u);
        ++ST_size;
    }
    sort(ST ,ST+ST_size,cmp);
    //for(i=0;i<ST_size;++i) printf("%s#\n",ST[i].u);
    while(scanf("%s",s)!=EOF)
    {      
          int id = bbs(s);
           if(id!=-1) printf("%s\n",ST[id].s);
              else printf("%s\n","eh");
    }
    return 0;
} 
    
        
         
