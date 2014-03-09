#include<iostream>
#include<stdlib.h>
#define maxlen 20
using namespace std;
typedef __int64 i64;
char a[maxlen],b[maxlen];
i64  k[maxlen],n;

i64 pow10(i64 i){
    i64 t=1;
    while(i--) t = t*10;
    return t;
}

i64 comp(i64 i){
    if(i==n) return 0;
    if(a[i]!='?'){
       if(a[i]>b[i])  return pow10(k[i]);
       if(a[i]==b[i]) return comp(i+1);
       if(a[i]<b[i])  return 0;
    }
    return (9-(b[i]-'0'))*pow10(k[i]) + comp(i+1);
}

int main(){
    i64 i;
    while(1){
      scanf("%s",a); 
      if(!strcmp(a,"#")) break;
      scanf("%s",b);
      n = strlen(a);
      memset(k,0,sizeof(k));
      for(i=n-2;i>=0;i--){  
        if(a[i+1]=='?') k[i]=k[i+1]+1;
        else k[i]=k[i+1];
      }
      printf("%I64d\n",comp(0));
    }
    return 0;
}

