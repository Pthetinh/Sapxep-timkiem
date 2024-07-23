#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#define N 100
#define L 2


int menu();

//Nhap cong thuc ham 
void function_f(int type);
//Tinh gia tri F(x)
float f_x( int type, float x);
//Them chuc nang cua bang
int table_f(int type, float min, float max, float step, float arr[L][N]);
//Hien thi bang gia tri ham
void output(float arr[L][N], int n);
//Kiem tra xem gia tri nao lon hon X, Tra ve dia chi cua gia tri do
int check(float arr[L][N], int n, float x);
// Tinh gia tri ham so tai diem x: F = F' + ((F" - F') * (x - x')) / (x" - x')  (Cong thuc noi suy tuyen tinh)
float formula(float arr_in[L][N], float X_k, int add);
//Them mot phan tu X_k vao bang gia tri 
void add_element_X(float arr[L][N], int n, int add, float X_k, float F_k);

float* a, * b, * c, * d;
int main()
{
	setlocale(LC_ALL, " ");

	int temp;
	do
	{
		int  n ,type,add;
		float X_k, F_k, min, max, step;
		float arr[L][N];

		type = menu();
		function_f(type);
		printf("Nhap pham vi [min,max] ");
		printf("\nNhap min = ");
		scanf("%f", &min);
		printf("Nhap max = ");
		scanf("%f", &max);
		printf("Nhap step = ");
		scanf("%f", &step);


		n=table_f(type, min, max, step, arr);
		output(arr, n );

		printf("Nhap X_k= ");
		scanf("%f", &X_k);
		add = check(arr, n, X_k);
		F_k=formula(arr,X_k,add);
		add_element_X(arr, n, add, X_k, F_k);
		printf("\nKet qua: \n");
		output(arr, n+1);

		printf("\nNhap <<0>> de thoat hoac nhap <<1>> de tinh toan lai: ");
		scanf("%d", &temp);
		printf("\n-------------------------------------------------------------------------------");
	} while (temp == 1);
	return 0;
}




int menu()
{
	int type;
	printf("\n\t1 - Ham phan so: (Ax+B)/(Cx+D)\n");
	printf("\t2 - Phuong trinh bac hai: Ax^2 + Bx + C\n");
	printf("\t3 - Phuong trinh bac nhat : Ax + B\n");
	printf("\t4 - Ham logarit: A*log(X)\n");
	printf("\t5 - Ham mu: A^x\n");
	printf("Chon ham ban muon: ");
	scanf("%d", &type);
	return type;
}


//Nhap cong thuc ham 
float i, j, k, l;
void function_f(int type)
{
	switch (type)
	{
		case 1:
			printf("Nhap A= ");
			scanf("%f", &i);
			a = &i;
			printf("Nhap B= ");
			scanf("%f", &j);
			b = &j;
			printf("Nhap C= ");
			scanf("%f", &k);
			c = &k;
			printf("Nhap D= ");
			scanf("%f", &l);
			d = &l;
			break;
		case 2:
			printf("Nhap A= ");
			scanf("%f", &i);
			a = &i;
			printf("Nhap B= ");
			scanf("%f", &j);
			b = &j;
			printf("Nhap C= ");
			scanf("%f", &k);
			c = &k;
			break;
		case 3:
			printf("Nhap A= ");
			scanf("%f", &i);
			a = &i;
			printf("Nhap B= ");
			scanf("%f", &j);
			b = &j;
			break;
		case 4:
			printf("Nhap A= ");
			scanf("%f", &i);
			a = &i;
			break;
		case 5:
			printf("Nhap A= ");
			scanf("%f", &i);
			a = &i;
	}
}


//Tinh gia tri F(x)
float f_x(int type, float x)
{
	switch (type)
	{
		case 1:
			return (*a * x + *b) / (*c * x + *d);
		case 2:
			return (*a * x * x + *b * x + *c) ;
		case 3:
			return *a * x + *b;
		case 4:
			return *a * (float)log(x);
		case 5:
			return (float)pow(*a, x);
	};
};


////Hien thi bang gia tri ham
int table_f(int type, float min, float max, float step, float arr[L][N])
{
	int j = 0;
	for (float i = min; i < max; i += step) 
	{
		arr[0][j] = i;
		arr[1][j] = f_x(type, arr[0][j]);
		j++;
	}
	arr[0][j] = max;
	arr[1][j] = f_x( type, arr[0][j]);
	return j + 1;
}


//In ra gia tri bang
void output(float arr[L][N], int n){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			printf("%.2lf\t\t", a[i][j]);
		}
		printf("\n");
	}
}
//Kiem tra xem gia tri nao lon hon X, Tra ve dia chi cua gia tri do
int check(float arr[L][N], int n, float x){
	int i;
	for(i = 0; i < n; i++){
		if(x < arr[0][i]) break;
	}
	return i;
}

// Tinh gia tri ham so tai diem x: F = F' + ((F" - F') * (x - x')) / (x" - x')  (Cong thuc noi suy tuyen tinh)
float formula(float arr_in[L][N], float X_k, int add){
	float T1 = arr_in[1][add] - arr_in[1][add - 1]; 	//F" - F'
 	float T2 = X_k - arr_in[0][add - 1];			//x - x'
 	float T2 = X_k - arr_in[0][add - 1];		//x" - x'
 	float T4 = arr_in[1][add - 1];				//F'
	float F = T4 + (T1 * T2) / T3;			//F
	return F;
}

//Them mot phan tu X_k vao bang gia tri 

void add_element_X(float arr[L][N], int n, int add, float X_k, float F_k){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= add; j--){
			arr[i][j + 1] = arr[i][j];
		}
	}
	arr[0][add] = X_k;
	arr[1][add] = F_k;
}

