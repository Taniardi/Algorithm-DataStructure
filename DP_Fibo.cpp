#include <stdio.h>

int table[100] = {0};

int getFiboMemoi(int num){
	if(num <= 1) return num;	
	
	if(table[num] != 0){
		return table[num];
	}
	
	return table[num] = getFiboMemoi(num - 1) + getFiboMemoi(num - 2);
}
int temp = 2;
int getFiboTabu(int num){
	if(table[num] != 0) return table[num];
	table[0] = 0;
	table[1] = 1;
	
	for(int i=temp; i<=num; i++){
		table[i] = table[i-1] + table[i-2];
	}
	
	temp = num;
	return table[num];
}

int main(){
	int num = 6;
	printf("%d\n", getFiboMemoi(num));
	num = 7;
	printf("%d\n", getFiboTabu(num));
	
}
