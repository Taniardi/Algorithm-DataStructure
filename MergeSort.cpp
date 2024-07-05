#include <stdio.h>

void merge(int *arr, int l, int m, int r){
	int size = r - l + 1;
	
	int newArr[size];
	int leftCursor = l, rightCursor = m+1, indexNewArr = 0;
	
	while(leftCursor <= m && rightCursor <= r){
		if(arr[leftCursor] < arr[rightCursor]){
			newArr[indexNewArr++] = arr[leftCursor++];
		}else {
			newArr[indexNewArr++] = arr[rightCursor++];
		}
	}
	
	while(rightCursor <= r){
		newArr[indexNewArr++] = arr[rightCursor++];
	}
	
	while(leftCursor <= m){
		newArr[indexNewArr++] = arr[leftCursor++];
	}
	
	for(int i=0; i<size; i++){
		arr[i+l] = newArr[i];
	}
}

void mergeSort(int *arr, int l, int r){
	if(r <= l) return;
	
	int m = (r - l) / 2 + l;
	
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);	
}


int main(){
	int arr[10] = { 8, 9, 11, 10, 2, 1, 3, 7, 5, 4};
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1);
	
	for(int i=0; i < size; i++){
		printf("%d ", arr[i]);
	} 
	
	return 0;
}
