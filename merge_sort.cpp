#include<stdio.h>
#include<math.h>

typedef long long ll;

int mark[1000001];

void merge(int a[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int x[n1], y[n2];
	for(int i = 0; i < n1; i++){
		x[i] = a[l + i];
	}
	for(int i = 0; i < n2; i++){
		y[i] = a[m + i + 1];
	}
	int i = 0, j = 0, cnt = l;
	while(i < n1 && j < n2){
		if(x[i] <= y[j]){
			a[cnt++] = x[i++];
		}
		else{
			a[cnt++] = y[j++];
		}
	}
	while(i < n1) a[cnt++] = x[i++];
	while(j < n2) a[cnt++] = y[j++];
}

void merge_sort(int a[], int l, int r){
	int m = (l + r) / 2;
	if(l < r){
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	merge_sort(a, 0, n - 1);
	merge_sort(b, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d %d ", a[i], b[n - i - 1]);
	}
	return 0;
} 
