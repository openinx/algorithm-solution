#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
struct phone
{
       char tel[8];
       bool operator<(const phone& other)const
       {
            return strcmp(tel,other.tel)<0;
       }
};
char toDigital(char ch)
{
     switch(ch)
     {
       case 'A': case 'B': case 'C': return '2'; 
       case 'D': case 'E': case 'F': return '3'; 
       case 'G': case 'H': case 'I': return '4';
       case 'J': case 'K': case 'L': return '5'; 
       case 'M': case 'N': case 'O': return '6'; 
       case 'P': case 'R': case 'S': return '7'; 
       case 'T': case 'U': case 'V': return '8'; 
       case 'W': case 'X': case 'Y': return '9';  
     }
     return -1;
}

int main()
{
    map<phone,int> data;
    map<phone,int>::iterator it;
    int N;
    scanf("%d",&N);
    int i;
    char ch;
    char buf[8];
    int index;
    phone temp;
    for(i=0;i<N;++i)
    {
        index=0;
        while(ch=getchar())
        {
              if(isdigit(ch))
              {
                  buf[index++]=ch;
              }
              else if(isupper(ch))
              {
                   buf[index++]=toDigital(ch);
              }
              else
                ;
              if(7==index)
              {
                    buf[index]=0;
                    strcpy(temp.tel,buf);
                    if(data.end()==data.find(temp))
                    {
                       data.insert(pair<phone,int>(temp,1));
                    }
                    else
                    {
                        data[temp]+=1;
                    }
                    break;      
              }
        }
    }
    bool hasDup=false;
    for(it=data.begin();it!=data.end();++it)
    {
        if(it->second>1)
        {
            hasDup=true;
            int j;
            for(j=0;j<3;++j)
            {
                 printf("%c",(it->first).tel[j]);
            }
            printf("%c",'-');
            for(j=3;j<7;++j)
            {
                  printf("%c",(it->first).tel[j]);
            }
            printf("%c",' ');
            printf("%d\n",it->second);
        }                                    
    }
    if(!hasDup)
    {
        printf("No duplicates.\n");
    }
//    system("pause");
    return 0;
}
