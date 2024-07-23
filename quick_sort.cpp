#include<stdio.h>
#include<math.h>

int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++){
		if(a[j] <= pivot){
			++i;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	++i;
	int tmp = a[i];
	a[i] = a[r];
	a[r] = tmp;
	printf("Phan hoach tu chi so %d den chi so %d:", l , r);
	for(int i = l; i <= r; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return i;
}
void quick_sort(int a[], int l, int r){
	if(l < r){
		int i = partition(a,l,r);
		quick_sort(a, l, i - 1);
		quick_sort(a, i + 1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	quick_sort(a, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
