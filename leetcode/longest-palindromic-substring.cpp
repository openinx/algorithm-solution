#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    string newStr(string s){
        int n = s.size(), i ;
        string ans;
        if(n == 0) return "^$";
        ans.append(1, '^');
        for(i = 0 ; i < s.size(); ++i){
            ans.append(1, '#');
            ans.append(1, s[i]);
        }
        ans.append("#$");
        return ans;
    }

    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        string t = newStr(s);
        int i , j, c = 0, r = 0, z,  n = t.size();
        vector<int> p(n, 0);
        for(i = 1; i < n; ++ i){
            z = c - ( i - c ); // mirror points of i
            p[i] = r > i ? min(r - i, p[z]) : 0 ;
            while(t[ i + p[i] + 1] == t[ i - p[i] - 1]) ++p[i];
            if( p[i] + i > r){
                r = i + p[i]; 
                c = i;
            }
        }
        i = max_element(p.begin(), p.end()) - p.begin();
        return s.substr((i - p[i] - 1)/2, p[i]);
    }
};

int main(){
	string s ;
    Solution sol1;
    cout << sol1.longestPalindrome("") <<endl;
	while(cin >> s){
		Solution sol;
		cout << sol.longestPalindrome(s)<< endl;
	}
	return 0;
}