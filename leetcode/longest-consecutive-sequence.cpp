#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        sort(num.begin(), num.end()) ;
        int cnt = 1, res = 1 ; 
        for(int i = 1 ; i < num.size(); ++ i){
            if(num[i] == num[i-1] + 1){
                cnt ++ ; 
                res = max( res, cnt ) ;
            }else{
                cnt = 1 ; 
            }
        }
        res = max(res, cnt ) ; 
        return res; 
    }
};

int main(){
    Solution sol ;
    vector<int> v ; 
    v.push_back(1) ; 
    v.push_back(2) ; 
    v.push_back(0) ;
    v.push_back(1) ;
    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size(); ++ i) 
        cout << "## " << v[i] << endl;  
}