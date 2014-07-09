#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<list>
#include<algorithm>

using namespace std; 

typedef pair<int,int> PII;
typedef list< pair<int,int> >::iterator list_it;
typedef map<int, list_it >::iterator map_it;

class LRUCache{
public:
    LRUCache(int capacity) {
    	size = capacity; 
    }
    
    int get(int key ) {
    	map_it mit = cache.find(key);
    	if(mit == cache.end())
    		return -1;
    	list_it lit = mit->second ;
    	PII pii(lit->first, lit->second);
    	kvs.erase(lit);
    	kvs.push_back(pii);
    	cache[pii.first] = --kvs.end();
    	return pii.second;
    }
        
    void set(int key, int value) {
    	map_it mit = cache.find(key);
    	PII elem(key, value);
    	if(mit == cache.end()){
    		if(cache.size() >= size){
    			cache.erase(kvs.front().first);
    			kvs.pop_front();
    		}    	
    		kvs.push_back(elem); 
    		cache[key] = --kvs.end();
    	}else{
    		list_it lit = mit->second;
    		kvs.erase(lit);
    		kvs.push_back(elem);
    		cache[key] = --kvs.end();
    	}
    }

private:
	int size ;
	list<PII> kvs ; 
	map<int, list_it> cache ;
};

int main(){
	LRUCache lru(5)  ;
	for(int i = 0 ; i < 10 ; ++ i){
		lru.set(i, i);
	}
	for(int i = 0 ; i < 10 ; ++ i)
		cout << "####: " << i << " #### " << lru.get(i) << endl ;
	return 0 ;
}