#include <stdio.h>
#include <math.h>

typedef long long ll;
const int mod = 10 ^ 9 + 7;

int nt(int n){
	if(n < 2) return 0;
	for(int i = 2; i < n; i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int min = 1e9, max = -1e9;
	int cnt1;
	for(int i = 0; i < n; i++){
		if(a[i] >= max){
			max = a[i];
			cnt1 = i;
		}
	}
	printf("%d %d\n", max, cnt1);
	int cnt2;
	for(int i = 0; i < n; i++){
		if(a[i] <= min){
			min = a[i];
			cnt2 = i;
		}
	}
	printf("%d %d\n", min, cnt2);
	int cnt3 = 0;
	for(int i = 0; i < n; i++){
		if(nt(a[i])) 
			++cnt3;
	}
	printf("%d\n", cnt3);
	ll maxtich = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(1ll * a[i] * a[j] >= maxtich)
				maxtich = a[i] * a[j];
		}
	}
	printf("%lld\n", maxtich);
	ll tich = 1;
	for(int i = 0; i < n; i++){
		tich *= (1ll * a[i] % mod);
	}
	printf("%lld\n", tich);
	return 0;
}
