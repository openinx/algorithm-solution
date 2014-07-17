#include <iostream>
using namespace std;

class Solution {
public:
    #define LOWBIT(x) ((x)&(-x))
    void dfs(int row, int ld, int rd, int n, int &sum){
        int M = (1<<n)-1, pos, p;
        if(row == M) {  ++ sum; return;} 
        pos = ((row|ld|rd) & M) ^ M; 
        while(pos){
            p = LOWBIT(pos);
            dfs(row|p, (ld|p)<<1, (rd|p)>>1, n, sum);
            pos -= pos & p;
        }
    }
    int totalNQueens(int n) {
        int sum = 0; 
        dfs(0, 0, 0, n, sum);
        return sum;
    }
};

int main(){
    Solution sol;
    for(int i = 4 ; i <= 12 ; ++ i){
        Solution sol;
        cout << sol.totalNQueens(i) << endl;
    }
    return 0;
}