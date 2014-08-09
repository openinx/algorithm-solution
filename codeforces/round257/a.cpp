#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
	int n , m , i, val[101] , k; 
	while( cin >> n >> m ){
		for(i = 1 ; i <= n ; ++ i)
			cin >> val[i];
		queue<int> q ;
		for(i = 1 ; i <= n; ++ i)
			q.push(i);
		while(!q.empty()){
			k = q.front(); q.pop();
			val[k] -= m; 
			if(val[k] > 0 )
				q.push(k);
		}
		cout << k << endl;
	}
	return 0 ;
}