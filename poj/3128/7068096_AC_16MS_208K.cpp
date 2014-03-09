#include<iostream>
using namespace std;

int len[30],visit[30],per[30];
char s[30];

int main()
{   
    int T,i,j,cnt;
    cin>>T;
    while(T--)
    {    
         cin>>s;
         for(i=1;i<=26;++i)  per[i]=s[i-1]-'A'+1;
         memset(visit,false,sizeof(visit));
         memset(len,0,sizeof(visit));
         for(i=1;i<=26;++i)
           if(!visit[i])
           {    
                cnt=0;
                for(j=i;visit[j]==false;j=per[j])
                {  
                        ++cnt;
                        visit[j]=true;
                }
                len[cnt]++;
           }
         bool check=true;
         for(i=2;(i<=26)&&(check);i+=2)
           if(len[i]%2==1) check=false;
         if(check)  cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
    }
    return 0;
}              
         
         
         
         
    
