#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
    	int i, j, n = word1.size(), m = word2.size();
    	if(n == 0 ) return m;
    	if(m == 0 ) return n;
    	vector<int> prev(m+1), now(m+1);
    	for(i = 0 ; i <= m ; ++ i) prev[i] = i;
    	for(i = 1 ; i <= n ; ++ i){
    		now[0] = i;
    		for(j = 1 ; j <= m; ++ j){
    			now[j] = min(prev[j] + 1, min(now[j-1] + 1, prev[j-1] + 1));
    			if(word1[i-1] == word2[j-1])
    				now[j] = min(now[j], prev[j-1]);
    		}
    		for(j = 0 ; j <= m; ++ j)
    			prev[j] = now[j];
    	}
    	return prev[m];
    }
};


int main(){
	Solution sol;
	cout << sol.minDistance("hello", "helloworld") << endl;
	cout << sol.minDistance("a", "aaa") << endl;
	cout << sol.minDistance("", "aaaa") << endl;
	cout << sol.minDistance("abaaaaaaaa", "aaaaaaaaaa") << endl;
	return 0;
}