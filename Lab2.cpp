#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100
#define L 2

int menu();
//Nhap cong thuc ham so
void function_f(int type);
//Tinh gia tri f_X
float f_x(int type, float x);
//Them bang gia tri ham so
int table_f(int type, float min, float max, float step, float arr[L][N]);
//In bang gia tri cua ham so ra man hinh
void out_put(float arr[L][N], int n);
//Kiem tra X nam giua hai diem nao tra ve gia tri lon hon X
int check(float arr[L][N], int n, float x);
//Tinh gia tri ham so tai diem X:Cong thuc noi suy tuyen tinh
float formula(float arr_in[L][N], float X_k, int add);
// Thêm phan tu X_k vào bang giá tri hàm so
void add_element_X(float arr[L][N], int n, int add, float X_k, float F_k);

float *a, *b, *c, *d;

int main(){
	int temp;
	do{
		int n, type, add;
		float X_k, F_k, min, max, step;
		float arr[L][N];
		
		type = menu();
		function_f(type);
		printf("Nhap khoang [min, max]: ");
        printf("\nNhap min = ");
        scanf("%f", &min);
        printf("Nhap max = ");
        scanf("%f", &max);
        printf("Nhap step = ");
        scanf("%f", &step);
        
        
        n = table_f(type, min, max, step, arr);
        out_put(arr, n);

        printf("Nhap X_k= ");
        scanf("%f", &X_k);
        add = check(arr, n, X_k);
        F_k = formula(arr, X_k, add);
        add_element_X(arr, n, add, X_k, F_k);
        printf("\nKet qua: \n");
        out_put(arr, n + 1);
		
		printf("\n Nhap '0' de thoat hoac nhap 1 de tinh lai: ");
		scanf("%d", &temp);
	}
	while(temp == 1);
}
int menu(){
	int type;
	printf("\n\t1 - Ham phan so: (Ax + B)(Cx + D)\n");
	printf("\t2 - Phuong trinh bac hai: Ax^2 + Bx + C \n");
	printf("\t3 - Phuong trinh bac nhat: Ax + B\n");
	printf("\t4 - Ham logarit: A*log(x)\n");
	printf("\t5 - Ham mu : A^x\n");
	printf("CHON HAM BAN MUON:");
	scanf("%d", &type);
	return type;
}

float i, j, k, l;
//Nhap cong thuc ham
void function_f(int type){
	switch(type){
		case 1:
			printf("Nhap A = ");
			scanf("%f",&i);
			a = &i;
			printf("Nhap B = ");
			scanf("%f", &j);
			b = &j;
			printf("Nhap C = ");
			scanf("%f", &k);
			c = &k;
			printf("Nhap D = ");
			scanf("%f", &l);
			d = &l;
			break;
		case 2:
			printf("Nhap A = ");
			scanf("%f",&i);
			a = &i;
			printf("Nhap B = ");
			scanf("%f", &j);
			b = &j;
			printf("Nhap C = ");
			scanf("%f", &k);
			c = &k;
			break;
		case 3:
			printf("Nhap A = ");
			scanf("%f",&i);
			a = &i;
			printf("Nhap B = ");
			scanf("%f", &j);
			b = &j;
			break;
		case 4:
			printf("Nhap A = ");
			scanf("%f",&i);
			a = &i;
			break;
		case 5:
			printf("Nhap A = ");
			scanf("%f",&i);
			a = &i;
			break;	
	}
}
//Tinh gia tri F_x

float f_x(int type, float x){
	switch(type){
		case 1:
			return (*a * x + *b) / (*c * x + *d);
			break;
		case 2:
			return (*a * x * x + *b * x + *c);
			break;
		case 3:
			return (*a * x + *b);
			break;
		case 4:
			return (*a * (float)log(x));
			break;
		case 5:
			return ((float) pow(*a, x));
			break;
	}
}

//Them bang gia tri ham so
int table_f(int type, float min, float max, float step, float arr[L][N]){
	int j = 0;
	for(float i = min; i < max; i += step){
		arr[0][j] = i;
		arr[1][j] = f_x(type, i);
		++j;
	}
	arr[0][j] = max;
	arr[1][j] = f_x(type, arr[0][j]);
	return j + 1;
}

//In bang gia tri cua ham so ra man hinh
void out_put(float arr[L][N], int n){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			printf("%.2lf\t\t", arr[i][j]);
		}
		printf("\n");
	}
}
//Kiem tra X nam giua hai diem nao tra ve gia tri lon hon X
int check(float arr[L][N], int n, float x){
	for(int i = 0; i < n; i++){
		if(arr[0][i] > x){
			break;
		}
	}
	return i;
}
//Tinh gia tri ham so tai diem X:Cong thuc noi suy tuyen tinh
float formula(float arr_in[L][N], float X_k, int add){
	float T1 = arr_in[1][add] - arr_in[1][add - 1];
	float T2 = X_k - arr_in[0][add - 1];
	float T3 = arr_in[0][add] - arr_in[0][add - 1];
	float T4 = arr_in[1][add - 1];
	float F = T4 + (T1 * T2) / T3;
	return F;
}
// Them phan tu X_k vao bang gia tri ham so
void add_element_X(float arr[L][N], int n, int add, float X_k, float F_k){
	for(int i = 0; i < 2; i++){
		for(int j = n; j > add; j--){
			arr[i][j + 1] = arr[i][j];
		}
	}
	arr[0][add] = X_k;
	arr[1][add] = F_k;
}


