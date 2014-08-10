#include <iostream>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


class MaxHeap{
public:
	void push(int x){
		arr.push_back(x);
		int i = arr.size() - 1, j; 
		while(i > 0){
			j = (i - 1) / 2 ;
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
			else
				break;
			i = j;
		}
	}
	int pop(){
		int i, j, val = arr[0];
		arr[0] = arr.back();
		arr.pop_back();
		i = 0 ;  j = 2 * i + 1;
		while(1){
			j = 2 * i + 1 ;
			if(j + 1< arr.size() && arr[j] < arr[j+1])
				++ j;
			if(j < arr.size() && arr[i] < arr[j])
				swap(arr[i], arr[j]);
			else 
				break;
			i = j;
		}
		return val;
	}
	bool empty(){
		return arr.size() == 0;
	}
private:
	vector<int> arr;
};


/*************************test***********************************************/

#define MAX_SIZE 2000000

int main(){
	MaxHeap heap;
	int x[MAX_SIZE], val, i, start_t , token;
	start_t = clock();
	for(i = 0 ; i < MAX_SIZE; ++ i){
		val = rand();
		heap.push(val);
		x[i] = val;
	}
	sort(x, x + sizeof(x)/sizeof(int), std::greater<int>());
	i = 0;
	while(!heap.empty()){
		val = heap.pop();
		assert(i < MAX_SIZE);
		assert(x[i++] == val);
	}
	token = clock() - start_t;
	printf("Test OK , push & pop %d integers, take %f ms\n",
		   MAX_SIZE, (float)token / CLOCKS_PER_SEC);
	return 0;
}