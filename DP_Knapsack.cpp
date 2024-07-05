#include <stdio.h>

int table[100][100] = {0};

int getMax(int a, int b){
	return a > b? a : b;
}

int knapsackTabu(int *w, int *v, int size, int capacity){	
	for(int i=0; i<capacity; i++){
		table[0][i] = 0;
		table[i][0] = 0;
	}

	for(int i=1;i<=size;i++){
		for(int c=1; c<=capacity; c++){
			if(c < w[i]){
				table[i][c] = table[i-1][c];
			}else{
				table[i][c] = getMax(table[i-1][c], table[i-1][c - w[i-1]] + v[i-1]);
			}
		}
	}	
	
	
	return table[size][capacity];	
}

int knapsackMemoi(int *w, int *v, int size, int capacity){
	if(size <= 0 || capacity <= 0) return 0;

	if(table[size][capacity] != 0) return table[size][capacity];
	
	if(capacity < w[size-1]) {
		return table[size][capacity] =  knapsackMemoi(w, v, size - 1, capacity);
	}

	return table[size][capacity] = getMax(
	knapsackMemoi(w, v, size - 1, capacity),
	knapsackMemoi(w, v, size - 1, capacity - w[size-1]) + v[size-1]
	);	
}

void viewTable(int size, int target){
	printf("Table\n");
	printf("==========\n");
	for(int i=0; i<=size; i++){
		for(int j=0; j<=target;j++){
			printf("%d ", table[i][j]);
		}
		puts("");
	}
}

int main(){
	int w[4] = {2, 3, 6, 7};
	int v[4] = {3, 5, 4, 11};
	int size = sizeof(w) / sizeof(w[0]);
	int capacity = 15;	
	
	int result = knapsackMemoi(w, v, size, capacity);
	printf("result : %d\n", result);
	viewTable(size, capacity);
	
	return 0;
}
