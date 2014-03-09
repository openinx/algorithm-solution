#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{   
     char s[35];
     int tot = 0;
     map< string , int> M;
     map< string , int >::iterator it;
      while(gets(s)!=NULL)
      {  

         ++ tot ;
         string str =s;
         M[str] ++;
      }
      for(it = M.begin() ; it!=M.end(); it++) 
      {
        cout<<it->first<<" ";
        printf("%0.4f\n",(double)it->second / (double) tot * 100);
      }
      return 0;
}
