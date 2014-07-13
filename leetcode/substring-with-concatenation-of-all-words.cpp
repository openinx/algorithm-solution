#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define unordered_map map
#define unordered_set set

class Solution {
public:
	void findIndex(string S, int start, int wordLen, int suml ,
				   unordered_map<string, int> &umap, vector<int> &result){
		if(start + suml > S.size()) return;
		unordered_map<string, int> dict;
		int i = start, j = start, curl = 0 ;
		for(int i = start; i + wordLen <= S.size(); i += wordLen){
			string str = S.substr(i, wordLen);
			if(umap[str] == 0) {
				dict.clear();
				j = i + wordLen; 
				curl = 0;
				continue;
			}
			while(j < i  && dict[str] >= umap[str]) {
				string prev = S.substr(j, wordLen);
				dict[prev]--;
				curl -= wordLen;
				j += wordLen;
			}
			dict[str] ++ ;
			curl += wordLen;
			if(curl == suml)
				result.push_back(i + wordLen - suml);
		}
	}

    vector<int> findSubstring(string S, vector<string> &L) {
    	unordered_map<string, int> umap;
    	vector<int> result;
    	for(int i = 0 ; i < L.size(); ++ i) umap[L[i]] ++ ;
    	int wordLen = L[0].size();
    	for(int i = 0 ; i < wordLen; ++ i)
	    	findIndex(S, i, wordLen, wordLen * L.size(), umap, result);
	    return result;
    }
};


int main(){
	int n ; 
	string S ;
	while(cin >> n >> S){
		Solution sol ; 
		vector<string> L ;
		for(int i = 0 ; i < n ;++ i){
			string word; 
			cin >> word; 
			L.push_back(word);
		}
		vector<int> result = sol.findSubstring(S,L) ; 
		cout << "####: " ; 
		for(int i = 0 ; i < result.size() ; ++ i)
			cout << " " << result[i]  ; 
		cout << endl ;
	}
	return 0 ;
}