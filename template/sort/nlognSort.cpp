#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;

void mergeSort(int *x, int *temp, int left, int right){
	if(left >= right) return;
	int mid = (left + right) >> 1;
	mergeSort(x, temp, left, mid);
	mergeSort(x, temp, mid + 1, right);
	int i = left, j = mid + 1, k = left;
	while(i <= mid && j <= right){
		if(x[i] < x[j])
			temp[k++] = x[i++];
		else
			temp[k++] = x[j++];
	}
	while(i <= mid) temp[k++] = x[i++];
	while(j <= right) temp[k++] = x[j++];
	for(i = left; i <= right; ++ i)
		x[i] = temp[i];
}

void quickSort(int *x, int left, int right){
	if(left >= right) return;
	int mid = x[(left + right) >> 1], i, j;
	i = left; j = right;
	do{
		while(x[i] < mid) ++ i;
		while(mid < x[j]) -- j;
		if(i <= j){
			swap(x[i++], x[j--]);
		}
	}while(i<=j);
	if(i < right) quickSort(x, i, right);
	if(left < j ) quickSort(x, left, j);
}

/*********************************test*****************************************/
#define MAX_SIZE 600000

int main(){
	int start_t, token;
	int x[MAX_SIZE], y[MAX_SIZE], temp[MAX_SIZE];
	/* initialize random seed: */
	srand(time(NULL));
	for(int i = 0 ; i < MAX_SIZE; ++ i)
		y[i] = x[i] = rand();
	// MergeSort
	start_t = clock();
	mergeSort(x, temp, 0, MAX_SIZE-1);
	token = clock() - start_t ;
	printf("Test OK, MergeSort %d integer, token %f seconds\n",
		   MAX_SIZE, (float)token/CLOCKS_PER_SEC);
	// QuickSort
	start_t = clock();
	quickSort(y, 0, MAX_SIZE-1);
	token = clock() - start_t;
	printf("Test OK, QuickSort %d integer, token %f seconds\n",
		   MAX_SIZE, (float)token/ CLOCKS_PER_SEC);
	// Compare all elements. 
	for(int i = 0 ; i < MAX_SIZE; ++ i)
		assert(x[i] == y[i]);
	return 0;
}