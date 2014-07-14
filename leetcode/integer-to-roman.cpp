#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
    	string bit0[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    	string bit1[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    	string bit2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    	string bit3[] = {"", "M", "MM", "MMM"};
    	int i0, i1, i2, i3;
    	i0 = num % 10 ;
    	if(num < 10) return bit0[num];
    	num /= 10; i1 = num % 10 ;
    	if(num < 10) return bit1[i1] + bit0[i0];
    	num /= 10; i2 = num % 10 ;
    	if(num < 10) return bit2[i2] + bit1[i1] + bit0[i0];
    	num /= 10; i3 = num % 10 ;
    	return bit3[i3] + bit2[i2] + bit1[i1] + bit0[i0];
    }
};

class Solution2{
public:
	string romanToInt(string s){

	}
};


int main(){
	Solution sol; 
	//cout << sol.intToRoman(100) << endl;
	for(int i = 1; i <= 3999 ; ++ i)
		cout << i << " : " << sol.intToRoman(i) << endl;
	return 0;
}