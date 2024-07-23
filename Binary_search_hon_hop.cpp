#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ham1(int a[], int n, int x){
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(x == a[mid]){
			res = mid;
			r = mid - 1;
		}
		else if(x < a[mid]){
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}

int ham2(int a[], int n, int x){
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(x == a[mid]){
			res = mid;
			l = mid + 1;
		}
		else if(x < a[mid]){
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}
int ham3(int a[], int n, int x){
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(a[mid] >= x){
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return res;
}

int ham4(int a[], int n, int x){
	int res = -1;
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(a[mid] > x){
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return res;
}
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d\n", ham1(a, n, x));
	printf("%d\n", ham2(a, n, x));
	printf("%d\n", ham3(a, n, x));
	printf("%d\n", ham4(a, n, x));
	if(ham1(a, n, x) == -1){
		printf("0");
	}
	else printf("%d\n", ham2(a, n, x) - ham1(a, n, x) + 1);
	return 0;
}
