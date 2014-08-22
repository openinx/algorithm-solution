#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int steps[1<<16], prev[1<<16];

void solve(int start, int end){
    if(start == end) {
        cout << "0" << endl; return ;
    }
    memset(prev, -1 , sizeof(prev));
    queue<int>  q;
    q.push(start); prev[start] = 0 ;
    while( !q.empty() ){
        int current = q.front(); q.pop();
        for(int i = 0 ; i < 4; ++ i)
            for(int j = 0 ; j < 4 ; ++ j){
                int next = current;
                for(int k = 0 ; k < 4 ; ++ k) { 
                    next ^= (1<<(4*i+k));
                    next ^= (1<<(4*k+j));
                }
                next ^= (1<<(4*i+j));
                if(prev[next] == -1){
                    prev[next] = current;
                    steps[next] = 4 * i + j;
                    q.push(next);
                }
            }
    }
    stack<int> paths;
    while(end != start){
        paths.push(steps[end]);
        end = prev[end];
    }
    cout << paths.size() << endl;
    while(!paths.empty()){
        int x = paths.top(); paths.pop();
        cout << x / 4 + 1 << " " << x % 4  + 1<< endl;
    }
}

int main(){
    char c ;
    int cnt = 0, beg = 0; 
    /*
    while(cnt < 16)
        if((c = getchar()) && (c == '+' || c == '-')){
            if(c == '+')
                beg |= (1<<cnt);
            ++ cnt;
        }
        */
    for(int i = 0 ; i < (1<<16); ++ i){
        solve(i, 0);
    }
    return 0 ;
}
