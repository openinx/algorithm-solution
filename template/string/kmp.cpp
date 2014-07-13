#include <iostream>
#include <string.h>

using namespace std;

class KMP{
public:
	void init(char *t, int m){
		int i , j; 
		p[0] = -1;
		for(i = 1; i < m ; ++ i){
			j = p[i-1] + 1;
			while(j > 0 && t[i] != t[j]) j = p[j-1] + 1;
			p[i] = (t[i] == t[j] ? j: -1);
		}
	}

	int solve(char *s, char *t){
		int n = strlen(s), m = strlen(t), i ,j;
		if( m == 0 ) return 0;
		init(t, m);
		j = 0 ; 
		for(i = 0 ; i < n ; ++ i){
			while(j > 0 && s[i] != t[j]) j = p[j-1] + 1;
			if(s[i] == t[j]) j++;
			if(j == m ) return i - m + 1 ; 
		}
		return -1;
	}

private:
	static const int MAXN = 1<<20 ; 
	int p[MAXN];
};


int main(){
	char s[] = "abbbbaabbbaa", t[] = "aabcb";
	KMP kmp;
	cout << kmp.solve(s, t) << endl; 
	return 0 ;
}