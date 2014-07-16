#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool isPrime(int x){
	for(int i = 2 ; i * i <= x ; ++ i)
		if(x % i == 0 ) return false;
	return true;
}

void initPrime(vector<int> &primes, int n){
	int k = 1 ; 
	for(int i = 0 ; i < n ; ++ i){
		while(!isPrime(++k));
		primes.push_back(k);
	}
}

class HashMap{
public:

	HashMap(){
		initPrime(primes, 26);
		slots = vector< vector<string> >(1<<20);
		size = 0 ;
	}

	int hash(string s){
		int res = 1 ;
		for(int i = 0 ; i < s.size(); ++ i)
			res = res * ( primes[ s[i] - 'a' ] )  % mod;
		return res;
	}

	bool equal(string a, string b){
		int ax[26] = {0}, bx[26] = {0};
		for(int i = 0 ; i < a.size(); ++ i) ax[ a[i] - 'a' ] ++ ;
		for(int i = 0 ; i < b.size(); ++ i) bx[ b[i] - 'a' ] ++ ;
		for(int i = 0 ; i < 26 ; ++ i)
			if(ax[i] != bx[i]) 
				return false;
		return true;
	}

	bool find(string s){
		int hashVal = hash(s); 
		for(int i = 0 ; i < slots[hashVal].size(); ++ i)
			if(equal(slots[hashVal][i], s))
				return true;
		return false;
	}

	bool insert(string s){
		int hashVal = hash(s); 
		for(int i = 0 ; i < slots[hashVal].size(); ++ i)
			if(equal(slots[hashVal][i],s))
				return false;
		++ size;
		slots[hashVal].push_back(s);
		return true;
	}

	int length(){
		return size;
	}

private:
	int size;
	static const int MAX_SIZE = 1<<20;
	static const int mod = (1<<20) - 1;
	vector< vector<string> > slots;
	vector<int> primes;
};

int main(){
	HashMap hashMap;
	hashMap.insert("aaaaaab");
	hashMap.insert("aaaaaab");
	cout << hashMap.length() << endl;
	cout << hashMap.find("aaaaaba") << endl;
	return 0;
}