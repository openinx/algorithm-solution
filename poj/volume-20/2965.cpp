#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int steps[1<<16], prev[1<<16], q[1<<16], head, tail;

void solve(int start){
    head = tail = 0 ;
    q[tail ++ ] = start; prev[start] = 0 ;
    while(head < tail){
        int current = q[head++]; 
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
                    q[tail++] = next;
                }
            }
    }
}

int main(){
    char c ;
    int cnt = 0, beg = 0; 
    memset(prev, -1 , sizeof(prev));
    solve(0);
    while(cnt < 16)
        if((c = getchar()) && (c == '+' || c == '-')){
            if(c == '+')
                beg |= (1<<cnt);
            ++ cnt;
        }
    vector<int> ret;
    while(beg != 0){
        ret.push_back(steps[beg]);
        beg = prev[beg];
    }
    cout << ret.size() << endl;
    for(int i = ret.size() -1 ; i >= 0 ; --i){
        cout << ret[i] / 4 + 1  << " " << ret[i] % 4 + 1 << endl;
    }
    return 0 ;
}
