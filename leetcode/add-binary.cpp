#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int last = 0, temp, i, j; 
    	string c = ""; 
    	if(a.size() < b.size() ) swap(a, b);
    	for(i = a.size() -1 , j = b.size()-1 ; j >=0; --i, --j){
    		temp = last + (a[i] - '0') + (b[j] - '0');
    		c.append(1, (temp & 1) + '0');
    		last = temp >> 1 ; 
    	}
    	for( ; i >= 0 ; --i){
    		temp = last + a[i] - '0';
    		c.append(1, (temp & 1) + '0');
    		last = temp >> 1;
    	}
    	if(last)
    		c.append(1, '1');
    	reverse(c.begin(), c.end());
    	return cout;
    }
};

int main(){
	Solution sol;
	cout << sol.addBinary("0", "0") << endl;
	cout << sol.addBinary("1", "1") << endl;
	return 0;
}