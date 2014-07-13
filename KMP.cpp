class Solution {
public:
	void init(char *t, int *p, int m){
		int i , j; 
		p[0] = -1;
		for(i = 1; i < m ; ++ i){
			j = p[i-1];
			while(j>=0 && t[i] != t[j+1]) j = p[j];
			p[i] = (t[i] == t[j+1] ? j+1: -1);
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
			if(j == m ) return s + i - m + 1 ; 
		}
		return NULL;
	}

    char *strStr(char *haystack, char *needle) {
    	return kmp(haystack, needle);
    }
};
