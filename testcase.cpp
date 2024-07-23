#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Doan_Thang{
	int fi;
	int se;
}; 

typedef struct Doan_Thang dt;

int cmp(const void *a, const void *b){
	dt *x = (dt*) a;
	dt *y = (dt*) b;
	return x->se - y->se;
}

dt a[100000];


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i].fi, &a[i].se);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	int cnt = 0;
	int end = 0; 
	for(int i = 0; i < n; i++){
		if(a[i].fi >= end){
			cnt++;
			end = a[i].se;
		} 
	}
	int res = n - cnt;
	printf("%d", res);
	return 0;
} 


