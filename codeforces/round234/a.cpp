#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t ; 
    char s[13];
    scanf("%d", &t);
    while(t--){
        vector< pair<int,int> > vec ;

        vec.clear();
        scanf("%s", s);

        for(int i = 1 ; i <= 12; ++ i)
            if(12 % i  == 0){
                bool check = 0 ; 
                int x = i, y = 12 / i ; 
                for(int c = 0 ; c < y ; ++ c)
                {
                    bool allx = 1 ;
                    for(int r = 0 ; r < x ; ++ r)
                        if(s[r * y + c] != 'X')
                        {
                            allx = 0 ;
                            break;
                        }
                    if (allx == 1){
                        check = 1 ; 
                        break; 
                    }
                }
                if(check)
                {
                    vec.push_back( pair<int,int>(x, y) ) ; 
                }
            }

        printf("%d", (int)vec.size());
        for(int i = 0 ; i < vec.size(); ++ i){
            pair<int, int> p = vec[i];
            printf(" %dx%d", p.first, p.second);
        }
        printf("\n");
    }
    return 0 ;
}
