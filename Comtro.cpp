#include<stdio.h>
#include<stdlib.h>

void nhandoi(int *n){
	*n *= 2;
}

void hoanvi(int *a, int * b){
	int tmp = *a;
		*a = *b;
		*b = tmp;
}


int main(){
	int n = 1000000;
	long long *a = (long long *) malloc(n * sizeof(int));
	for(int i = 0; i < 5;i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	free(a);
	return 0; 
} 
