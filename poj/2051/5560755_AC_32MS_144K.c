#include<stdio.h>
#include<string.h>
typedef struct {
int person;
int period;
}Node;
Node N[1001];
void sort(int count)
{  Node e;
   int i,j;
   for(i=1;i<=count-1;i++)
     for(j=1;j<=count-i;j++)
     if(N[j].person>N[j+1].person)
     {  e=N[j];
        N[j]=N[j+1];
        N[j+1]=e;
     }
}        
int main()
{   int i,count=1,j,k,t=1;
    char ch[20];
    int m[1001],min,index,number;
    for(i=0;i<1001;i++) m[i]=1;
    scanf("%s",ch);
    while(strcmp(ch,"#"))
    {   scanf("%d%d",&N[count].person,&N[count].period);
        count++;
        scanf("%s",ch);
    }
    scanf("%d",&number);
    sort(count-1);
    while(t<=number)
    {   min=20000;
         for(i=1;i<count;i++)
          if(m[i]*N[i].period<min)
           {  min=m[i]*N[i].period;
              index=i;
           }
        m[index]++;
       printf("%d\n",N[index].person);      
       t++;
    }
    return 0;
}      

