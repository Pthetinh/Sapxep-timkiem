#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sapxep(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				swap(&a[i], &a[j]);
			}
		}
		printf("Buoc%d: ", i + 1);
		for(int i = 0; i < n; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sapxep(a, n);
	return 0;
}
