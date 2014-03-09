#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define maxn 25
using namespace std;

struct node{
       int id,role,t;
       char name[maxn];
};

int cnt[4];
node p[maxn];

int toN(char *s){
    int i,len=strlen(s),tot=0,c;
    for(i=len-1,c=1;i>=0;--i,c*=10) tot += (s[i]-'0')*c;
    return tot;
} 

char OK[5]="GDMS";
int  Find(char c){
     int i;
     for(i=0;i<4;++i) 
       if(c==OK[i]) return i;
     return -1;
}


bool GetInfo(node &a){
     char c,y[6],x[6];
     int i,j;
     scanf("%d",&a.id); if(a.id==0) return false;
     scanf("%s %c",a.name,&c);
     a.role=Find(c);
     a.t=0;
     while(1){
     c = getchar();  if(c=='\n') break;
     y[0]=getchar() ;
     y[1]=getchar(); y[2]=getchar(); y[3]=getchar(); y[4]='\0';
     getchar(); // -
     x[0]=getchar(); x[1]=getchar(); x[2]=getchar(); x[3]=getchar(); x[4]='\0';
     a.t += toN(x) - toN(y) + 1;
     }
     return true;
}

node ans[maxn];
bool can(){
     int i,j,k,cap = 1,curs;
     curs = 1;
     for(i=0;i<4;++i){
      for(j=0;j<cnt[i];++j){ 
           int pos , md = 200;
           for(k=curs;k<=22;++k)
             if(p[k].role == i && p[k].id < md) {  pos = k , md = p[k].id ; }
           if(md == 200) return false;
           swap(p[pos],p[curs]);
           ++curs;
      }
     }
     for(i=2;i<=11;++i)
       if(p[cap].t < p[i].t ||(p[cap].t == p[i].t && p[cap].id < p[i].id))  cap = i;
     ans[1]=p[cap];  j = 1;
     for(i=1;i<cap;++i) ans[++j]=p[i];
     for(i=cap+1;i<=11;++i) ans[++j]=p[i]; 
     return true;
}

void show(){
     int i;
     for(i=1;i<=11;++i)
       printf("%d %s %c\n",ans[i].id,ans[i].name,OK[ans[i].role]);
}

int main(){
    int  i;
    while(1){
    if(GetInfo(p[1]) == false )  break;
    for(i=2;i<=22;++i) GetInfo(p[i]);
    cnt[0]=1;
    cnt[1]=getchar()-'0'; getchar(); cnt[2]=getchar()-'0'; getchar(); cnt[3]=getchar()-'0'; getchar();
    if(!can())
        printf("IMPOSSIBLE TO ARRANGE\n"); 
    else 
        show();
    printf("\n");
    }
    return 0;
}
