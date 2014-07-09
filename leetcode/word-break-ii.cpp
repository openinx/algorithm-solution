struct node{ 
    string str; 
    int prev ; 
    node(string s, int p): str(s), prev(p) {}
};

class Solution {
public:
    vector<string> back(vector<node> *dp, int index){
        vector<string> ret; 
        if(index < 0 ) return ret;
        for(int i = 0 ;  i < dp[index].size(); ++ i){
            node t = dp[index][i] ;
            if(t.prev < 0 ){
                ret.push_back(t.str);
            }else{
                vector<string> v = back(dp, t.prev);
                for(int k = 0 ;k < v.size(); ++ k){
                    ret.push_back(v[k].append(" ").append(t.str));
                }
            }
        }
        return ret;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    	vector< node > dp[s.size()]; 
    	for(int i = 0 ; i < s.size(); ++ i){
    		for(int k = 0 ; k <= i ; ++ k){
    			string str = s.substr(k, i+1-k);
    			if(dict.find(str) != dict.end()){
    			    dp[i].push_back(node(str, k-1));
    			}
    		}
    	}
    	return back(dp, s.size()-1);
    }
};