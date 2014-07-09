class Solution {
public:
    bool is_palindrome(string s){
        for (int i = 0, j = s.size() - 1 ; i < j ; ++ i , --j )
            if (s[i] != s[j]) return 0; 
        return 1; 
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>  result ;
        vector<string> row ;
        if(is_palindrome(s)){
            row.push_back(s) ; 
            result.push_back(row) ; 
        }
        for(int i = 1 ; i < s.size() ; ++ i){
            string a = s.substr(0, i), b = s.substr(i, s.size() - i ) ; 
            if (!is_palindrome(a))  continue ;
            vector<vector<string>> all = partition(b) ;
            for (int k = 0 ;k < all.size() ; ++ k) {
                all[k].insert(all[k].begin() , a );
                result.push_back(all[k]) ; 
            }
        }
        return result ; 
    }
};
