#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;



class Solution {
public:
	void init(char *t, int *p, int m){
		int i , j; 
		p[0] = -1;
		for(i = 1; i < m ; ++ i){
			j = p[i-1] + 1;
			while(j > 0 && t[i] != t[j]) j = p[j-1] + 1;
			p[i] = (t[i] == t[j] ? j: -1);
		}
	}

	char* kmp(char *s, char *t){
		int n = strlen(s), m = strlen(t);
		if( m == 0 )
			return s ; 
		int i, j , *p = new int[m];
		init(t, p, m);
		j = 0 ; 
		for(i = 0 ; i < n ; ++ i){
			while(j > 0 && s[i] != t[j]) j = p[j-1] + 1;
			if(s[i] == t[j]) j++;
			if(j == m ) return s + i - m + 1; 
		}
		return NULL;
	}

    char *strStr(char *haystack, char *needle) {
    	return kmp(haystack, needle);
    }
};


int main(){
	int i , j ; 
	Solution sol;
	char s[] = "mississippi", t[] = "issi";
	cout << sol.strStr(s, t) - s << endl ;
	return 0 ;
}