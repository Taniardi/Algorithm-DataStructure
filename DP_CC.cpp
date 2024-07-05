#include <stdio.h>

int table[100][100] = {0};
int ccTabu(int *coin, int size, int target){
	for(int i=0; i<=target; i++){
		table[0][i] = 0;
		table[i][0] = 1;
	}	
	
	for(int c=1; c<=size; c++){
		for(int t=1; t<=target; t++){
			if(t < coin[c-1]){
				table[c][t] = table[c-1][t];
			}else{
				table[c][t] = table[c-1][t] + table[c][t - coin[c-1]];
			}
			
		}
	}
	
	return table[size][target];
}

int ccMemoi(int *arr, int size, int target){
	if(target == 0) return 1;
	if(size == 0 || target < 0) return 0;
	
	if(table[size][target] != 0) return table[size][target];
	
	return table[size][target] = ccMemoi(arr, size - 1, target) + ccMemoi(arr, size, target - arr[size-1]);
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
	int coin[3] = {1, 3, 5};
	int size = sizeof(coin) / sizeof(coin[0]);
	int target = 5;
	
	int totalWays = ccMemoi(coin, size, target);
	printf("%d\n", totalWays);
	
	viewTable(size, target);
	
	return 0;
}
