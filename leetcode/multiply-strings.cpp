#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0") return "0";
    	int i , j , last , temp;
    	vector<int> result(num1.size() + num2.size()-1);
    	fill(result.begin(), result.end(), 0);
    	for(i = num1.size()-1; i >= 0; --i)
    		for(j = num2.size()-1; j >= 0 ; -- j){
    			result[i + j] += (num1[i] - '0') * (num2[j] - '0');
    		}
    	last = 0; 
    	for(i = result.size() - 1 ; i >= 0 ; --i){
    		temp = result[i] + last;
    		result[i] = temp % 10 ;
    		last = temp / 10;
    	}
    	if(last)
	    	result.insert(result.begin(), last);
	    string answer ; 
	    for(int i = 0 ; i < result.size(); ++ i)
	    	answer.append(1, result[i] + '0');
	    return answer;
    }
};

int main(){
	Solution sol;
	cout << sol.multiply("1234", "2") << endl;
	cout << sol.multiply("1234", "1") << endl;
	cout << sol.multiply("1234", "0") << endl;
	cout << sol.multiply("12343143435345452343234214313413413545436", "2341341311234") << endl;
	return 0;
}