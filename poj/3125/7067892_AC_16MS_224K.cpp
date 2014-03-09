#include<iostream>
#include<vector>
using namespace std;

struct  node
{    int id;
     int e;
};

const int _size =105;
int n,m;
node tp;


int main()
{  
    int T,i,ans;
    cin>>T;
    while(T--)
    {     
          vector<node> v;
          cin>>n>>m;
          for(i=0;i<n;++i)
          {     tp.id=i;
                cin>>tp.e;
                v.insert(v.end(),tp);
          }
          vector<node>::iterator it,jt;
          ans=0;
          for(it=v.begin();it!=v.end();it=v.begin())
          {    
               for(jt=it+1;jt!=v.end();jt++)  if((*jt).e>(*it).e) break;
               if(jt!=v.end()) 
               {   
                   tp.id=(*it).id;
                   tp.e=(*it).e;
                   v.erase(v.begin());
                   v.insert(v.end(),tp);
               }
               else 
               {   bool check=false;
                   if((*v.begin()).id==m) check=true;
                   v.erase(v.begin());
                   ++ans;
                   if(check) break;
               }
          }
          cout<<ans<<endl;
          v.clear();
    }
    return 0;
}
          
             
         
    



             
        

     
     
