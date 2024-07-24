#include<stdio.h>
#include<math.h>

void selection_sort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int min_index = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[min_index]){
				min_index = j;
			}
		}
		int tmp = a[i];
		a[i] = a[min_index];
		a[min_index] = tmp;
		printf("Buoc %d:", i + 1);
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
	selection_sort(a, n);
	return 0;
} 
