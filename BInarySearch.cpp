#include <stdio.h>

int binarySearch(int *arr, int size, int target){
	int leftIndex = 0;
	int rightIndex = size-1;
	int mid;
	
	while(leftIndex <= rightIndex){
		mid = (rightIndex - leftIndex) / 2	+ leftIndex;
		if(arr[mid] == target){
			return mid;
		}
		if(arr[mid] < target){
			leftIndex = mid + 1;
		}else{
			rightIndex = mid - 1;
		}
	}
	
	return -1;
}

int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int target = 6;
	int index = binarySearch(arr, size, target);
	printf("Target : %d\n", target);
	printf("Index : %d\n", index);
	
	return 0;
}
