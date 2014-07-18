#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	string lastLine(vector<string> &words, int start, int end, int L){
		string buf; 
		buf.append(words[start]);
		for(int i = start + 1; i <= end; ++ i){
			buf.append(" ");
			buf.append(words[i]);
		}
		buf.append(L - buf.size(), ' ');
		return buf;
	}

	string midLine(vector<string> &words, int start, int end, int spaces, int L){
		string buf;
		buf.append(words[start]); 
		if(start == end){
			buf.append(L - buf.size(), ' ');
			return buf;
		}
		int n = spaces / (end - start) , m = spaces % (end - start), i, space;
		for(i = start + 1 ; i <= end; ++ i){
			space = n;
			if( i - start  <= m ) 
				++ space;
			buf.append(space, ' ');
			buf.append(words[i]);
		}
		return buf;
	}

    vector<string> fullJustify(vector<string> &words, int L) {
    	vector<string> result;
    	if(words.size() == 0) return result;
    	int i, k, n = words.size();
    	string line;
    	vector<int> sum(n);
    	sum[0] = words[0].size();
    	for(i = 1 ; i < n ; ++ i) 
    		sum[i] = sum[i-1] + words[i].size();
    	for(i = 0 ; i < n; ){
    		int prev = (i== 0 ? 0 : sum[i-1]);
    		for(k = i ; k < n; ++ k)
    			if(sum[k] - prev + (k - i) <= L && (k >= n - 1 || sum[k+1] - prev + (k + 1 - i) > L ))
    				break;
    		if(k >= n - 1)
    			line = lastLine(words, i, n-1 , L);
    		else
    			line = midLine(words, i, k , L - (sum[k] - prev), L);
    		result.push_back(line);
    		i = k + 1;
    	}
    	return result;
    }
};

int main(){
	Solution sol;
	string strs[] = {"a", "This", "is", "an", "example", "of", "text", "justification."};
	//string strs[] = {"a", "b", "ccccccccccccc"};
	vector<string> words(strs, strs + sizeof(strs) / sizeof(string));
	vector<string> result;
	result = sol.fullJustify(words, 16) ;
	for(int i = 0 ;i < result.size(); ++ i){
		cout << result[i] << endl;
	}
	return 0 ;
}