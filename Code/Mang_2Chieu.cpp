#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 100


void tao_Mang2C(int a[][MAXSIZE], int &n, int &m)
{
	printf("Nhap so dong:");
	scanf("%d", &n);
	printf("Nhap so cot:");
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j]=rand()%100;
		}
	}
}

void xuat_Mang2C(int a[][MAXSIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// tinh tong cac phan tu co chu so dau la chu so le

int Tach(int n)
{
	while (n/10 != 0)
	{
		n=n/10;
	}
	return n;
}

void tinhTong(int a[][MAXSIZE], int n, int m)
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Tach(a[i][j])%2 != 0)
			{
				tong+=a[i][j];
			}
		}
	}

	printf("Ket Qua: %d", tong);
}


// Hàm kiểm tra số hoàn thiện
int isPerfectNumber(int num) {
    if (num < 2) return 0;
    int sum = 1; // 1 luôn là ước số của mọi số nguyên dương
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void listPerfectNumbersInMatrix(int matrix[100][100], int rows, int cols) {
    printf("Cac so hoan thien trong ma tran la: ");
    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPerfectNumber(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong co so hoan thien nao trong ma tran.");
    }
    printf("\n");
}

// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
void sumElementsGreaterThanNextAbs(int matrix[100][100], int rows, int cols) {
    int sum = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Kiểm tra phần tử liền sau trong cùng hàng
            if (j < cols - 1 && matrix[i][j] > abs(matrix[i][j + 1])) {
                sum += matrix[i][j];
            }
            // Kiểm tra phần tử liền sau trong cùng cột
            if (i < rows - 1 && matrix[i][j] > abs(matrix[i + 1][j])) {
                sum += matrix[i][j];
            }
        }
    }
    
	printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no la: %d", sum);
}

int sumRow(int matrix[100][100], int cols, int k) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += matrix[k][j];
    }
	return sum;
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n, m;
	tao_Mang2C(a,n,m);
	xuat_Mang2C(a,n,m);
	printf("\n---------------------------\n");
	tinhTong(a,n,m);
	printf("\n---------------------------\n");
	listPerfectNumbersInMatrix(a,n,m);
	printf("\n---------------------------\n");
	sumElementsGreaterThanNextAbs(a,n,m);
	printf("\n---------------------------\n");
	int k;
	 // Nhập số dòng k
    printf("Nhap so dong k: ");
    scanf("%d", &k);

    // Kiểm tra nếu dòng k hợp lệ
	if (k >= 0 && k < n) {
        // Tính tổng giá trị trên dòng k của ma trận
		int result = sumRow(a, m, k);
        // In kết quả
        printf("Tong gia tri tren dong %d cua ma tran: %d\n", k, result);
    } else {
        printf("Dong k khong hop le.\n");
    }
	getch();
	return 0;
}