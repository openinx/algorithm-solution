#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


int n , p , hash[300], x[300];

int solve(){
	for(int i = 0 ; i < n ; ++ i)
		cin >> x[i];
	memset(hash, -1, sizeof(hash));
	for(int i = 0 ; i < n ; ++ i){
		int index = x[i] % p ; 
		if(hash[index] == -1)
			hash[index] = 0;
		else
			return i + 1 ;
	}
	return -1;
}

int main(){
	while(cin >> p >> n){
		cout << solve() << endl;
	}
	return 0 ;
}