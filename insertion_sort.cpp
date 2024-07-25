#include<stdio.h>
#include<math.h>

void insertion_sort(int a[], int n){
	printf("Buoc 0:%d\n", a[0]);
	for(int i = 1; i < n; i++){
		int value = a[i];
		int pos = i - 1;
		while(pos >= 0 && value < a[pos]){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = value;
		printf("Buoc %d:", i);
		for(int j = 0; j <= i; j++){
			printf("%d ", a[j]);
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
	insertion_sort(a, n);
	return 0;
}
