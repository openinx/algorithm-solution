#include <iostream>
#include <algorithm>
using namespace std;

struct node {
   int sorted;
   char m[355];
}str[355];
int cmp(const void* a,const void* b) {
   return ((node *)a)->sorted - ((node *)b)->sorted;
}
int main() {
   int n, m;
   cin>>n>>m;
   for(int i = 0;i < m; i++)
      for(int j = 0; j < n; j++)
         cin>>str[i].m[j];
   for(int k = 0; k < m; k++)
      for(int i = 0; i < n; i++)
         for(int j =i+1; j < n; j++)
            if(str[k].m[i] > str[k].m[j])
               str[k].sorted++;
   qsort(str,m,sizeof(str[0]),cmp);
   for(int i = 0; i < m; i++)
      cout<<str[i].m<<endl;
   system("pause");
   return 0;
}
